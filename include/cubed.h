/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:23:19 by marvin            #+#    #+#             */
/*   Updated: 2025/12/09 09:23:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
#define CUBED_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <math.h>
#include "libft.h"
#include "mlx.h"

#define	WIDTH	640
#define	HEIGHT	420
#define POINT_SIZE 8

#define	W	119
#define	A	97
#define	S	115
#define	D	100

#define	UP		65362
#define	DOWN	65364
#define	LEFT	65361
#define	RIGHT	65363
#define ESC     65307

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
} t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	img;
} t_mlx;

typedef struct s_win
{
	int		width;
	int		height;
} t_win;

typedef struct s_map
{
	char	**matrix;
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
} t_map;

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
} t_player;

typedef struct s_ray
{
	double		camera_x;
	double		dir_x;
	double		dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double		sidedist_x;
	double		sidedist_y;
	double		delta_x;
	double		delta_y;
	double		wall_dist;
	double		wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
} t_ray;

typedef struct s_keys
{
	int	w;
    int	a;
    int	s;
    int	d;
    int	left;
    int	right;
} t_keys;

typedef struct s_cub
{
	t_mlx		mlx;
	t_win		win;
	t_img		img;
	t_map		map;
	t_player	player;
	t_ray		ray;
	t_keys		keys;
} t_cub;

/*INIT DATA*/
void	init_data(t_cub *cub);

/*INIT MLX*/
void	init_mlx(t_cub *cub);

/*KEYS*/
int		key_press(int k, t_cub *cub);
int		key_release(int k, t_cub *cub);
void	close_program(t_cub *cub);

/*PARSER*/
char	**open_and_read_lines(char *path);
int		parse_cub(t_cub *cub, char *path);
char	**parse_map(char **lines, int start, int *out_height, int *out_width);
void	validate_identifiers(t_map *map);
int		find_map_start(t_map *map, char	**lines);

int		parse_lines_identifier(t_map *map, char *line);
int		parse_color(char *str);

/*RENDERING*/
int		render_frame(t_cub *cub);

/*UTILS*/
void	exit_error(const char *str);
void	free_map(char **map, int height);
int		is_player_char(char c);
int		ft_array_len(char **array);
void	print_map(t_map *map);
#endif