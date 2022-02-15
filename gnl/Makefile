# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmois <cmois@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 10:13:44 by cmois             #+#    #+#              #
#    Updated: 2021/06/10 15:25:24 by cmois            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =    get_next_line.a

CFLAGS         =    -Wall -Wextra -Werror -c

CC            =    gcc

SRCS        =   get_next_line.c get_next_line_utils.c \

OBJS        =    $(SRCS:.c=.o)


all        :    $(NAME)

$(NAME)    : $(OBJS)
	@ar crs $@ $(OBJS)

%.o : %.c
	@$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:			fclean all
