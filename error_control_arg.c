/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 10:11:41 by cmois             #+#    #+#             */
/*   Updated: 2021/11/26 17:19:02 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	does_map_exist(char *str, t_all *all)
{
	int	fd;

	(void)all;
	fd = open(str, O_RDONLY);
	if (fd != 0 && fd != -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

int	compare_extention(char *model, char *to_compare)
{
	int	len_to_compare;
	int	len_model;
	int	k;

	k = 0;
	len_model = ft_strlen(model);
	len_to_compare = ft_strlen(to_compare) - len_model;
	while (to_compare[len_to_compare])
	{
		if (to_compare[len_to_compare] != model[k])
			return (0);
		len_to_compare++;
		k++;
	}
	return (1);
}

int	is_it_dot_ber(char *str)
{
	char	*tmp;

	tmp = ".ber";
	if (compare_extention(tmp, str) == 1)
		return (1);
	return (0);
}

int	is_it_a_file(char *str)
{
	int	fd;

	fd = open(str, O_DIRECTORY);
	if (fd > 0)
		return (0);
	return (1);
}

int	error_control(char *str, t_all *all)
{
	if (is_it_dot_ber(str) == 1 && is_it_a_file(str) == 1
		&& does_map_exist(str, all) == 1)
		return (1);
	return (0);
}
