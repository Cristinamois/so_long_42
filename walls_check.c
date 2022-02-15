/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:10:38 by cmois             #+#    #+#             */
/*   Updated: 2021/11/25 15:22:38 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_up(t_all *all, char **str)
{
	if (str[all->size.player_pos_height - 1]
		[all->size.player_pos_width] == 'E'
		&& all->counter.collectible > 0)
		return (0);
	if (str[all->size.player_pos_height - 1]
		[all->size.player_pos_width] == '1')
		return (0);
	if (str[all->size.player_pos_height - 1]
		[all->size.player_pos_width] == 'E'
		&& all->counter.collectible <= 0)
	{
		moving_up(all);
		return (close_window(all));
	}
	return (1);
}

int	check_down(t_all *all, char **str)
{
	if (str[all->size.player_pos_height + 1]
		[all->size.player_pos_width] == 'E'
		&& all->counter.collectible > 0)
		return (0);
	if (str[all->size.player_pos_height + 1]
		[all->size.player_pos_width] == '1')
		return (0);
	if (str[all->size.player_pos_height + 1]
		[all->size.player_pos_width] == 'E'
		&& all->counter.collectible <= 0)
	{
		moving_down(all);
		return (close_window(all));
	}
	return (1);
}

int	check_left(t_all *all, char **str)
{
	if (str[all->size.player_pos_height]
		[all->size.player_pos_width - 1] == 'E'
		&& all->counter.collectible > 0)
		return (0);
	if (str[all->size.player_pos_height]
		[all->size.player_pos_width - 1] == '1')
		return (0);
	if (str[all->size.player_pos_height]
		[all->size.player_pos_width - 1] == 'E'
		&& all->counter.collectible <= 0)
	{
		moving_left(all);
		return (close_window(all));
	}
	return (1);
}

int	check_right(t_all *all, char **str)
{
	if (str[all->size.player_pos_height]
		[all->size.player_pos_width + 1] == 'E'
		&& all->counter.collectible > 0)
		return (0);
	if (str[all->size.player_pos_height]
		[all->size.player_pos_width + 1] == '1')
		return (0);
	if (str[all->size.player_pos_height]
		[all->size.player_pos_width + 1] == 'E'
		&& all->counter.collectible <= 0)
	{
		moving_right(all);
		return (close_window(all));
	}
	return (1);
}

int	checking_for_walls(t_all *all, int number_ref)
{
	if (number_ref == 8)
		if (check_up(all, all->screen.map) == 0)
			return (0);
	if (number_ref == 5)
		if (check_down(all, all->screen.map) == 0)
			return (0);
	if (number_ref == 4)
		if (check_left(all, all->screen.map) == 0)
			return (0);
	if (number_ref == 6)
		if (check_right(all, all->screen.map) == 0)
			return (0);
	return (1);
}
