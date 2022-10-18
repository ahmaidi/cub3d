/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_pjection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:37:19 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/15 14:09:12 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_action.h"

static uint32_t	get_buffer(char *texture, int offset_y, int offset_x)
{
	uint32_t	buffer;

	buffer = ((uint32_t *)texture)[(TILE_SIZE * offset_y) + offset_x];
	return (buffer);
}

static void	cub_set_buffer(t_cub *cub, int i, int y, int wsh)
{
	uint32_t	texel_color;
	int			distance_from_top;
	int			offset_y;

	texel_color = 0;
	distance_from_top = (y + (wsh / 2)) - (WIN_H / 2);
	offset_y = distance_from_top * ((float)TILE_SIZE / wsh);
	if (cub->ray[i].was_hit_vertical && (cub->px > cub->ray[i].wall_hit_x))
		texel_color = get_buffer(cub->we_buf, offset_y, cub->texture_offset);
	else if (cub->ray[i].was_hit_vertical)
		texel_color = get_buffer(cub->ea_buf, offset_y, cub->texture_offset);
	else if (!cub->ray[i].was_hit_vertical
		&& (cub->py < cub->ray[i].wall_hit_y))
		texel_color = get_buffer(cub->so_buf, offset_y, cub->texture_offset);
	else if (!cub->ray[i].was_hit_vertical)
		texel_color = get_buffer(cub->no_buf, offset_y, cub->texture_offset);
	((uint32_t *)cub->layer1_buffer)[(WIN_W * y) + i] = texel_color;
}

static void	loop_init(t_cub *cub, int *wall, int x)
{
	float	perp_distance;
	float	distance_proj_plane;
	float	projected_wall_height;

	perp_distance = cub->ray[x].distance
		* cos(cub->ray[x].ray_angle - cub->player->rotationangle);
	distance_proj_plane = (WIN_W / 2) / tan((60 * (PI / 180)) / 2);
	projected_wall_height = (TILE_SIZE / perp_distance) * distance_proj_plane;
	wall[0] = (int)projected_wall_height;
	wall[1] = (WIN_H / 2) - ((wall[0]) / 2);
	if (wall[1] < 0)
		wall[1] = 0;
	wall[2] = (WIN_H / 2) + ((wall[0]) / 2);
	if (wall[2] > WIN_H)
		wall[2] = WIN_H;
	if (cub->ray[x].was_hit_vertical)
		cub->texture_offset = (int)cub->ray[x].wall_hit_y % TILE_SIZE;
	else
		cub->texture_offset = (int)cub->ray[x].wall_hit_x % TILE_SIZE;
}

/*
	wall[0] = wall_strip_height;
	wall[1] = wall_top_pixel;
	wall[2] = wall_bottom_pixel;
*/
void	generate_3d_projection(t_cub *cub)
{
	int		x;
	int		y;
	int		wall[3];

	x = -1;
	while (++x < NUM_RAYS)
	{
		loop_init (cub, wall, x);
		y = 0;
		while (y < wall[1])
			set_buffer(cub, (((y++) * (WIN_W * 4)) + (x * 4)), cub->cei);
		while (y < wall[2])
			cub_set_buffer(cub, x, y++, wall[0]);
		while (y < WIN_H)
			set_buffer(cub, (((y++) * (WIN_W * 4)) + (x * 4)), cub->flo);
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->layer1, 0, 0);
}
