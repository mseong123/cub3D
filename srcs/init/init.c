#include "cub3d.h"

void	init_ray(t_ray *ray)
{
	ray->dirX = -1;
	ray->dirY = 0;
	ray->planeX = 0;
	ray->planeY = -0.66;
	ray->rayX = 0;
	ray->rayY = 0;
	ray->deltaX = 0;
	ray->deltaY = 0;
	ray->sideX = 0;
	ray->sideY = 0;
	ray->perpDist = 0;
	ray->mapX = 0;
	ray->mapY = 0;
	ray->side = 0;
	ray->hit = 0;
	ray->stepX = 0;
	ray->stepY = 0;
	ray->drawStart = 0;
	ray->drawEnd = 0;
}

void	init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		perror("cub3d");
		exit(EXIT_FAILURE);
	}
	data->mlx_win = mlx_new_window(data->mlx_ptr, \
	W_WIDTH, W_HEIGHT, "cub3d");
	if (!data->mlx_win)
	{
		perror("cub3d");
		exit(EXIT_FAILURE);
	}
	data->player->posX = 5;
	data->player->posY = 5;
	init_image(data, data->camera, W_WIDTH, W_HEIGHT);
	init_ray(data->ray);

}

