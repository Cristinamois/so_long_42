/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 09:42:23 by cmois             #+#    #+#             */
/*   Updated: 2021/11/26 17:44:25 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <mlx.h>
# include <string.h>
# include "libft.h"
# include "get_next_line.h"
# define BUFFER 1000

typedef struct s_screen
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	**map;
	int		fd;
}		t_screen;

typedef struct s_size
{
	int	pos_width;
	int	pos_height;
	int	img_width;
	int	img_height;
	int	player_pos_width;
	int	player_pos_height;
	int	number_of_lines;
}		t_size;

typedef struct s_texture
{
	char	*wall;
	char	*floor;
	char	*player;
	char	*collectible;
	char	*exit;
}		t_texture;

typedef struct s_counter
{
	int	moves;
	int	player;
	int	collectible;
	int	exit;

}		t_counter;

typedef struct s_all
{
	t_screen	screen;
	t_size		size;
	t_texture	texture;
	t_counter	counter;
}		t_all;

/*functions added for norm*/
void	increment_i_j(int *i, int *j);

/*------------------------*/

/*ERRORS CHECK*/

int		error_control(char *str, t_all *all);
int		valid_map(t_all *all);
int		error_control_part_2(t_all *all);
int		compare_extention(char *model, char *to_compare);
/*------------*/

/*giving values*/
void	give_value_to_map(t_all *all, char *arg);
int		number_of_lines_height(t_all *all, char *arg);
int		number_of_char_width(t_all *all);
void	player_starting_position(t_all *all);
int		number_of_collectible_in_map(t_all *all);
int		count_number_of_exit(t_all *all);
char	**taking_lines_from_file(char *arg);
int		is_next_bloc_a_collectible_part_two(t_all *all, int number_ref);
int		is_next_bloc_a_collectible_part_3(t_all *all, int number_ref);
/*-------------*/

/*leave*/
void	exit_in_a_beautiful_way_keur(t_all *all);
int		close_win_wrapper(t_all *all);
int		close_window(t_all *all);
void	ft_free_double(char **str);
void	exit_in_a_beautiful_way_keur_and_error_msg(t_all *all);
/*-----*/

/*put stuff to screen*/
void	put_to_screen(t_all *all, int number_repere);
void	parsing_map(t_all *all);
/*-------------------*/

/*moving checks*/
void	right_moving_check(t_all *all, int number_ref);
void	left_moving_check(t_all *all, int number_ref);
void	up_moving_check(t_all *all, int number_ref);
void	down_moving_check(t_all *all, int number_ref);
int		is_next_bloc_a_collectible(t_all *all, int number_ref);
int		checking_for_walls(t_all *all, int number_ref);
int		check_right(t_all *all, char **str);
int		check_left(t_all *all, char **str);
int		check_up(t_all *all, char **str);
int		check_down(t_all *all, char **str);
void	moving_right(t_all *all);
void	moving_left(t_all *all);
void	moving_up(t_all *all);
void	moving_down(t_all *all);

/*-------------*/
#endif
