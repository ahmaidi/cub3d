/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:33:51 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/14 16:31:31 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

int	is_it_hitt_wall(t_cub *cub, float x, float y)
{
	int	index_x;
	int	index_y;

	index_y = floor(y / TILE_SIZE);
	index_x = floor(x / TILE_SIZE);
	if (index_y < 0 || index_y < 0)
		return (0);
	if (cub->map[index_y][index_x] != '0' && cub->map[index_y][index_x] != 'N'
		&& cub->map[index_y][index_x] != 'S'
		&& cub->map[index_y][index_x] != 'W'
		&& cub->map[index_y][index_x] != 'E')
		return (1);
	return (0);
}

static void	set_player_bo(t_cub *cub)
{
	int	player_size;
	int	player_color;
	int	i[2];

	player_size = 2;
	player_color = 11605993;
	i[0] = -1;
	while (++i[0] < player_size)
	{
		i[1] = -1;
		while (++i[1] < player_size)
			mlx_pixel_put(cub->mlx, cub->win,
				cub->px + i[0], cub->py + i[1], player_color);
	}
}

static void	set_player_info_bo(t_cub *cub, int *coord_i)
{
	cub->playerside = cub->map[coord_i[1]][coord_i[0]];
	if (!cub->px && !cub->py)
	{
		cub->px = (TILE_SIZE * coord_i[0]) + TILE_SIZE / 2;
		cub->py = (TILE_SIZE * coord_i[1]) + TILE_SIZE / 2;
	}
}

void	set_map_bo(t_cub *cub, int mode)
{
	int		coord_i[2];

	coord_i[0] = 0;
	while (coord_i[0] < cub->s_map[0])
	{
		coord_i[1] = 0;
		while (coord_i[1] < cub->s_map[1])
		{
			if (cub->map[coord_i[1]][coord_i[0]] != '+'
				&& cub->map[coord_i[1]][coord_i[0]] != ' '
				&& cub->map[coord_i[1]][coord_i[0]] != '1'
				&& cub->map[coord_i[1]][coord_i[0]] != '0')
				set_player_info_bo(cub, coord_i);
			coord_i[1]++;
		}
		coord_i[0]++;
	}
}
