GREEN	=	\033[1;32m
CYAN	=	\033[0;36m
WHITE	=	\033[0m
CLEAR	=	\r\033[K

NAME = Cub3d


CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
CFLAGS += -I libft
CFLAGS += -I include
CFLAGS += -I minilibx


LIBFT = libft/libft.a
MINILIBX = minilibx/libmlx_Linux.a
MLX_FLAGS = -L minilibx -lmlx -lXext -lX11 -lm -lbsd

SRCS = 	src/init_mlx.c src/init_data.c src/utils.c src/player_update.c src/init_player.c		\
	src/utils1.c src/parse_lines_identifiers.c src/open_and_readlines.c src/parser_map.c		\
	src/validate_map.c src/player_move.c src/hooks.c src/drawing_wall.c src/calculate_steps.c	\
	src/raycasting.c src/textures.c src/main.c


OBJS = $(SRCS:src/%.c=objs/%.o)

all: $(LIBFT) $(MINILIBX) $(NAME)

sanitize: 

$(NAME): objs $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)Cub3d ready$(WHITE)"

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
