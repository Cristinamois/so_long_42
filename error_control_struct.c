/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:52:06 by cmois             #+#    #+#             */
/*   Updated: 2021/11/26 17:16:39 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	error_control_part_2(t_all *all)
{
	char	*tmp;

	tmp = ".xpm";
	if (all->counter.collectible >= 1 && all->counter.player == 1
		&& all->counter.exit == 1)
	{
		if (compare_extention(tmp, all->texture.wall)
			&& compare_extention(tmp, all->texture.floor)
			&& compare_extention(tmp, all->texture.player)
			&& compare_extention(tmp, all->texture.collectible)
			&& compare_extention(tmp, all->texture.exit)
			&& valid_map(all))
		{
			return (1);
		}
	}
	return (0);
}
