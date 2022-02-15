/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:18:43 by cmois             #+#    #+#             */
/*   Updated: 2021/11/26 17:38:05 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	is_it_a_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	walls_around(t_all *all)
{
	int	i;

	i = 0;
	while (all->screen.map[i])
	{
		if (i == 0 || i == (all->size.img_height - 1))
		{
			if (!is_it_a_wall(all->screen.map[i]))
				return (0);
			i++;
		}
		if (i > 0 && i < all->size.img_height)
		{
			if (all->screen.map[i][all->size.img_width - 1] != '1'
					|| all->screen.map[i][0] != '1')
				return (0);
			i++;
		}
	}
	return (1);
}

int	is_it_rectangular(t_all *all)
{
	int	i;
	int	state;
	int	j;

	state = 0;
	i = 0;
	while (all->screen.map[i])
	{
		j = 0;
		while (all->screen.map[i][j])
			j++;
		state = j;
		if (state != all->size.img_width)
			return (0);
		i++;
	}
	return (1);
}

int	texture_exists(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd > 0)
		return (1);
	return (0);
}

int	valid_map(t_all *all)
{
	if (is_it_rectangular(all) && walls_around(all)
		&& texture_exists(all->texture.wall)
		&& texture_exists(all->texture.floor)
		&& texture_exists(all->texture.collectible)
		&& texture_exists(all->texture.player)
		&& texture_exists(all->texture.exit))
		return (1);
	return (0);
}
