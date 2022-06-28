#include "../../includes/cub3d.h"

void	ft_put_pixel(t_texture *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_l + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_arrlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_in_bounds(t_all *s, int i, int j)
{
	int	retval;

	retval = 0;
	if (i < 0 || j < 0 || i > ft_arrlen(s->map) - 1)
		retval = 1;
	else if (j > (int)ft_strlen(s->map[i]) - 1)
		retval = 1;
	return (retval);
}

void	free_all_2(t_all *s)
{
	ft_free_arr_char(s->map);
	free_img(s->spot_e, s->size_e);
	free_img(s->spot_w, s->size_w);
	free_img(s->spot_s, s->size_s);
	free_img(s->spot_n, s->size_n);
	mlx_destroy_image(s->mlx, s->map_img.img);
	mlx_destroy_image(s->mlx, s->fps.img);
	mlx_destroy_window(s->mlx, s->win);
}
