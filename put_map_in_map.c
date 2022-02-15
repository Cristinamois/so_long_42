/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map_in_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:35:44 by cmois             #+#    #+#             */
/*   Updated: 2021/11/25 15:43:30 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	apply_gnl(t_all *all, char *line, int fd)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		j = 1;
		all->screen.map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	if (j == 1)
	{
		all->screen.map[i] = ft_strdup(line);
		free(line);
		all->screen.map[i + 1] = NULL;
	}
	else
		exit(0);
}

void	give_value_to_map(t_all *all, char *arg)
{
	int		number_of_lines;
	char	*line;
	int		fd;

	fd = open(arg, O_RDONLY);
	line = NULL;
	number_of_lines = number_of_lines_height(all, arg);
	all->screen.map = (char **)malloc(sizeof(char *) * (number_of_lines + 1));
	if (!all->screen.map)
		exit (0);
	apply_gnl(all, line, fd);
	close(fd);
}
