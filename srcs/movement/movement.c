#include "cub3d.h"

void	up(t_data *data)
{
	if(data->map[(int)(data->player->posX + data->ray->dirX * MOVESPEED)][(int)data->player->posY] == '0')
		data->player->posX += data->ray->dirX * MOVESPEED;
    if(data->map[(int)data->player->posX][(int)(data->player->posY + data->ray->dirY * MOVESPEED)] == '0') 
		data->player->posY += data->ray->dirY * MOVESPEED;
	render_frame(data);
}

void	down(t_data *data)
{
	if(data->map[(int)(data->player->posX - data->ray->dirX * MOVESPEED)][(int)data->player->posY] == '0')
		data->player->posX -= data->ray->dirX * MOVESPEED;
    if(data->map[(int)data->player->posX][(int)(data->player->posY - data->ray->dirY * MOVESPEED)] == '0') 
		data->player->posY -= data->ray->dirY * MOVESPEED;
	render_frame(data);
}

void	left(t_data *data)
{
	if(data->map[(int)(data->player->posX + data->ray->dirY * MOVESPEED)][(int)data->player->posY] == '0')
		data->player->posX += data->ray->dirY * MOVESPEED;
    if(data->map[(int)data->player->posX][(int)(data->player->posY - data->ray->dirX * MOVESPEED)] == '0') 
		data->player->posY -= data->ray->dirX * MOVESPEED;
	render_frame(data);
}

void	right(t_data *data)
{
	if(data->map[(int)(data->player->posX - data->ray->dirY * MOVESPEED)][(int)data->player->posY] == '0')
		data->player->posX -= data->ray->dirY * MOVESPEED;
    if(data->map[(int)data->player->posX][(int)(data->player->posY + data->ray->dirX * MOVESPEED)] == '0') 
		data->player->posY += data->ray->dirX * MOVESPEED;
	render_frame(data);
}
