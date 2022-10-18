/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:13:43 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/14 01:08:28 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

void	key_w_s(t_cub *cub, int i)
{
	cub->player->walkdirection = i;
	update_image(cub);
}

void	key_a(t_cub *cub)
{
	cub->player->walkdirection = 1;
	cub->player->turnleft = PI / 2;
	update_image(cub);
}

void	key_d(t_cub *cub)
{
	cub->player->walkdirection = -1;
	cub->player->turnleft = PI / 2;
	update_image(cub);
}

void	key_rotate(t_cub *cub, int i)
{
	cub->player->turndirection = i;
	update_image(cub);
}
