#include "../../includes/cub3d.h"

int	ft_collision(t_all *s, int state)
{
	if (state == FORWARD)
	{
		s->oro_x = (s->pos.x + 15 * s->dir.x) / 100;
		s->oro_y = (s->pos.y + 15 * s->dir.y) / 100;
	}
	else if (state == BACK)
	{
		s->oro_x = (s->pos.x - 15 * s->dir.x) / 100;
		s->oro_y = (s->pos.y - 15 * s->dir.y) / 100;
	}
	else if (state == LEFT)
	{
		s->oro_x = (s->pos.x + 15 * s->perp_dir.x) / 100;
		s->oro_y = (s->pos.y + 15 * s->perp_dir.y) / 100;
	}
	else if (state == RIGHT)
	{
		s->oro_x = (s->pos.x - 15 * s->perp_dir.x) / 100;
		s->oro_y = (s->pos.y - 15 * s->perp_dir.y) / 100;
	}
	if (s->map[s->oro_y][s->oro_x] == '1' || \
		s->map[s->oro_y][s->oro_x] == ' ')
		return (1);
	return (0);
}

void	init_ray_2(t_all *s)
{
	if (s->ray_dir.x < 0)
	{
		s->step_x = -1;
		s->side_dist.x = ((s->pos.x) - s->oro_x) * s->delta_dist.x;
	}
	else
	{
		s->step_x = 1;
		s->side_dist.x = (s->oro_x + 1 - s->pos.x) * \
			s->delta_dist.x;
	}
	if (s->ray_dir.y < 0)
	{
		s->step_y = -1;
		s->side_dist.y = ((s->pos.y) - s->oro_y) * s->delta_dist.y;
	}
	else
	{
		s->step_y = 1;
		s->side_dist.y = (s->oro_y + 1 - s->pos.y) * \
			s->delta_dist.y;
	}
	s->collide = 0;
}

void	init_ray(t_all *s, int i, int amount)
{
	s->camera_x = 2 * i / (double)amount - 1;
	s->ray_dir.x = s->dir.x + s->plane.x * s->camera_x;
	s->ray_dir.y = s->dir.y + s->plane.y * s->camera_x;
	s->oro_x = (int)s->pos.x;
	s->oro_y = (int)s->pos.y;
	if (s->ray_dir.x == 0)
		s->delta_dist.x = 1e30;
	else
		s->delta_dist.x = fabs(1 / s->ray_dir.x);
	if (s->ray_dir.y == 0)
		s->delta_dist.y = 1e30;
	else
		s->delta_dist.y = fabs(1 / s->ray_dir.y);
	init_ray_2(s);
}

void	dda(t_all *s)
{
	while (!s->collide)
	{
		if (s->side_dist.x < s->side_dist.y)
		{
			s->side_dist.x += s->delta_dist.x;
			s->oro_x += s->step_x;
			s->side = 0;
		}
		else
		{
			s->side_dist.y += s->delta_dist.y;
			s->oro_y += s->step_y;
			s->side = 1;
		}
		if (s->map[s->oro_y / 100][s->oro_x / 100] == '1')
			s->collide = 1;
	}
	if (s->side == 0)
		s->perp_wall_dist = s->side_dist.x - s->delta_dist.x;
	else
		s->perp_wall_dist = s->side_dist.y - s->delta_dist.y;
	if (s->perp_wall_dist == 0)
		s->perp_wall_dist = 1;
}

void	raycast(t_all *s, int amount)
{
	int	i;

	i = -1;
	while (++i < amount)
	{
		init_ray(s, i, amount);
		dda(s);
		s->line_h = (int)(SIZE_Y / (s->perp_wall_dist / 100));
		s->draw_start = (-s->line_h / 2 + SIZE_Y / 2);
		s->prev_start = s->draw_start;
		if (s->draw_start < 0)
			s->draw_start = 0;
		s->draw_end = (s->line_h / 2 + SIZE_Y / 2);
		if (s->draw_end >= SIZE_Y)
			s->draw_end = SIZE_Y - 1;
		if (s->side == 0 && s->ray_dir.x > 0)
			s->side = EAST;
		else if (s->side == 0)
			s->side = WEST;
		else if (s->side == 1 && s->ray_dir.y > 0)
			s->side = SOUTH;
		else
			s->side = NORTH;
		ft_draw_line(s, amount - i - 1);
	}
}
