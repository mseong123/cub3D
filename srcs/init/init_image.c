#include "cub3d.h"

void	init_image(t_data *data, t_img *img, int width, int height)
{
	img->mlx_img = mlx_new_image(data->mlx_ptr, width, height);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian);
}


