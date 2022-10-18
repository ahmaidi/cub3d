/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:49:29 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/10/14 19:16:20 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game_action.h"

int	find_texture_or_colors(char *str, t_cub **cub)
{
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == 'N')
		return (get_texture(str + 1, cub, 0));
	else if (*str == 'S')
		return (get_texture(str + 1, cub, 1));
	else if (*str == 'W')
		return (get_texture(str + 1, cub, 2));
	else if (*str == 'E')
		return (get_texture(str + 1, cub, 3));
	else if (*str == 'F')
		return (get_color(str + 1, cub, 4));
	else if (*str == 'C')
		return (get_color(str + 1, cub, 5));
	else
		return (0);
}

void	ft_error(void)
{
	write(2, "invalid map\n", 12);
	exit(1);
}

int	check_charactre(char *str, t_cub **cub)
{
	int	i;

	i = 0;
	while (*str == ' ' || *str == '\t')
		str++;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != ' ' && str[i] != '1' && str[i] != '\t'\
		&& str[i] != 'N' && str[i] != 'S' && str[i] != 'E' && str[i] != 'W')
			return (0);
		if ((*cub)->is_player > 1)
			return (0);
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
		{
			(*cub)->side_of_player = str[i];
			(*cub)->is_player += 1;
		}
		i++;
	}
	return (1);
}

void	remove_last_spaces(char **str)
{
	while ((*str)[ft_strlen(*str) - 1] == ' ' || \
	(*str)[ft_strlen(*str) - 1] == '\t' || (*str)[ft_strlen(*str) - 1] == '\n')
		(*str)[ft_strlen(*str) - 1] = '\0';
}

void	filling_map(t_cub **cub, char *str)
{
	(*cub)->in_map = 1;
	remove_last_spaces(&str);
	if (!check_charactre(str, cub))
	{
		write(2, "ERROR\n", 6);
		write(2, "There's a foreign key in the map OR much players\n", 49);
		ft_error();
	}
	++((*cub)->size_map);
	(*cub)->map = ft_alloc((*cub)->map, sizeof(char *) * \
	(*cub)->size_map - 1, sizeof(char *) * (*cub)->size_map + 1);
	(*cub)->map[(*cub)->size_map - 1] = ft_strdup(str);
	(*cub)->map[(*cub)->size_map] = NULL;
}
