/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_action.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:37:31 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/15 14:11:51 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_ACTION_H
# define GAME_ACTION_H

# include "cub.h"
# include "../includes/rays.h"

# define UP_KEY				13
# define DOWN_KEY			1
# define RIGHT_KEY			2
# define LEFT_KEY			0
# define EXIT_BOTTON		17

# define L_ARROW_KEY		123
# define R_ARROW_KEY		124

# define WIN_W				1600
# define WIN_H				900

# define FALSE				0
# define TRUE				1

# define TWO_PI 			6.28318530
# define FLT_MAX			3.402823466e+38F
# define TILE_SIZE			64
# define SCAL   			8

int		mouse_hook(int key, t_cub *cub);
void	drow_row_minimap(t_cub *c);
void	set_buffer(t_cub *c, int pixel, int color);
void	drow_minimap(t_cub *c);
void	drow_floor_and_ceilling(t_cub *c);
void	update_image(t_cub *cub);
void	moveplayer(t_cub *cub);
void	minimap_manip(t_cub *cub);
void	put_image(t_cub *cub, int *coord_i, int empty);
void	key_w_s(t_cub *cub, int i);
void	key_a(t_cub *cub);
void	key_d(t_cub *cub);
void	key_rotate(t_cub *cub, int i);
float	normalize_angle(float angle);
int		is_it_hitt_wall(t_cub *cub, float x, float y);
void	cast_ray(t_cub *cub, float ra, int stripl);
void	drow_rays(t_cub *cub);
void	rander_reys(t_cub *cub);
void	generate_3d_projection(t_cub *cub);
void	set_map(t_cub *cub);
void	cast_ray_init(t_cub *cub);
void	add_plus(t_cub **cub, int j);
void	add_front_plus(t_cub **cub);
void	add_back_plus(t_cub *cub);
void	add_back(t_cub **cub, int len);
int		check(char c);
int		check_around_zero(t_cub **cub);
void	check_map(t_cub **cub);
void	check_str_valid(char *str);
void	check_nbr_vrg(char *str);
int		wrong_color(void);
int		create_trgb(int *rgb);
void	side_of_player(t_cub *cub);

#endif