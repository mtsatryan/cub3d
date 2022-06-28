#include "../../includes/cub3d.h"

void	free_img(int **array, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(array[i]);
	free(array);
}

void	free_all(t_all *s)
{
	if (s->tex_e == 1)
		ft_free_arr_int(s->spot_e, s->size_e);
	if (s->tex_w == 1)
		ft_free_arr_int(s->spot_w, s->size_w);
	if (s->tex_s == 1)
		ft_free_arr_int(s->spot_s, s->size_s);
	if (s->tex_n == 1)
		ft_free_arr_int(s->spot_n, s->size_n);
	if (s->map)
		ft_free_arr_char(s->map);
	free(s);
}

int	free_str(char *s1)
{
	free(s1);
	return (0);
}
