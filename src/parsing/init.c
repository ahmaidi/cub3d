/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 09:26:45 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/14 16:30:50 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game_action.h"

void	cast_ray_init(t_cub *cub)
{
	cub->cs.fod_vert_wall_hit = FALSE;
	cub->cs.vert_wall_hit_x = 0;
	cub->cs.vert_wall_hit_y = 0;
	cub->cs.xintercept = 0;
	cub->cs.yintercept = 0;
	cub->cs.xstep = 0;
	cub->cs.ystep = 0;
	cub->cs.is_ray_facing_down = 0;
	cub->cs.is_ray_facing_up = 0;
	cub->cs.is_ray_facing_right = 0;
	cub->cs.is_ray_facing_left = 0;
	cub->cs.fod_hoz_wall_hit = FALSE;
	cub->cs.horz_wall_hit_x = 0;
	cub->cs.horz_wall_hit_y = 0;
}

static void	ray_init(t_cub *cub)
{
	int	i;

	cast_ray_init(cub);
	cub->player->turnspeed = 10 * (PI / 180);
	cub->mouse_old = 0;
	cub->player->walkspeed = 15;
	i = -1;
	while (++i < NUM_RAYS)
	{
		cub->ray[i].ray_angle = 0;
		cub->ray[i].distance = 0;
		cub->ray[i].was_hit_vertical = 0;
		cub->ray[i].is_ray_facing_no = 0;
		cub->ray[i].is_ray_facing_so = 0;
		cub->ray[i].is_ray_facing_we = 0;
		cub->ray[i].is_ray_facing_ea = 0;
	}
}

t_cub	*cub_init(void)
{
	t_cub		*c;

	c = var_init(sizeof(t_cub));
	c->player = var_init(sizeof(t_player));
	c->image = var_init(sizeof(t_image));
	c->tab_txt_c = NULL;
	c->map = NULL;
	c->size_tab = 0;
	c->size_map = 0;
	c->in_map = 0;
	c->is_player = 0;
	c->px = 0;
	c->py = 0;
	c->player->turndirection = 0;
	c->player->walkdirection = 0;
	c->player->rotationangle = PI / 2;
	c->player->turnleft = 0;
	ray_init(c);
	return (c);
}
