/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <melee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:47:01 by melee             #+#    #+#             */
/*   Updated: 2023/08/30 18:37:41 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_sprite_value1(t_data *data)
{
	if (data->sprite.drawstarty < 0)
		data->sprite.drawstarty = 0;
	data->sprite.drawendy = (data->sprite.spriteheight / 2) + \
	(W_HEIGHT / 2) + data->sprite.vmovescreen;
	if (data->sprite.drawendy >= W_HEIGHT)
		data->sprite.drawendy = W_HEIGHT - 1;
	data->sprite.spritewidth = abs((int)(W_HEIGHT / \
	(data->sprite.transformy))) / UDIV;
	data->sprite.drawstartx = (-data->sprite.spritewidth / 2) + \
	data->sprite.spritescreenx;
	if (data->sprite.drawstartx < 0)
		data->sprite.drawstartx = 0;
	data->sprite.drawendx = (data->sprite.spritewidth / 2) + \
	data->sprite.spritescreenx;
	if (data->sprite.drawendx >= W_WIDTH)
		data->sprite.drawendx = W_WIDTH - 1;
}

void	set_sprite_value(t_data *data)
{
	data->sprite.spritex = data->sprite.posx - data->player.posx;
	data->sprite.spritey = data->sprite.posy - data->player.posy;
	data->sprite.invdet = 1.0 / ((data->ray.planex * data->ray.diry) - \
	(data->ray.dirx * data->ray.planey));
	data->sprite.transformx = data->sprite.invdet * \
	((data->ray.diry * data->sprite.spritex) - (data->ray.dirx * \
	data->sprite.spritey));
	data->sprite.transformy = data->sprite.invdet * \
	((-data->ray.planey * data->sprite.spritex) + \
	(data->ray.planex * data->sprite.spritey));
	data->sprite.spritescreenx = (int)((W_WIDTH / 2) * \
	(1 + data->sprite.transformx / data->sprite.transformy));
	data->sprite.spriteheight = abs((int)(W_HEIGHT / \
	(data->sprite.transformy))) / VDIV;
	data->sprite.vmovescreen = (int) VMOVE / data->sprite.transformy;
	data->sprite.drawstarty = (-data->sprite.spriteheight / 2) + \
	(W_HEIGHT / 2) + data->sprite.vmovescreen;
	set_sprite_value1(data);
}

void	draw_sprite_y(t_data *data, int x)
{
	int			y;
	uint32_t	*s_img_addr;
	uint32_t	color;

	if (data->sprite.transformy > 0 && x > 0 && \
	x < W_WIDTH && data->sprite.transformy < data->sprite.zbuffer[x])
	{
		y = data->sprite.drawstarty;
		data->sprite.stepy = 1.0 * S_HEIGHT / data->sprite.spriteheight;
		data->sprite.texpos = (y - data->sprite.vmovescreen - \
		W_HEIGHT / 2 + data->sprite.spriteheight / 2) * data->sprite.stepy;
		while (y < data->sprite.drawendy)
		{
			data->sprite.texy = data->sprite.texpos;
			data->sprite.texpos += data->sprite.stepy;
			s_img_addr = (uint32_t *)(data->sprite.sprite_img[data-> \
			sprite.i].addr + ((data->sprite.texy * data->sprite \
			.sprite_img[data->sprite.i].line_len) + (data->sprite.texx * \
			(data->sprite.sprite_img[data->sprite.i].bpp / 8))));
			color = *s_img_addr;
			if ((color & 0x00FFFFFF) != 0)
				img_pix_put(&data->camera, x, y, color);
			y++;
		}
	}
}

void	draw_sprite(t_data *data)
{
	int	x;

	set_sprite_value(data);
	x = data->sprite.drawstartx;
	while (x < data->sprite.drawendx)
	{
		data->sprite.texx = ((x - ((-data->sprite.spritewidth / 2) + \
		(data->sprite.spritescreenx))) * ((double)S_WIDTH / \
		(double)data->sprite.spritewidth));
		draw_sprite_y(data, x);
		x++;
	}
}
