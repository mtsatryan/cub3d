#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_all	*s;

	if (argc != 2)
		return (write(2, "Error!\nNot the right amount of Arguments!\n", 43));
	s = init(argv[1]);
	if (s == NULL)
		return (1);
	render(s);
	mlx_hook(s->win, ON_DESTROY, 0, ft_close, s);
	mlx_hook(s->win, ON_KEYDOWN, 0, keyhandler, s);
	mlx_loop(s->mlx);
	return (0);
}
