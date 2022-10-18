/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 08:18:43 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/14 19:19:06 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game_action.h"

void	check_exteniton(char *file, char *str)
{
	int	size;

	size = ft_strlen(file);
	if (ft_strncmp(&file[size - 4], str, 4))
	{
		write(2, "ERROR\n", 6);
		ft_putstr_fd("ERROR\n\t\e[0;31m", STDERR_FILENO);
		ft_putstr_fd(file, STDERR_FILENO);
		ft_putstr_fd(": is not a \"", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd("\" file :(\e[0m\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	compare(char *s1, char *s2)
{
	while (*s1 == ' ' || *s1 == '\t')
		s1++;
	while (*s2 == ' ' || *s2 == '\t')
		s2++;
	if (!ft_strncmp(s1, s2, 2))
	{
		write(2, "ERROR\n", 6);
		write(2, "float Key\n", 10);
		ft_error();
	}
}

void	parse_it(t_cub **cub, char **str, char **str_depl, int *in_map)
{
	int	prev;

	if (*str != '\0' || (*cub)->in_map)
	{
		prev = *in_map;
		if (*in_map != 6)
			compare(*str_depl, *str);
		if (*in_map == 6)
			filling_map(cub, *str);
		*in_map += find_texture_or_colors(*str, cub);
		if ((*in_map == prev && *in_map != 6))
		{
			write(2, "ERROR\n", 6);
			write(2, "nbre of textures not equal five\n", 32);
			ft_error();
		}
	}
	free(*str_depl);
	*str_depl = ft_strdup(*str);
	free(*str);
}

int	parser_file(int fd, t_cub **cub)
{
	char	*str;
	int		in_map;
	char	*str_depl;

	in_map = 0;
	str_depl = ft_strdup("");
	str = get_next_line(fd);
	while (str)
	{
		remove_last_spaces(&str);
		if (*str == '\0' && !(*cub)->in_map)
		{
			free(str);
			str = get_next_line(fd);
			continue ;
		}
		parse_it(cub, &str, &str_depl, &in_map);
		str = get_next_line(fd);
	}
	free(str_depl);
	check_map(cub);
	return (1);
}

t_cub	*map_init(char *file)
{
	t_cub	*cub;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror (file);
		exit (EXIT_FAILURE);
	}
	cub = cub_init();
	parser_file(fd, &cub);
	side_of_player(cub);
	close(fd);
	return (cub);
}
