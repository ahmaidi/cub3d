/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:04:58 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/14 16:33:24 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/part_bonus.h"

int	mouse_mouve(int x, int y, t_cub *cub)
{
	cub->player->turnspeed = (PI / 180);
	if ((x >= 0 && x <= WIN_W) && (y >= 0 && y <= WIN_H))
	{
		if (x > cub->mouse_old)
			key_rotate(cub, 1);
		else if (x < cub->mouse_old)
			key_rotate(cub, -1);
	}
	cub->mouse_old = x;
	cub->player->turnspeed = 10 * (PI / 180);
	return (0);
}

int	deal_key_bo(int key, t_cub *cub)
{
	if (key == 53)
		exit_game(cub);
	if (key == UP_KEY)
		key_w_s(cub, 1);
	if (key == DOWN_KEY)
		key_w_s(cub, -1);
	if (key == LEFT_KEY)
		key_d(cub);
	if (key == RIGHT_KEY)
		key_a(cub);
	if (key == R_ARROW_KEY)
		key_rotate(cub, 1);
	if (key == L_ARROW_KEY)
		key_rotate(cub, -1);
	cub->player->turndirection = 0;
	cub->player->walkdirection = 0;
	cub->player->turnleft = 0;
	return (EXIT_SUCCESS);
}
