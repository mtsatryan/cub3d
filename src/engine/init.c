#include "../../includes/cub3d.h"

void	ft_spawn_dir(t_all *s, int i, int j)
{
	if (s->map[i][j] == 'N')
	{
		s->dir.x = 0;
		s->dir.y = -1;
	}
	else if (s->map[i][j] == 'S')
	{
		s->dir.x = 0;
		s->dir.y = 1;
	}
	else if (s->map[i][j] == 'W')
	{
		s->dir.x = -1;
		s->dir.y = 0;
	}
	else if (s->map[i][j] == 'E')
	{
		s->dir.x = 1;
		s->dir.y = 0;
	}
	s->perp_dir.x = s->dir.y;
	s->perp_dir.y = s->dir.x * -1;
	s->plane.x = s->perp_dir.x;
	s->plane.y = s->perp_dir.y;
	ft_norme_vector(&s->plane, 0.66);
}

void	set_vecs(t_all *s)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < ft_arrlen(s->map))
	{
		while (++j < (int)ft_strlen(s->map[i]))
		{
			if (s->map[i][j] == 'N' || s->map[i][j] == 'S' \
				|| s->map[i][j] == 'E' || s->map[i][j] == 'W')
			{
				s->pos.x = j * 100 + 50;
				s->pos.y = i * 100 + 50;
				ft_spawn_dir(s, i, j);
			}
		}
		j = -1;
	}
}

int	player_spawn(char **map)
{
	int	i;
	int	j;
	int	p_count;

	i = -1;
	p_count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || \
				map[i][j] == 'E' || map[i][j] == 'S')
				p_count++;
		}
	}
	if (p_count != 1)
		return (0);
	return (1);
}

void	init_utils(t_all *s)
{
		s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, SIZE_X, SIZE_Y, "cub3d");
	s->map_img.img = mlx_new_image(s->mlx, MAP_W, MAP_H);
	s->map_img.addr = mlx_get_data_addr(s->map_img.img, \
		&s->map_img.bpp, \
		&s->map_img.line_l, &s->map_img.endian);
	s->fps.img = mlx_new_image(s->mlx, SIZE_X, SIZE_Y);
	s->fps.addr = mlx_get_data_addr(s->fps.img, \
		&s->fps.bpp, \
		&s->fps.line_l, &s->fps.endian);
}

t_all	*init(char *path)
{
	t_all	*s;

	s = malloc(sizeof(t_all));
	s->tex_n = 0;
	s->tex_s = 0;
	s->tex_e = 0;
	s->tex_w = 0;
	s->map = NULL;
	s->_f = -1;
	s->_c = -1;
	if (get_input(s, path) == 0)
	{
		free_all(s);
		return (NULL);
	}
	init_utils(s);
	if (!player_spawn(s->map))
	{
		ft_message_int("Invalid amount of player positions\n", 0);
		free_all_2(s);
		exit(0);
	}
	set_vecs(s);
	return (s);
}
