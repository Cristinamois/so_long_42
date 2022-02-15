/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 09:14:38 by cmois             #+#    #+#             */
/*   Updated: 2021/11/21 16:45:01 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlenn(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s2)
		return ((char *)ERROR);
	i = 0;
	j = ft_strlen_gnl(s1) + ft_strlenn(s2);
	str = (char *)malloc(sizeof(char) * (j + 1));
	if (!str)
		return ((char *)ERROR);
	j = 0;
	if (s1)
	{
		while (s1[i])
			str[j++] = s1[i++];
	}
	i = 0;
	while (s2[i] && s2[i] != '\n')
		str[j++] = s2[i++];
	str[j] = 0;
	free(s1);
	return (str);
}

void	ft_bzero_gnl(char *str)
{
	while (*str)
		*str++ = 0;
}
