#include "../../includes/cub3d.h"

static int	get_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 87);
	return (c - 55);
}

int	ft_hextoi(char	*hex)
{
	int		i;
	int		sign;
	int		out;

	i = 0;
	sign = 1;
	out = 0;
	while (hex[i] == 32 || (hex[i] > 8 && hex[i] < 14))
		i++;
	if (hex[i] == '+' || hex[i] == '-')
		sign = (hex[i++] - 44) * -1;
	while ((hex[i] >= '0' && hex[i] <= '9') || (hex[i] >= 'a' && hex[i] <= 'f')
		|| (hex[i] >= 'A' && hex[i] <= 'F'))
		out = (out * 16) + get_value(hex[i++]);
	return (out * sign);
}

void	ft_add_newline(char **map)
{
	int		i;
	char	*out;
	int		len;

	i = 0;
	while (map[i])
		i++;
	i--;
	out = ft_calloc(sizeof(char), ft_strlen(map[i]) + 3);
	ft_strlcpy(out, map[i], ft_strlen(map[i]) + 1);
	len = ft_strlen(map[i]);
	free(map[i]);
	map[i] = out;
	map[i][len] = '\n';
}
