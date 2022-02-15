/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_next_bloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:44:01 by cmois             #+#    #+#             */
/*   Updated: 2021/11/25 15:51:05 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/*
   6 == right;
   8 == up;
   4 == left;
   5 == down;
 */

int	is_next_bloc_a_collectible(t_all *all, int number_ref)
{
	if (number_ref == 8)
	{
		if (all->screen.map[all->size.player_pos_height - 1]
			[all->size.player_pos_width] == 'C')
		{
			all->screen.map[all->size.player_pos_height - 1]
			[all->size.player_pos_width] = '0';
			return (1);
		}
	}
	if (number_ref == 4)
	{
		if (is_next_bloc_a_collectible_part_3(all, number_ref))
			return (1);
	}
	if (number_ref == 5 || number_ref == 6)
	{
		if (is_next_bloc_a_collectible_part_two(all, number_ref))
			return (1);
	}
	return (0);
}

void	right_moving_check(t_all *all, int number_ref)
{
	if (number_ref == 6)
	{
		if (is_next_bloc_a_collectible(all, number_ref))
		{
			all->counter.collectible--;
		}
		if (checking_for_walls(all, number_ref))
		{
			moving_right(all);
			all->counter.moves++;
		}
	}
}

void	left_moving_check(t_all *all, int number_ref)
{
	if (number_ref == 4)
	{
		if (is_next_bloc_a_collectible(all, number_ref))
			all->counter.collectible--;
		if (checking_for_walls(all, number_ref))
		{
			moving_left(all);
			all->counter.moves++;
		}
	}
}

void	up_moving_check(t_all *all, int number_ref)
{
	if (number_ref == 8)
	{
		if (is_next_bloc_a_collectible(all, number_ref))
			all->counter.collectible--;
		if (checking_for_walls(all, number_ref))
		{
			moving_up(all);
			all->counter.moves++;
		}
	}
}

void	down_moving_check(t_all *all, int number_ref)
{
	if (number_ref == 5)
	{
		if (is_next_bloc_a_collectible(all, number_ref))
			all->counter.collectible--;
		if (checking_for_walls(all, number_ref))
		{
			moving_down(all);
			all->counter.moves++;
		}
	}
}
