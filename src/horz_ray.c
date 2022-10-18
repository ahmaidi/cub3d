/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horz_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:44:42 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/15 14:10:43 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

static void	tst(t_cub *cub, int x, int y)
{
	if (cub->cs.is_ray_facing_left)
		cub->cs.x_to_check = x + -1;
	else
		cub->cs.x_to_check = x + 1;
	cub->cs.y_to_check = y ;
}

static void	horz_ray_start(t_cub *cub)
{
	float	next_vert_touch_x;
	float	next_vert_touch_y;

	next_vert_touch_x = cub->cs.xintercept;
	next_vert_touch_y = cub->cs.yintercept;
	while (next_vert_touch_x >= 0 && next_vert_touch_x <= cub->cs.map_x
		&& next_vert_touch_y >= 0 && next_vert_touch_y <= cub->cs.map_y)
	{
		tst(cub, next_vert_touch_x, next_vert_touch_y);
		if (is_it_hitt_wall(cub, cub->cs.x_to_check, cub->cs.y_to_check))
		{
			cub->cs.vert_wall_hit_x = next_vert_touch_x;
			cub->cs.vert_wall_hit_y = next_vert_touch_y;
			cub->cs.fod_vert_wall_hit = TRUE;
			break ;
		}
		else
		{
			next_vert_touch_x += cub->cs.xstep;
			next_vert_touch_y += cub->cs.ystep;
		}
	}
}

void	horz_ray_init(t_cub *cub, float *ray_angle)
{
	cub->cs.xintercept = floor(cub->px / TILE_SIZE) * TILE_SIZE;
	if (cub->cs.is_ray_facing_right)
		cub->cs.xintercept += TILE_SIZE;
	cub->cs.yintercept = cub->py
		+ (cub->cs.xintercept - cub->px) * tan(*ray_angle);
	cub->cs.xstep = TILE_SIZE;
	if (cub->cs.is_ray_facing_left)
		cub->cs.xstep *= -1;
	cub->cs.ystep = TILE_SIZE * tan(*ray_angle);
	if (cub->cs.is_ray_facing_up && cub->cs.ystep > 0)
		cub->cs.ystep *= -1;
	if (cub->cs.is_ray_facing_down && cub->cs.ystep < 0)
		cub->cs.ystep *= -1;
	horz_ray_start(cub);
}
