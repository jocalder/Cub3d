/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:38:44 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/07 16:38:44 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <stdbool.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define WIDTH		960
# define HEIGHT		540
# define POINT_SIZE	8

# define W	119
# define A	97
# define S	115
# define D	100

# define LEFT	65361
# define RIGHT	65363
# define ESC	65307

# define MOVE_SPEED 0.02
# define ROT_SPEED  0.01

# define TEX_NORTH 0
# define TEX_SOUTH 1
# define TEX_EAST  2
# define TEX_WEST  3

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_mlx;

typedef struct s_win
{
	int		width;
	int		height;
}	t_win;

typedef struct s_map
{
	char	**matrix;
	char	**cpy_map;
	int		fd;
	int		line_count;
	int		start;
	int		width;
	int		height;

	char	*no;
	char	*so;
	char	*we;
	char	*ea;

	int		floor_color;
	int		ceiling_color;
}	t_map;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		move_x;
	int		move_y;
	int		rotate;
	char	dir;
}	t_player;

typedef struct s_ray
{
	double		camera_x;
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	double		sidedist_x;
	double		sidedist_y;
	double		delta_x;
	double		delta_y;
	double		wall_dist;
	double		wall_x;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}	t_ray;

typedef struct s_keys
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		up;
	int		down;
	int		left;
	int		right;
}	t_keys;

typedef struct s_cub
{
	t_mlx		mlx;
	t_win		win;
	t_img		img;
	t_img		textures[4];
	t_map		map;
	t_player	player;
	t_ray		ray;
	t_keys		keys;
}	t_cub;

/*INIT*/
void	init_map(t_map *map);
void	init_data_player(t_player *player);
void	init_raycasting(t_ray *ray);
void	init_window(t_win *window);
void	init_keys(t_keys *keys);

void	init_player(t_cub *cub, t_map *map);
∫
/*PARSE*/
int		parse_cub(t_cub *cub, char *path);
int		parse_texture_north_and_south(t_map *map, char *line);
int		parse_texture_west_and_east(t_map *map, char *line);
int		parse_floor_and_ceiling(t_map *map, char *line);

/*PARSE_UTILS*/
void	padding_rows(t_map *map);
void	validate_identifiers(t_map *map);
int		map_check(t_cub *cub);

/*PLAYER*/

/*RENDER*/
int		render_frame(t_cub *cub);
void	calculate_step(t_cub *cub);


void	move_forward(t_cub *cub);
void	move_backward(t_cub *cub);
void	move_left(t_cub *cub);
void	move_right(t_cub *cub);
void	update_player(t_cub *cub);

/*RENDERING AND RAYCASTING*/

void	put_pixel(t_cub *cub, int x, int y, int color);
int		get_texture_pixel(t_img *texture, int x, int y);
void	calculate_wall_x(t_cub *cub);
t_img	*get_wall_texture(t_cub *cub);
void	draw_textured_column(t_cub *cub, int x);
void	draw_column(t_cub *cub, int x);
void	calculate_wall(t_cub *cub);
∫
/*KEYS*/
int		key_press(int k, t_cub *cub);
int		key_release(int k, t_cub *cub);

/*UTILS*/
void	exit_error(const char *str);
char	**add_line(char **array, char *line, int count);
int		is_player_char(char c);
char	*get_path(char *line);
char	*cpy_map(char *line, int *width)

void	free_map(char **map, int height);
int		is_walkable(t_map *map, double x, double y);
void	close_program(t_cub *cub);
int		parse_value(char **str);

#endif
