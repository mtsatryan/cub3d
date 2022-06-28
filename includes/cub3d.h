/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgtsatryan <mgtsatryan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:26:46 by mgtsatryan        #+#    #+#             */
/*   Updated: 2022/06/09 19:26:47 by mgtsatryan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

# define SIZE_X 1280
# define SIZE_Y 720
# define MAP_W 150
# define MAP_H 150

# define K_W		13
# define K_A		0
# define K_S		1
# define K_D		2
# define K_Q		12
# define K_E		14
# define K_ESC 		53
# define K_LEFT		123
# define K_RIGHT	124
# define K_DOWN 	125
# define K_UP 		126
# define ON_KEYDOWN	2
# define ON_DESTROY	17

enum flags
{
	FORWARD,
	RIGHT,
	BACK,
	LEFT,	
	NORTH,
	EAST,
	WEST,
	SOUTH
};

typedef struct s_orient
{
	int	north;
	int	east;
	int	west;
	int	south;
	int	floor;
	int	ceiling;
	int	doubles;
}	t_orient;

typedef struct s_vec
{
	double	x;
	double	y;
}				t_vec;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
}				t_texture;

typedef struct s_xpm
{
	int		size;
	int		colours;
	int		cpp;
	char	**code;
	int		*value;
}	t_xpm;

typedef struct s_all
{
	void		*mlx;
	void		*win;
	t_vec	pos;
	t_vec	dir;
	t_vec	perp_dir;
	t_vec	plane;
	t_vec	ray_dir;
	t_vec	side_dist;
	t_vec	delta_dist;
	t_vec	v;
	t_texture		map_img;
	t_texture		fps;
	int		tex_s;
	int		tex_w;
	int		tex_e;
	int		tex_n;
	char		**map;
	int			_f;
	int			_c;
	int			size_n;
	int			size_e;
	int			size_s;
	int			size_w;
	int			**spot_n;
	int			**spot_e;
	int			**spot_s;
	int			**spot_w;
	double		camera_x;
	double		perp_wall_dist;
	int			oro_x;
	int			oro_y;
	int			step_x;
	int			step_y;
	int			collide;
	int			side;
	int			line_h;
	int			draw_start;
	int			draw_end;
	int			prev_start;
	int			pixel_x;
	int			pixel_y;
	int			rev;
}				t_all;

int		ft_arrlen(char **s);
void	ft_norme_vector(t_vec *dir, double len);
void	ft_put_pixel(t_texture *img, int x, int y, int color);
void	ft_draw_line(t_all *s, int x);
void	raycast(t_all *s, int amount);
t_all	*init(char *path);
void	render(t_all *s);
int		ft_close(void *ptr);
int		keyhandler(int keycode, void *ptr);
int		ft_collision(t_all *s, int state);
int		ft_in_bounds(t_all *s, int i, int j);
int		get_pixel(t_all *s, int i);
int	get_input(t_all *s, char *path_name);
int	set_colors_cf(char *line, t_all *s);
int	ft_message_int(char *line, int perror);
void	print_arr(char	**arr, int fd);
void	ft_free_arr_char(char	**arr);
int		ft_hextoi(char	*hex);
int	xpm_to_int(char *path, char c, t_all *s);
void	print_2d_int_array(int **arr, int size);
int	ft_check_surround_v(char **map);
int	ft_check_surround_h(char **map);
void	free_all_2(t_all *s);
int	check_chars(char **map);
char	**ft_stradd(char **arr, char *new_el);
void	ft_free_arr_int(int **arr, int size);
int	xpm_to_int(char *path, char c, t_all *s);
void	ft_put_in_struct(char c, int size, int **arr, t_all *s);
char	*get_path(char *path);
int	xpm_to_int(char *path, char c, t_all *s);
char	*skip_lines(int fd);
void	fill_texture_size(char *line, t_xpm *s);
void	fill_arr(t_xpm *s, int fd);
int		find_ind(char *line, t_xpm *tex_data);
int		**fill_texture(t_xpm *tex_data, int fd);
void	ft_add_newline(char **map);
void	free_img(int **array, int size);
int		free_str(char *s1);
void	free_all(t_all *s);
char	*init_check(t_orient *data, int fd);
void	ft_find_doubles_util(int *check, t_orient *data);
int	ft_find_doubles(int fd);
void	init_utils(t_all *s);

#endif
