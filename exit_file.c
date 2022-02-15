/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:57:45 by cmois             #+#    #+#             */
/*   Updated: 2021/11/26 17:43:04 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	close_window(t_all *all)
{
	if (all->screen.mlx_win)
		mlx_destroy_window(all->screen.mlx, all->screen.mlx_win);
	if (all->screen.mlx)
	{
		mlx_destroy_display(all->screen.mlx);
		free(all->screen.mlx);
	}
	exit_in_a_beautiful_way_keur(all);
	return (0);
}

int	close_win_wrapper(t_all *all)
{
	if (all->screen.mlx_win)
		mlx_destroy_window(all->screen.mlx, all->screen.mlx_win);
	if (all->screen.mlx)
	{
		mlx_destroy_display(all->screen.mlx);
		free(all->screen.mlx);
	}
	exit_in_a_beautiful_way_keur(all);
	return (0);
}

void	ft_free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
}

void	exit_in_a_beautiful_way_keur(t_all *all)
{
	if (all->screen.map)
	{
		ft_free_double(all->screen.map);
		free(all->screen.map);
	}
	all->counter.moves = 0;
	if (all)
		free(all);
	exit (0);
}

void	exit_in_a_beautiful_way_keur_and_error_msg(t_all *all)
{
	if (all->screen.map)
	{
		ft_free_double(all->screen.map);
		free(all->screen.map);
	}
	all->counter.moves = 0;
	if (all)
		free(all);
	ft_putstr_fd("Error\nSomething went wrong\n", 1);
	ft_putstr_fd("Please_check the map, the arguments, ", 1);
	ft_putstr_fd("or anything that makes the program going wrong\n", 1);
	exit (0);
}
