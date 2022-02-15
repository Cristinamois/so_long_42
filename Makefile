NAME            = so_long

CC                = gcc
CFLAGS            = -g -Wall -Wextra -Werror

SRCS            = main.c error_control_arg.c valid_map_control.c functions_added_for_norm.c put_map_in_map.c verif_where_are_all_size.c \
					error_control_struct.c exit_file.c  \
					start_parsing_map.c put_to_screen.c  \
					check_next_bloc.c moving.c walls_check.c is_next_bloc_collectible_part_two.c\
					

INCS        = -I ./inc -I ./mlx -I ./libft/ -I ./gnl

SOURCES        = $(SRCS:.c=.o)

DEPS    = $(SOURCES:.o=.d)
DFLAGS            = -MMD -MF $(@:.o=.d)

all: $(NAME)


-include $(DEPS)
$(NAME): $(SOURCES) ./solong.h
	${MAKE} -C mlx
	${MAKE} -C libft $(INCS)
	${MAKE} -C gnl
	$(CC) $(CFLAGS) $(SOURCES) $(INCS) -Imlx -Lmlx -lmlx -lXext -lX11 -lm -o $(NAME) ./libft/libft.a ./gnl/get_next_line.a

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -Imlx -c $< -o $@ $(DFLAGS)

clean:
	${MAKE} -C mlx clean
	${MAKE} -C libft clean
	${MAKE} -C gnl clean
	rm *.o
	rm *.d

fclean: clean
	${MAKE} -C libft fclean
	${MAKE} -C gnl fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
