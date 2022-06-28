#include "../../includes/cub3d.h"

void	ft_put_in_struct(char c, int size, int **arr, t_all *s)
{
	if (c == 'N')
	{
		s->size_n = size;
		s->spot_n = arr;
	}
	else if (c == 'E')
	{
		s->size_e = size;
		s->spot_e = arr;
	}
	else if (c == 'S')
	{
		s->size_s = size;
		s->spot_s = arr;
	}
	else if (c == 'W')
	{
		s->size_w = size;
		s->spot_w = arr;
	}
}

char	*get_path(char *path)
{
	path += 2;
	while (path[0] == ' ')
		path++;
	path[ft_strlen(path) - 1] = 0;
	return (path);
}

void	ft_tex_setup(char c, t_all *s)
{
	if (c == 'N')
		s->tex_n = 1;
	else if (c == 'S')
		s->tex_s = 1;
	else if (c == 'E')
		s->tex_e = 1;
	else if (c == 'W')
		s->tex_w = 1;
}

int	xpm_to_int(char *path, char c, t_all *s)
{
	int			fd;
	char		*line;
	t_xpm	text_all;
	int			**arr;
	
	if ((c == 'N' && s->tex_n) || (c == 'S' && s->tex_s)
		|| (c == 'E' && s->tex_e) || (c == 'W' && s->tex_w))
		return (ft_message_int("Duplicated direction\n", 0));
	path = get_path(path);
	if (ft_strncmp(path + ft_strlen(path) - 4, ".xpm", 5))
		return (ft_message_int("Texture is not a .xpm File!\n", 0));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_message_int(path, 1));
	line = skip_lines(fd);
	fill_texture_size(line, &text_all);
	if (text_all.size == -1)
		return (0);
	fill_arr(&text_all, fd);
	arr = fill_texture(&text_all, fd);
	free(text_all.value);
	ft_free_arr_char(text_all.code);
	ft_put_in_struct(c, text_all.size, arr, s);
	ft_tex_setup(c, s);
	return (1);
}
