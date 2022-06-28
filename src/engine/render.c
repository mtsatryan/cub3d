#include "../../includes/cub3d.h"

void	ft_put_sqr(t_all *s, int x, int y, unsigned int color)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
			ft_put_pixel(&s->map_img, x + j, y - i, color);
		ft_put_pixel(&s->map_img, x + j, y - i, 0x00000000);
	}
	k = x + j;
	i = -1;
	while (++i < 10)
		ft_put_pixel(&s->map_img, k, y - i, 0x00000000);
}

void	minimap(t_all *s)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	s->oro_x = ((s->pos.x - 800) / 100);
	s->oro_y = ((s->pos.y - 800) / 100);
	while (++i < 15)
	{
		while (++j < 15)
		{
			if (ft_in_bounds(s, s->oro_y + i, s->oro_x + j))
				ft_put_sqr(s, j * 10, i * 10, 0x00000000);
			else if (s->map[s->oro_y + i][s->oro_x + j] == '1')
				ft_put_sqr(s, j * 10, i * 10, 0x00000000);
			else if (s->map[s->oro_y + i][s->oro_x + j] >= '0')
				ft_put_sqr(s, j * 10, i * 10, 0x00C8C8C8);
			else
				ft_put_sqr(s, j * 10, i * 10, 0x00000000);
		}
		j = -1;
	}
}

void	ft_draw_line(t_all *s, int x)
{
	int	i;
	int	color;

	i = -1;
	while (++i < s->draw_start)
		ft_put_pixel(&s->fps, x, i, s->_c);
	i = -1;
	while (++i < s->draw_end - s->draw_start)
	{
		color = get_pixel(s, i);
		ft_put_pixel(&s->fps, x, s->draw_start + i, color);
	}
	i = -1;
	while (++i < SIZE_Y - s->draw_end)
		ft_put_pixel(&s->fps, x, i + s->draw_end, s->_f);
}

void	render(t_all *s)
{
	raycast(s, SIZE_X);
	minimap(s);
	mlx_put_image_to_window(s->mlx, s->win, s->fps.img, 0, 0);
	mlx_put_image_to_window(s->mlx, s->win, s->map_img.img, \
		SIZE_X - 150, 0);
}
