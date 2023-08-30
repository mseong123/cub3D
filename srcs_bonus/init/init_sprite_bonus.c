/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <melee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:47:11 by melee             #+#    #+#             */
/*   Updated: 2023/08/30 18:33:34 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_sprite(t_sprite *sprite)
{
	sprite->posx = 0;
	sprite->posy = 0;
	sprite->spritex = 0;
	sprite->spritey = 0;
	sprite->invdet = 0;
	sprite->transformx = 0;
	sprite->transformy = 0;
	sprite->spritescreenx = 0;
	sprite->spriteheight = 0;
	sprite->spritewidth = 0;
	sprite->drawstarty = 0;
	sprite->drawendy = 0;
	sprite->drawstartx = 0;
	sprite->drawendx = 0;
	sprite->vmovescreen = 0;
	sprite->i = 0;
	sprite->tick = 0;
	sprite->stepy = 0;
	sprite->texpos = 0;
	sprite->texx = 0;
	sprite->texy = 0;
	sprite->dir_index = 0;
}
