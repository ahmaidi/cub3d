/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 20:38:14 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/10/14 01:05:58 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

int	exit_game(t_cub *cub)
{
	int	i;

	mlx_destroy_image(cub->mlx, cub->image->ea);
	mlx_destroy_image(cub->mlx, cub->image->so);
	mlx_destroy_image(cub->mlx, cub->image->we);
	mlx_destroy_image(cub->mlx, cub->image->no);
	mlx_destroy_window(cub->mlx, cub->win);
	i = -1;
	while (cub->map[++i])
		free_it(cub->map[i]);
	free(cub->image);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	key_rotate_right(t_cub *cub)
{
	cub->player->turndirection = 1;
	update_image(cub);
}

void	key_rotate_left(t_cub *cub)
{
	cub->player->turndirection = -1;
	update_image(cub);
}

int	deal_key(int key, t_cub *cub)
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
