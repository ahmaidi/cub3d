/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:51:49 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/10/14 16:30:07 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game_action.h"

void	remove_last_nl(t_cub **cub)
{
	remove_last_spaces(&(*cub)->map[(*cub)->size_map - 1]);
	while (*(*cub)->map[(*cub)->size_map - 1] == '\0')
	{
		free((*cub)->map[(*cub)->size_map]);
		free((*cub)->map[(*cub)->size_map - 1]);
		(*cub)->map[(*cub)->size_map - 1] = NULL;
		(*cub)->size_map--;
	}
}

int	check_up_down_walls(char *s1, char *s2)
{
	int	i;

	i = 1;
	while (s1[i])
	{
		if (s1[i] != '1' && s1[i] != ' ' && s2[i] != '\t')
			break ;
		i++;
	}
	if (s1[i] != '\0')
		return (1);
	i = 1;
	while (s2[i])
	{
		if (s2[i] != '1' && s2[i] != ' ' && s2[i] != '\t')
			break ;
		i++;
	}
	if (s2[i] != '\0')
		return (1);
	return (0);
}

int	check_walls(char **map, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (1);
		i++;
	}
	if (check_up_down_walls(map[0], map[size - 1]))
		return (1);
	return (0);
}
