GREEN	=	\033[1;32m
CYAN	=	\033[0;36m
WHITE	=	\033[0m
CLEAR	=	\r\033[K

NAME = cub3d


CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I libft
CFLAGS += -I inc
CFLAGS += -I minilibx


LIBFT = libft/libft.a
MINILIBX = minilibx/libmlx_Linux.a
MLX_FLAGS = -L minilibx -lmlx -lXext -lX11 -lm -lbsd

SRCS =	src/main.c							\
		src/init/init_data.c				\
		src/init/init_player.c				\
		src/parse/parse_cub.c				\
		src/parse/parse_lines_identifiers.c	\
		src/parse/parse_cub_utils.cs		\
		src/render/render_frame.c			\
		src/render/calculate_steps.c		\
		src/utils/utils_1.c					\
		src/utils/utils_2.c					\
		src/player_update.c					\
		src/read_lines.c					\
		src/player_move.c 					\
		src/hooks.c 						\
		src/drawing_wall.c 					\
		src/textures.c 						\


OBJS = $(SRCS:src/%.c=objs/%.o)

all: $(LIBFT) $(MINILIBX) $(NAME)

$(NAME): objs $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)cub3d ready$(WHITE)"

$(LIBFT):
	@make --silent -C libft

$(MINILIBX):
	@make -C minilibx --silent > /dev/null 2>&1

objs:
	@mkdir -p objs

objs/%.o: src/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make --silent clean -C libft
	@make --silent clean -C minilibx > /dev/null 2>&1
	@rm -rf objs
	@echo "Objetcs files deleted."

fclean: clean
	@make --silent fclean -C libft
	@make --silent clean -C minilibx > /dev/null 2>&1
	@rm -f $(NAME)
	@echo "Full clean completed"

re: fclean all

.PHONY: all clean fclean re
