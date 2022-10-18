/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:07:08 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/13 23:43:22 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PART_BONUS_H
# define PART_BONUS_H
# include "game_action.h"

int		mouse_mouve(int x, int y, t_cub *cub);
int		deal_key_bo(int key, t_cub *cub);
void	set_map_bo(t_cub *cub, int mode);

#endif
