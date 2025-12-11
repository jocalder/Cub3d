GREEN	=	\033[1;32m
CYAN	=	\033[0;36m
WHITE	=	\033[0m
CLEAR	=	\r\033[K

NAME = Cub3d


CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I libft
CFLAGS += -I include
CFLAGS += -I minilibx


LIBFT = libft/libft.a
MINILIBX = minilibx/libmlx_Linux.a
MLX_FLAGS = -L minilibx -lmlx -lXext -lX11 -lm -lbsd

SRCS = 	init_mlx.c init_data.c utils.c main.c


OBJS = $(SRCS:%.c=objs/%.o)

all: $(LIBFT) $(MINILIBX) $(NAME)

$(NAME): objs $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)Cub3d ready$(WHITE)"

$(LIBFT):
	@make --silent -C libft

$(MINILIBX):
	@make -C minilibx --silent > /dev/null 2>&1

objs:
	@mkdir -p objs/src/

objs/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make --silent clean -C libft
	@make clean -C minilibx
	@rm -rf objs
	@echo "Objetcs files deleted."

fclean: clean
	@make --silent fclean -C libft
	@make clean -C minilibx
	@rm -f $(NAME)
	@echo "Full clean completed"

re: fclean all

.PHONY: all clean fclean re
