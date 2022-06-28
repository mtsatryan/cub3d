#include "../../includes/cub3d.h"

int	ft_close(void *ptr)
{
	t_all	*s;

	s = (t_all *)ptr;
	free_all_2(s);
	exit(0);
}

void	ft_move(int keycode, t_all *s)
{
	if (keycode == K_W && !ft_collision(s, FORWARD))
	{
		s->pos.x += 10 * s->dir.x;
		s->pos.y += 10 * s->dir.y;
	}
	if (keycode == K_S && !ft_collision(s, BACK))
	{
		s->pos.x -= 10 * s->dir.x;
		s->pos.y -= 10 * s->dir.y;
	}
	if (keycode == K_A && !ft_collision(s, LEFT))
	{
		s->pos.x += 10 * s->perp_dir.x;
		s->pos.y += 10 * s->perp_dir.y;
	}
	if (keycode == K_D && !ft_collision(s, RIGHT))
	{
		s->pos.x -= 10 * s->perp_dir.x;
		s->pos.y -= 10 * s->perp_dir.y;
	}
}

void	ft_norme_vector(t_vec *dir, double len)
{
	double	v;
	double	f;

	v = sqrt(dir->x * dir->x + dir->y * dir->y);
	f = len / v;
	dir->x *= f;
	dir->y *= f;
}

void	ft_rotate_utils(t_all *s, double alpha)
{
	double	temp;

	temp = s->dir.x;
	s->dir.x = s->dir.x * cos(alpha) - s->dir.y * sin(alpha);
	s->dir.y = temp * sin(alpha) + s->dir.y * cos(alpha);
	temp = s->perp_dir.x;
	s->perp_dir.x = s->perp_dir.x * cos(alpha) - \
		s->perp_dir.y * sin(alpha);
	s->perp_dir.y = temp * sin(alpha) + s->perp_dir.y * cos(alpha);
	temp = s->plane.x;
	s->plane.x = s->plane.x * cos(alpha) - s->plane.y * sin(alpha);
	s->plane.y = temp * sin(alpha) + s->plane.y * cos(alpha);
}

void	ft_rotate(int keycode, t_all *s)
{
	if (keycode == K_Q)
		ft_rotate_utils(s, -0.05);
	else if (keycode == K_E)
		ft_rotate_utils(s, 0.05);
	ft_norme_vector(&s->dir, 1);
	ft_norme_vector(&s->perp_dir, 1);
	ft_norme_vector(&s->plane, 0.66);
}

int	keyhandler(int keycode, void *ptr)
{
	t_all	*s;

	s = (t_all *)ptr;
	if (keycode == K_ESC)
	{
		free_all_2(s);
		exit(0);
	}
	ft_move(keycode, s);
	ft_rotate(keycode, s);
	render(s);
	return (0);
}