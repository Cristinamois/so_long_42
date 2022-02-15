/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_next_bloc_collectible_part_two.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:24:32 by cmois             #+#    #+#             */
/*   Updated: 2021/11/25 15:53:25 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	is_next_bloc_a_collectible_part_two(t_all *all, int number_ref)
{
	if (number_ref == 5)
	{
		if (all->screen.map[all->size.player_pos_height + 1]
			[all->size.player_pos_width] == 'C')
		{
			all->screen.map[all->size.player_pos_height + 1]
			[all->size.player_pos_width] = '0';
			return (1);
		}
	}
	if (number_ref == 6)
	{
		if (all->screen.map[all->size.player_pos_height]
			[all->size.player_pos_width + 1] == 'C')
		{
			all->screen.map[all->size.player_pos_height]
			[all->size.player_pos_width + 1] = '0';
			return (1);
		}
	}
	return (0);
}

int	is_next_bloc_a_collectible_part_3(t_all *all, int number_ref)
{
	if (number_ref == 4)
	{
		if (all->screen.map[all->size.player_pos_height]
			[all->size.player_pos_width - 1] == 'C')
		{
			all->screen.map[all->size.player_pos_height]
			[all->size.player_pos_width - 1] = '0';
			return (1);
		}
	}
	return (0);
}
