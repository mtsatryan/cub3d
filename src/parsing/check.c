#include "../../includes/cub3d.h"

char	*init_check(t_orient *datas, int fd)
{
	char	*line;

	datas->east = 0;
	datas->north = 0;
	datas->west = 0;
	datas->south = 0;
	datas->floor = 0;
	datas->ceiling = 0;
	datas->doubles = 0;
	line = get_next_line(fd);
	return (line);
}

void	ft_find_doubles_util(int *check, t_orient *data)
{
	if (*check == 1)
		data->doubles = 1;
	else
		*check = 1;
}

int	ft_find_doubles(int fd)
{
	char				*line;
	t_orient	check;

	line = init_check(&check, fd);
	while (line)
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
			ft_find_doubles_util(&check.north, &check);
		else if (ft_strncmp(line, "SO ", 3) == 0)
			ft_find_doubles_util(&check.south, &check);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			ft_find_doubles_util(&check.west, &check);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			ft_find_doubles_util(&check.east, &check);
		else if (ft_strncmp(line, "F ", 2) == 0)
			ft_find_doubles_util(&check.floor, &check);
		else if (ft_strncmp(line, "C ", 2) == 0)
			ft_find_doubles_util(&check.ceiling, &check);
		free(line);
		if (check.doubles == 1)
			return (0);
		line = get_next_line(fd);
	}
	return (close(fd) + 1);
}
