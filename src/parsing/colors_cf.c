#include "../../includes/cub3d.h"

int	check_rgb_util_2(char *line, int i, int j)
{
	char	*temp;

	temp = ft_substr(line, j, i - j);
	if (ft_atoi(temp) > 255 || ft_atoi(temp) < 0)
	{
		free(temp);
		return (-1);
	}
	free(temp);
	return (1);
}

int	check_rgb_util(char *line, int i)
{
	int		j;
	int		y;

	y = 0;
	while (line[i])
	{
		j = i;
		while (ft_isdigit(line[i]))
			i++;
		if (i - j > 3 || i - j < 1)
			return (-1);
		if (check_rgb_util_2(line, i, j) == -1)
			return (-1);
		if (line[i] == 0 || line[i] == '\n')
			break ;
		if (y < 2 && line[i] != ',')
			return (-1);
		i++;
		y++;
	}
	return (y);
}

int	check_rgb(char *line)
{
	int		i;
	int		y;

	i = 1;
	y = 0;
	while (line[i] == ' ')
		i++;
	if (i - y == 0)
		return (0);
	y = check_rgb_util(line, i);
	if (y != 2)
		return (0);
	return (1);
}

int	ft_get_paint(char *line)
{
	int		i;
	int		j;
	int		y;
	char	*temp;
	int		rgb;

	i = 1;
	rgb = 0;
	y = 2;
	while (line[i] && y >= 0)
	{
		while (line[i] == ' ')
			i++;
		j = i;
		while (ft_isdigit(line[i]))
			i++;
		if (i - j - 1 > 2)
			return (0);
		temp = ft_substr(line, j, i - j);
		rgb = (ft_atoi(temp) * pow(256, y)) + rgb;
		free(temp);
		i++;
		y--;
	}
	return (rgb);
}

int	set_colors_cf(char *line, t_all *s)
{
	if (line[0] == 'F')
	{
		if (s->_f != -1)
			return (ft_message_int("Multiple floor colours\n", 0));
		if (check_rgb(line) == 0)
			return (ft_message_int("Floor colour is \
not formatted right!\n", 0));
		s->_f = ft_get_paint(line);
		if (s->_f < 0)
			return (0);
	}
	else if (line[0] == 'C')
	{
		if (s->_c != -1)
			return (ft_message_int("Multiple ceiling colours\n", 0));
		if (check_rgb(line) == 0)
			return (ft_message_int("Ceiling colour \
is not formatted right!\n", 0));
		s->_c = ft_get_paint(line);
		if (s->_c < 0)
			return (0);
	}
	return (1);
}
