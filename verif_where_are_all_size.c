/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_where_are_all_size.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:31:41 by cmois             #+#    #+#             */
/*   Updated: 2021/11/22 17:51:59 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

/*
   all->size.img_width = 0;
   all->size.img_height = 0;          //give_value_later
   all->size.player_pos_width = 0;
   all->size.player_pos_height = 0;
 */

int	number_of_lines_height(t_all *all, char *arg)
{
	int		number_of_lines;
	char	*line;
	int		fd;

	(void)all;
	fd = open(arg, O_RDONLY);
	number_of_lines = 1;
	while (get_next_line(fd, &line) == 1)
	{
		number_of_lines++;
		free(line);
	}
	free(line);
	close(fd);
	all->size.number_of_lines = number_of_lines;
	return (number_of_lines);
}

int	number_of_char_width(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (all->screen.map[i][j])
		j++;
	return (j);
}

void	player_starting_position(t_all *all)
{
	int		i;
	int		j;
	char	**str;

	str = all->screen.map;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
			{
				all->size.player_pos_width = j;
				all->size.player_pos_height = i;
				all->counter.player++;
				j++;
			}
			else
				j++;
		}
		i++;
	}
}

int	number_of_collectible_in_map(t_all *all)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	ret = 0;
	while (all->screen.map[i])
	{
		j = 0;
		while (all->screen.map[i][j])
		{
			if (all->screen.map[i][j] == 'C')
				ret++;
			j++;
		}
		i++;
	}
	return (ret);
}

int	count_number_of_exit(t_all *all)
{
	int	i;
	int	j;
	int	ret;

	ret = 0;
	i = 0;
	while (all->screen.map[i])
	{
		j = 0;
		while (all->screen.map[i][j])
		{
			if (all->screen.map[i][j] == 'E')
				ret++;
			j++;
		}
		i++;
	}
	return (ret);
}
