#include "../../includes/cub3d.h"

int	ft_check_surround_h(char **map)
{
	int	y_c;
	int	x_c;

	y_c = 0;
	while (map[y_c])
	{
		x_c = 0;
		while (map[y_c][x_c])
		{
			while (map[y_c][x_c] == ' ' && map[y_c][x_c] != 0)
				x_c++;
			if (map[y_c][x_c] == 0)
				break ;
			if (map[y_c][x_c] != '1')
				return (0);
			while (map[y_c][x_c] != ' ' && map[y_c][x_c] != 0)
				x_c++;
			if (map[y_c][x_c - 1] != '1')
				return (0);
		}
		y_c++;
	}
	return (1);
}

int	ft_check_surround_v(char **map)
{
	int	y_c;
	int	x_c;

	x_c = 0;
	while (map[0][x_c] != 0)
	{
		y_c = 0;
		while (map[y_c] != NULL)
		{
			while (map[y_c] && map[y_c][x_c] == ' ')
				y_c++;
			if (map[y_c] == NULL)
				break ;
			if (map[y_c][x_c] != '1')
				return (0);
			while (map[y_c] && map[y_c][x_c] != ' ')
				y_c++;
			if (map[y_c - 1][x_c] != '1')
				return (0);
		}
		x_c++;
	}
	return (1);
}

int	check_chars(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != ' ' && map[y][x] != '0'
				&& map[y][x] != 'N' && map[y][x] != 'E' && map[y][x] != 'S'
				&& map[y][x] != 'W')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
