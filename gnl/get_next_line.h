/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 09:14:30 by cmois             #+#    #+#             */
/*   Updated: 2021/11/21 16:44:54 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# define ERROR -1
# define BUFFER_SIZE 1000000

int		get_next_line(int fd, char **line);
size_t	ft_strlen_gnl(char *str);
size_t	ft_strlenn(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	clean(char *str, size_t i);
void	ft_bzero_gnl(char *str);
int		n_in_buff(char *str);

#endif
