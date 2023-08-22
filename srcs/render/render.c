#include "cub3d.h"

void	img_pix_put(t_img *img, int x, int y, uint32_t color)
{
	char *pixel;

	pixel = img->addr + (img->line_len * y) + (x * (img->bpp/8));
	*(uint32_t *)pixel = color;
}

// void	fill_camera(t_data *data, int x)
// {
// 	int y;

// 	y = data->ray->drawStart;
// 	while (y < data->ray->drawEnd)
// 	{
// 		if (data->ray->side == 1)
// 			img_pix_put(data->camera, x, y, 0xFF00);
// 		else
// 			img_pix_put(data->camera, x, y, 0xFF00/2);
// 		y++;
// 	}
// }

void	clear_window(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	// while (i < W_HEIGHT * data->camera->line_len)
	// 	data->camera->addr[i++] = 0;
}

// int	render_frame(t_data *data)
// {
// 	int x;

// 	x = 0;
// 	clear_window(data);
// 	init_image(data, data->camera, W_WIDTH, W_HEIGHT);
// 	while(x < W_WIDTH)
// 	{
// 		set_raycast_values(data, x);
// 		calc_init_side(data);
// 		dda(data);
// 		cal_height(data);
// 		fill_camera(data, x);
// 		x++;
// 	}
// 	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->camera->mlx_img, 0, 0);
// 	mlx_destroy_image(data->mlx_ptr, data->camera->mlx_img);
// 	return (0);
// }

// idk how it loops here





