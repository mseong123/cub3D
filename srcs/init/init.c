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
	ray->lineHeight = 0;
}

void	init_player(t_player *player)
{
	player->posX = 5;
	player->posY = 5;
	player->forward = false;
	player->backward = false;
	player->left = false;
	player->right = false;
	player->rot_left = false;
	player->rot_right = false;
}

void	init_texture(t_tex *texture)
{
	texture->texX = 0;
	texture->step = 0;
	texture->texPos = 0;
}

// added booleans for player
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
	data->c_fps = ft_strdup("0");
	data->frames = 0;
	gettimeofday(&data->frame_start, NULL);
	data->ceil_color = 0x73a5c6;
	data->floor_color = 0x2e5984;
	init_player(&data->player);
	init_ray(&data->ray);
	init_texture(&data->texture);
}

