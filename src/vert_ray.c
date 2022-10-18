/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:44:38 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/14 16:27:36 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

static void	tst(t_cub *cub, int x, int y)
{
	cub->cs.x_to_check = x;
	if (cub->cs.is_ray_facing_up)
		cub->cs.y_to_check = y + -1;
	else
		cub->cs.y_to_check = y + 1;
}

static void	vert_ray_start(t_cub *cub)
{
	float	next_horz_touch_x;
	float	next_horz_touch_y;

	next_horz_touch_x = cub->cs.xintercept;
	next_horz_touch_y = cub->cs.yintercept;
	cub->cs.map_x = cub->s_map[0] * TILE_SIZE;
	cub->cs.map_y = cub->s_map[1] * TILE_SIZE;
	while (next_horz_touch_x >= 0 && next_horz_touch_x <= cub->cs.map_x
		&& next_horz_touch_y >= 0 && next_horz_touch_y <= cub->cs.map_y)
	{
		tst(cub, next_horz_touch_x, next_horz_touch_y);
		if (is_it_hitt_wall(cub, cub->cs.x_to_check, cub->cs.y_to_check))
		{
			cub->cs.horz_wall_hit_x = next_horz_touch_x;
			cub->cs.horz_wall_hit_y = next_horz_touch_y;
			cub->cs.fod_hoz_wall_hit = TRUE;
			break ;
		}
		else
		{
			next_horz_touch_x += cub->cs.xstep;
			next_horz_touch_y += cub->cs.ystep;
		}
	}
}

void	vert_ray_init(t_cub *cub, float *ray_angle)
{
	cast_ray_init(cub);
	*ray_angle = normalize_angle(*ray_angle);
	if (*ray_angle > 0)
		cub->cs.is_ray_facing_down = *ray_angle < PI;
	cub->cs.is_ray_facing_up = !cub->cs.is_ray_facing_down;
	if ((*ray_angle < 0.5 * PI) || (*ray_angle > (1.5 * PI)))
		cub->cs.is_ray_facing_right = 1;
	else
		cub->cs.is_ray_facing_right = 0;
	cub->cs.is_ray_facing_left = !cub->cs.is_ray_facing_right;
	cub->cs.yintercept = floor(cub->py / TILE_SIZE) * TILE_SIZE;
	if (cub->cs.is_ray_facing_down)
		cub->cs.yintercept += TILE_SIZE;
	cub->cs.xintercept = cub->px
		+ (cub->cs.yintercept - cub->py) / tan(*ray_angle);
	cub->cs.ystep = TILE_SIZE;
	if (cub->cs.is_ray_facing_up)
		cub->cs.ystep *= -1;
	cub->cs.xstep = TILE_SIZE / tan(*ray_angle);
	if (cub->cs.is_ray_facing_left && cub->cs.xstep > 0)
		cub->cs.xstep *= -1;
	if (cub->cs.is_ray_facing_right && cub->cs.xstep < 0)
			cub->cs.xstep *= -1;
	vert_ray_start(cub);
}
