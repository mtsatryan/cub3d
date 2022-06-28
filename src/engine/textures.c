#include "../../includes/cub3d.h"

int	read_texture(t_all *s, int **tex, int i, int size)
{
	double	percentage;
	int		color;


	if (s->side == NORTH || s->side == SOUTH)
		percentage = fmod(s->v.x, 100);
	else
		percentage = fmod(s->v.y, 100);
	percentage /= 100;
	if (s->rev)
		percentage = 1 - percentage;
	s->pixel_y = (int)(size * i / s->line_h);
	s->pixel_x = (int)(percentage * size);
	color = tex[s->pixel_y][s->pixel_x];
	return (color);
}

int	get_pixel(t_all *s, int i)
{
	int	color;

	s->v.x = (s->perp_wall_dist) * s->ray_dir.x + s->pos.x;
	s->v.y = (s->perp_wall_dist) * s->ray_dir.y + s->pos.y;
	if (s->prev_start < 0)
		i -= s->prev_start;
	if (s->side == SOUTH || s->side == WEST)
		s->rev = 1;
	else
		s->rev = 0;
	if (s->side == NORTH)
		color = read_texture(s, s->spot_n, i, \
			s->size_n);
	else if (s->side == SOUTH)
		color = read_texture(s, s->spot_s, i, \
			s->size_s);
	else if (s->side == WEST)
		color = read_texture(s, s->spot_w, i, \
			s->size_w);
	else
		color = read_texture(s, s->spot_e, i, \
			s->size_e);
	return (color);
}
