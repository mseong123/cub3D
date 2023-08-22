#include "cub3d.h"

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 13)
		up(data);
	else if (keycode == 0)
		left(data);
	else if (keycode == 2)
		right(data);
	else if (keycode == 1)
		down(data);
	else if (keycode == 123)
		rotate_left(data);
	else if (keycode == 124)
		rotate_right(data);
	else if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int	handle_destroy(t_data *data)
{
	(void)data;
	exit(EXIT_SUCCESS);
	return (0);
}