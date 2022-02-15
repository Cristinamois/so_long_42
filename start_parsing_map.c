/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_parsing_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:40:35 by cmois             #+#    #+#             */
/*   Updated: 2021/11/26 17:18:25 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	treat_line_return(t_all *all)
{
	all->size.pos_width = 0;
	all->size.pos_height += 32;
}

int	check_what_to_display(char c, int nbr)
{
	if (c == '1')
		nbr = 1;
	if (c == '0')
		nbr = 0;
	if (c == 'P')
		nbr = 9;
	if (c == 'C')
		nbr = 4;
	if (c == 'E')
		nbr = 3;
	return (nbr);
}

void	check_last_on_map(t_all *all, int nbr)
{
	nbr = 1;
	put_to_screen(all, nbr);
	treat_line_return(all);
}

void	check_all_norm(t_all *all, int i, int j)
{
	int	nbr;

	nbr = 0;
	while (all->screen.map[i][j])
	{
		if (all->screen.map[i][j + 1] == '\0')
		{
			check_last_on_map(all, nbr);
			break ;
		}
		if (all->screen.map[i][j] == '1' || all->screen.map[i][j] == '0'
				|| all->screen.map[i][j] == 'P'
				|| all->screen.map[i][j] == 'C'
				|| all->screen.map[i][j] == 'E')
		{
			nbr = check_what_to_display(all->screen.map[i][j], nbr);
			put_to_screen(all, nbr);
		}
		else
			exit_in_a_beautiful_way_keur_and_error_msg(all);
		j++;
	}
}

void	parsing_map(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->screen.map[i] && i <= all->size.number_of_lines)
	{
		j = 0;
		check_all_norm(all, i, j);
		i++;
	}
}
