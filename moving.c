/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:53:50 by cmois             #+#    #+#             */
/*   Updated: 2021/11/25 09:28:51 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	moving_right(t_all *all)
{
	all->screen.img = mlx_xpm_file_to_image(all->screen.mlx,
			all->texture.player, &all->size.img_width,
			&all->size.img_height);
	mlx_put_image_to_window(all->screen.mlx, all->screen.mlx_win,
		all->screen.img, (((all->size.player_pos_width + 1) * 32)),
		(all->size.player_pos_height * 32));
	mlx_destroy_image(all->screen.mlx, all->screen.img);
	all->screen.img = mlx_xpm_file_to_image(all->screen.mlx, all->texture.floor,
			&all->size.img_width, &all->size.img_height);
	mlx_put_image_to_window(all->screen.mlx, all->screen.mlx_win,
		all->screen.img, (((all->size.player_pos_width) * 32)),
		(all->size.player_pos_height * 32));
	mlx_destroy_image(all->screen.mlx, all->screen.img);
	all->size.player_pos_width++;
}

void	moving_left(t_all *all)
{
	all->screen.img = mlx_xpm_file_to_image(all->screen.mlx,
			all->texture.player, &all->size.img_width,
			&all->size.img_height);
	mlx_put_image_to_window(all->screen.mlx, all->screen.mlx_win,
		all->screen.img, (((all->size.player_pos_width - 1) * 32)),
		(all->size.player_pos_height * 32));
	mlx_destroy_image(all->screen.mlx, all->screen.img);
	all->screen.img = mlx_xpm_file_to_image(all->screen.mlx, all->texture.floor,
			&all->size.img_width, &all->size.img_height);
	mlx_put_image_to_window(all->screen.mlx, all->screen.mlx_win,
		all->screen.img, (((all->size.player_pos_width) * 32)),
		(all->size.player_pos_height * 32));
	mlx_destroy_image(all->screen.mlx, all->screen.img);
	all->size.player_pos_width--;
}

void	moving_up(t_all *all)
{
	all->screen.img = mlx_xpm_file_to_image(all->screen.mlx,
			all->texture.player, &all->size.img_width,
			&all->size.img_height);
	mlx_put_image_to_window(all->screen.mlx, all->screen.mlx_win,
		all->screen.img, ((all->size.player_pos_width * 32)),
		((all->size.player_pos_height - 1) * 32));
	mlx_destroy_image(all->screen.mlx, all->screen.img);
	all->screen.img = mlx_xpm_file_to_image(all->screen.mlx, all->texture.floor,
			&all->size.img_width, &all->size.img_height);
	mlx_put_image_to_window(all->screen.mlx, all->screen.mlx_win,
		all->screen.img, (all->size.player_pos_width * 32),
		(all->size.player_pos_height * 32));
	mlx_destroy_image(all->screen.mlx, all->screen.img);
	all->size.player_pos_height--;
}

void	moving_down(t_all *all)
{
	all->screen.img = mlx_xpm_file_to_image(all->screen.mlx,
			all->texture.player, &all->size.img_width,
			&all->size.img_height);
	mlx_put_image_to_window(all->screen.mlx, all->screen.mlx_win,
		all->screen.img, (all->size.player_pos_width * 32),
		((all->size.player_pos_height + 1) * 32));
	mlx_destroy_image(all->screen.mlx, all->screen.img);
	all->screen.img = mlx_xpm_file_to_image(all->screen.mlx, all->texture.floor,
			&all->size.img_width, &all->size.img_height);
	mlx_put_image_to_window(all->screen.mlx, all->screen.mlx_win,
		all->screen.img, (all->size.player_pos_width * 32),
		(all->size.player_pos_height * 32));
	mlx_destroy_image(all->screen.mlx, all->screen.img);
	all->size.player_pos_height++;
}
