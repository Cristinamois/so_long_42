/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 09:14:10 by cmois             #+#    #+#             */
/*   Updated: 2021/11/21 16:45:08 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	n_in_buff(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

void	clean(char *str, size_t j)
{
	size_t		i;

	i = 0;
	if (!str[j])
	{
		ft_bzero_gnl(str);
		return ;
	}
	++j;
	while (str[j])
		str[i++] = str[j++];
	ft_bzero_gnl(str + i);
}

void	ft_safe(size_t j, char *buffer)
{
	j = ft_strlenn(buffer);
	clean(buffer, j);
}

void	init_vars(int *i, size_t *j, char **line)
{
	*i = 1;
	*j = 0;
	*line = NULL;
}

int	get_next_line(int fd, char **line)
{
	int			i;
	size_t		j;
	static char	buffer[BUFFER_SIZE + 1];

	if (!line || BUFFER_SIZE < 1 || read(fd, buffer, 0) == -1)
		return (ERROR);
	init_vars(&i, &j, line);
	*line = ft_strjoin_gnl(*line, buffer);
	while (i > 0 && !n_in_buff(buffer))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i)
			buffer[i] = 0;
		if (i > 0)
			*line = ft_strjoin_gnl(*line, buffer);
		if (i == 0)
		{
			ft_safe(j, buffer);
			return (0);
		}
		if (i == -1)
			return (ERROR);
	}
	ft_safe(j, buffer);
	return (1);
}
