#include "cub3d.h"

void	up(t_data *data)
{
	if(data->map[(int)data->player.posY][(int)(data->player.posX + data->ray.dirX * MOVESPEED)] == '0')
		data->player.posX += data->ray.dirX * MOVESPEED;
    if(data->map[(int)(data->player.posY + data->ray.dirY * MOVESPEED)][(int)data->player.posX] == '0') 
		data->player.posY += data->ray.dirY * MOVESPEED;
}

void	down(t_data *data)
{
	if(data->map[(int)data->player.posY][(int)(data->player.posX - data->ray.dirX * MOVESPEED)] == '0')
		data->player.posX -= data->ray.dirX * MOVESPEED;
    if(data->map[(int)(data->player.posY - data->ray.dirY * MOVESPEED)][(int)data->player.posX] == '0') 
		data->player.posY -= data->ray.dirY * MOVESPEED;
}

void	left(t_data *data)
{
	if(data->map[(int)data->player.posY][(int)(data->player.posX + data->ray.dirY * MOVESPEED)] == '0')
		data->player.posX += data->ray.dirY * MOVESPEED;
    if(data->map[(int)(data->player.posY - data->ray.dirX * MOVESPEED)][(int)data->player.posX] == '0') 
		data->player.posY -= data->ray.dirX * MOVESPEED;
}

void	right(t_data *data)
{
	if(data->map[(int)data->player.posY][(int)(data->player.posX - data->ray.dirY * MOVESPEED)] == '0')
		data->player.posX -= data->ray.dirY * MOVESPEED;
    if(data->map[(int)(data->player.posY + data->ray.dirX * MOVESPEED)][(int)data->player.posX] == '0') 
		data->player.posY += data->ray.dirX * MOVESPEED;
}
