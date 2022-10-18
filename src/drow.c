/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:36:19 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/14 01:06:59 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

int	create_trgb(int *rgb)
{
	return (rgb[1] << 16 | rgb[2] << 8 | rgb[3]);
}

void	set_buffer(t_cub *c, int pixel, int color)
{
	c->layer1_buffer[pixel + 0] = (color) & 0xFF;
	c->layer1_buffer[pixel + 1] = (color >> 8) & 0xFF;
	c->layer1_buffer[pixel + 2] = (color >> 16) & 0xFF;
	c->layer1_buffer[pixel + 3] = (color >> 24);
}

void	drow_floor_and_ceilling(t_cub *c)
{
	int		index[2];
	int		pixel;

	index[0] = -1;
	while (++index[0] < WIN_H)
	{
		index[1] = -1;
		while (++index[1] < WIN_W)
		{
			pixel = (index[0] * (WIN_W * 4)) + (index[1] * 4);
			if (index[0] < (WIN_H / 2))
				set_buffer(c, pixel, c->cei);
			else
				set_buffer(c, pixel, c->flo);
		}
	}
}

void	side_of_player(t_cub *cub)
{
	if (cub->side_of_player == 'N')
		cub->player->rotationangle = (3 * PI) / 2;
	else if (cub->side_of_player == 'E')
		cub->player->rotationangle = 0;
	else if (cub->side_of_player == 'W')
		cub->player->rotationangle = PI;
	else if (cub->side_of_player == 'S')
		cub->player->rotationangle = PI / 2;
}
