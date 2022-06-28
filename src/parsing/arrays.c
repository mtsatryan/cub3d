#include "../../includes/cub3d.h"

void	print_arr(char	**arr, int fd)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i] != NULL)
		{
			ft_putstr_fd(arr[i], fd);
			if (arr[i][ft_strlen(arr[i]) - 1] != '\n')
				ft_putstr_fd("\'\n", fd);
			else
				ft_putstr_fd("\'", fd);
			i++;
		}
	}
}

void	ft_free_arr_char(char	**arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i] != NULL)
		{
			free(arr[i]);
			i++;
		}
	}
	free(arr);
}

int	ft_message_int(char *line, int err)
{
	write(2, "Error!\n", 8);
	if (err == 1)
		perror(line);
	else
		write(2, line, ft_strlen(line));
	return (0);
}

char	**ft_stradd(char **arr, char *new_el)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	while (arr[i])
		i++;
	temp = ft_calloc((sizeof(char *)), i + 2);
	j = 0;
	while (arr[j])
	{
		temp[j] = arr[j];
		j++;
	}
	temp[j] = new_el;
	free(arr);
	return (temp);
}

void	ft_free_arr_int(int **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
