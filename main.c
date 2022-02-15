/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 14:29:04 by cmois             #+#    #+#             */
/*   Updated: 2021/11/26 17:20:24 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_structure(t_all *all, char *arg)
{
	all->screen.addr = NULL;
	all->screen.bits_per_pixel = 0;
	all->screen.line_length = 0;
	all->screen.endian = 0;
	all->counter.player = 0;
	give_value_to_map(all, arg);
	all->texture.wall = "textures/dark_vortex.xpm";
	all->texture.floor = "textures/sol_good_one_shit.xpm";
	all->texture.player = "textures/crisclope_font_ok.xpm";
	all->texture.collectible = "textures/collectible_food.xpm";
	all->texture.exit = "textures/outdoor.xpm";
	all->size.pos_width = 0;
	all->size.pos_height = 0;
	all->size.img_width = number_of_char_width(all);
	all->size.img_height = number_of_lines_height(all, arg);
	player_starting_position(all);
	all->counter.moves = 0;
	all->counter.collectible = number_of_collectible_in_map(all);
	all->counter.exit = count_number_of_exit(all);
}

void	start_mlx(t_all *all)
{
	all->screen.mlx = mlx_init();
	all->screen.mlx_win = mlx_new_window(all->screen.mlx,
			(all->size.img_width * 32),
			(all->size.img_height * 32), "It was long");
}

int	move(int keycode, t_all *all)
{
	char	*moving_string;

	if (keycode == 65307)
		close_window(all);
	if (keycode == 100)
		right_moving_check(all, 6);
	if (keycode == 97)
		left_moving_check(all, 4);
	if (keycode == 119)
		up_moving_check(all, 8);
	if (keycode == 115)
		down_moving_check(all, 5);
	moving_string = ft_itoa(all->counter.moves);
	ft_putstr_fd(moving_string, 1);
	ft_putchar_fd('\r', 1);
	free(moving_string);
	return (1);
}

int	main(int ac, char **av)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	if (!all)
		return (0);
	all->screen.map = NULL;
	if (ac == 2 && (error_control(av[1], all) == 1))
	{
		init_structure(all, av[1]);
		if (error_control_part_2(all) == 1)
		{
			start_mlx(all);
			parsing_map(all);
		}
		else
			exit_in_a_beautiful_way_keur_and_error_msg(all);
	}
	else
		exit_in_a_beautiful_way_keur_and_error_msg(all);
	mlx_key_hook(all->screen.mlx_win, move, all);
	mlx_hook(all->screen.mlx_win, 17, 0L, &close_win_wrapper, all);
	mlx_loop(all->screen.mlx);
	exit (0);
}
