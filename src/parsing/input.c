#include "../../includes/cub3d.h"

int	ft_read_input(t_all *s, int fd)
{
	char	*l;
	int		i;

	i = 0;
	l = get_next_line(fd);
	while (l && i < 6)
	{
		if ((l[0] == 'N' || l[0] == 'E' || l[0] == 'S' || l[0] == 'W') && ++i)
		{
			if (xpm_to_int(l, l[0], s) == 0)
				return (free_str(l));
		}
		else if ((l[0] == 'F' || l[0] == 'C') && ++i)
		{
			if (set_colors_cf(l, s) == 0)
				return (free_str(l));
		}
		else if (ft_strlen(l) > 1)
			return (free_str(l));
		free(l);
		if (i == 6)
			break ;
		l = get_next_line(fd);
	}
	return (i);
}

char	*ft_fill_spaces_util(char	*line, int size, char *out, int i)
{
	if ((int)ft_strlen(line) > size)
	{
		line[size] = 0;
		return (line);
	}
	else if ((int)ft_strlen(line) == size)
	{
		if (line[size - 1] != '\n')
			return (line);
		line[size -1] = ' ';
		line[size] = '\0';
		return (line);
	}
	else
	{
		out = ft_calloc(sizeof(char), size + 1);
		ft_strlcpy(out, line, size);
		i = ft_strlen(out) - 1;
		if (line[i] != '\n')
			i++;
		while (i < size)
			out[i++] = ' ';
		free(line);
		return (out);
	}
}

void	ft_fill_spaces(char **map)
{
	int	x;
	int	i;
	int	len;

	i = 0;
	x = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > x)
			x = len;
		i++;
	}
	i = 0;
	x -= 1;
	while (map[i])
	{
		map[i] = ft_fill_spaces_util(map[i], x, "", 0);
		i++;
	}
}

int	ft_read_map(int fd, t_all *s)
{
	char	*line;
	char	**map;

	line = get_next_line(fd);
	map = ft_calloc(sizeof(char *), 1);
	while (line && ft_strlen(line) == 1)
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		map = ft_stradd(map, line);
		line = get_next_line(fd);
	}
	ft_add_newline(map);
	ft_fill_spaces(map);
	s->map = map;
	if (check_chars(map) == 0)
		return (ft_message_int("Illegal Characters.\n", 0));
	if (ft_check_surround_v(map) == 0)
		return (ft_message_int("Map isn't enclosed vertically.\n", 0));
	if (ft_check_surround_h(map) == 0)
		return (ft_message_int("Map isn't enclosed\
 horizontally.\n", 0));
	return (1);
}

int	get_input(t_all *s, char *path_name)
{
	int	fd;

	if (ft_strncmp(path_name + ft_strlen(path_name) - 4, ".cub", 5))
		return (ft_message_int("Argument is not a \".cub\" file\n", 0));
	fd = open(path_name, O_RDONLY);
	if (fd < 0)
		return (ft_message_int(path_name, 1));
	if (ft_find_doubles(fd) == 0)
		return (ft_message_int
			("Too many things in .cub file\n", 0));
	fd = open(path_name, O_RDONLY);
	if (fd < 0)
		return (ft_message_int(path_name, 1));
	if (ft_read_input(s, fd) != 6)
		return (ft_message_int
			("Not enough Textures &/ floor/ceiling colour\n", 0));
	if (ft_read_map(fd, s) == 0)
		return (0);
	return (1);
}
