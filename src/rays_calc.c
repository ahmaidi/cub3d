/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:55:20 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/14 16:37:48 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

float	normalize_angle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	float	tmp;

	tmp = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return (tmp);
}

static void	tst(t_cub *cub, int stripl, float vhd, float hhd)
{
	if (vhd < hhd)
	{
		cub->ray[stripl].distance = vhd;
		cub->ray[stripl].wall_hit_x = cub->cs.vert_wall_hit_x;
		cub->ray[stripl].wall_hit_y = cub->cs.vert_wall_hit_y;
		cub->ray[stripl].was_hit_vertical = TRUE;
	}
	else
	{
		cub->ray[stripl].distance = hhd;
		cub->ray[stripl].wall_hit_x = cub->cs.horz_wall_hit_x;
		cub->ray[stripl].wall_hit_y = cub->cs.horz_wall_hit_y;
		cub->ray[stripl].was_hit_vertical = FALSE;
	}
	cub->ray[stripl].is_ray_facing_no = cub->cs.is_ray_facing_down;
	cub->ray[stripl].is_ray_facing_so = cub->cs.is_ray_facing_up;
	cub->ray[stripl].is_ray_facing_we = cub->cs.is_ray_facing_left;
	cub->ray[stripl].is_ray_facing_ea = cub->cs.is_ray_facing_right;
}

void	cast_ray(t_cub *cub, float ray_angle, int stripl)
{
	float	horz_hit_distance;
	float	vert_hit_distance;

	vert_ray_init(cub, &ray_angle);
	horz_ray_init(cub, &ray_angle);
	if (cub->cs.fod_hoz_wall_hit)
		horz_hit_distance = distance_between_points(cub->px, cub->py,
				cub->cs.horz_wall_hit_x, cub->cs.horz_wall_hit_y);
	else
		horz_hit_distance = FLT_MAX;
	if (cub->cs.fod_vert_wall_hit)
		vert_hit_distance = distance_between_points(
				cub->px, cub->py, cub->cs.vert_wall_hit_x,
				cub->cs.vert_wall_hit_y);
	else
		vert_hit_distance = FLT_MAX;
	tst(cub, stripl, vert_hit_distance, horz_hit_distance);
	cub->ray[stripl].ray_angle = ray_angle;
}
