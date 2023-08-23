#include "cub3d.h"

void	set_raycast_values(t_data *data, int x)
{
	double cameraX;

	cameraX = 2 * x / (double)W_WIDTH - 1;
	data->ray.rayX = data->ray.dirX + (data->ray.planeX * cameraX);
	data->ray.rayY = data->ray.dirY + (data->ray.planeY * cameraX);
	data->ray.mapX = (int)data->player.posX;
	data->ray.mapY = (int)data->player.posY;
	data->ray.deltaX = fabs(1 / data->ray.rayX);
	data->ray.deltaY = fabs(1 / data->ray.rayY);
}

void	calc_init_side(t_data *data)
{
	if (data->ray.rayX < 0)
	{
		data->ray.stepX = -1;
		data->ray.sideX = (data->player.posX - data->ray.mapX) * data->ray.deltaX;
	}
	else
	{
		data->ray.stepX = 1;
		data->ray.sideX = (data->ray.mapX + 1.0 - data->player.posX) * data->ray.deltaX;
	}
	if (data->ray.rayY < 0)
	{
		data->ray.stepY = -1;
		data->ray.sideY = (data->player.posY - data->ray.mapY) * data->ray.deltaY;
	}
	else
	{
		data->ray.stepY = 1;
		data->ray.sideY = (data->ray.mapY + 1.0 - data->player.posY) * data->ray.deltaY;
	}
}

void	dda(t_data *data)
{
	int hit;
	
	hit = 0;
	while (hit == 0)
	{
		if (data->ray.sideX < data->ray.sideY)
		{
			data->ray.sideX += data->ray.deltaX;
			data->ray.mapX += data->ray.stepX;
			data->ray.side = 0;
			
		}
		else
		{
			data->ray.sideY += data->ray.deltaY;
			data->ray.mapY += data->ray.stepY;
			data->ray.side = 1;
		}
		if (data->map[data->ray.mapY][data->ray.mapX] == '1')
			hit = 1;
	}
	if (data->ray.side == 0)
		data->ray.perpDist = data->ray.sideX - data->ray.deltaX;
    else
		data->ray.perpDist = data->ray.sideY - data->ray.deltaY;
	
}

void	cal_height(t_data *data)
{
	int lineHeight;
	
	lineHeight = (int)(W_HEIGHT / data->ray.perpDist);
	data->ray.lineHeight = lineHeight;
	data->ray.drawStart = -lineHeight / 2 + W_HEIGHT / 2;
    if(data->ray.drawStart < 0)
		data->ray.drawStart = 0;
	data->ray.drawEnd = lineHeight / 2 + W_HEIGHT / 2;
    if(data->ray.drawEnd >= W_HEIGHT)
		data->ray.drawEnd = W_HEIGHT - 1;
}
