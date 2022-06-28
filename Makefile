NAME	:=	cub3d

SRCS	:=	src/main.c \
			src/engine/init.c \
			src/engine/ft_keycode.c \
			src/engine/raycasting.c \
			src/engine/render.c \
			src/engine/utils.c \
			src/engine/textures.c\
			src/parsing/arrays.c\
			src/parsing/colors_cf.c\
			src/parsing/input.c\
			src/parsing/utils.c\
			src/parsing/map_check.c\
			src/parsing/xpm_to_int.c\
			src/parsing/xpm_to_int_utils.c\
			src/parsing/ft_free.c\
			src/parsing/check.c
		
OBJS	:=	${SRCS:.c=.o}

CC		:=	gcc

CFLAGS	:=	-Wall -Wextra -Wextra -O3



all:		${NAME}

%.o: %.c
		${CC} ${CFLAGS} -Imlx -c $< -o $@

${NAME}:	${OBJS}
		@make -C ./libft
		@make -C ./get_next_line all
		@make -C ./mlx all
		@${CC} ${OBJS} ${CFLAGS} libft/libft.a get_next_line/get_next_line.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
		@make -C ./libft clean
		@make -C ./get_next_line clean
		@make -C ./mlx clean
		rm -f ${OBJS} ${FPS_OBJS}

fclean:		clean
		@make -C ./libft fclean
		@make -C ./get_next_line fclean
		rm -f ${NAME} ${FPS_NAME}

re:			fclean all

.PHONY:		all clean fclean re