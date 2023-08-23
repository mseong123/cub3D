#include "cub3d.h"

void	init_image(t_data *data, t_img *img, int width, int height)
{
	img->mlx_img = mlx_new_image(data->mlx_ptr, width, height);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian);
}

void	init_tex(t_data *data)
{
	int height;
	int width;

	data->tex[NORTH].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/brick1.xpm", &width, &height);
	data->tex[NORTH].addr = mlx_get_data_addr(data->tex[NORTH].mlx_img, &data->tex[NORTH].bpp, &data->tex[NORTH].line_len, &data->tex[NORTH].endian);
	data->tex[SOUTH].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/brick2.xpm", &width, &height);
	data->tex[SOUTH].addr = mlx_get_data_addr(data->tex[SOUTH].mlx_img, &data->tex[SOUTH].bpp, &data->tex[SOUTH].line_len, &data->tex[SOUTH].endian);
	data->tex[EAST].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/brick3.xpm", &width, &height);
	data->tex[EAST].addr = mlx_get_data_addr(data->tex[EAST].mlx_img, &data->tex[EAST].bpp, &data->tex[EAST].line_len, &data->tex[EAST].endian);
	data->tex[WEST].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/brick4.xpm", &width, &height);
	data->tex[WEST].addr = mlx_get_data_addr(data->tex[WEST].mlx_img, &data->tex[WEST].bpp, &data->tex[WEST].line_len, &data->tex[WEST].endian);
}


