/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_to_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:04:23 by cmois             #+#    #+#             */
/*   Updated: 2021/11/24 16:08:51 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/*
number_repere:
1 == wall
0 == floor
9 == player
3 == exit
4 == collectible
 */

void	put_the_image(t_all *all, t_screen screen)
{
	mlx_put_image_to_window(screen.mlx, screen.mlx_win, screen.img,
		all->size.pos_width, all->size.pos_height);
	if (all->size.pos_width != (all->size.img_width * 32))
		all->size.pos_width += 32;
	mlx_destroy_image(screen.mlx, screen.img);
}

void	put_to_screen(t_all *all, int number_repere)
{
	if (number_repere == 1)
		all->screen.img = mlx_xpm_file_to_image(all->screen.mlx,
				all->texture.wall, &all->size.img_width,
				&all->size.img_height);
	else if (number_repere == 0)
		all->screen.img = mlx_xpm_file_to_image(all->screen.mlx,
				all->texture.floor, &all->size.img_width,
				&all->size.img_height);
	else if (number_repere == 9)
		all->screen.img = mlx_xpm_file_to_image(all->screen.mlx,
				all->texture.player, &all->size.img_width,
				&all->size.img_height);
	else if (number_repere == 3)
		all->screen.img = mlx_xpm_file_to_image(all->screen.mlx,
				all->texture.exit, &all->size.img_width,
				&all->size.img_height);
	else if (number_repere == 4)
		all->screen.img = mlx_xpm_file_to_image(all->screen.mlx,
				all->texture.collectible, &all->size.img_width,
				&all->size.img_height);
	put_the_image(all, all->screen);
}
