/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:53:06 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/10/14 19:17:06 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game_action.h"

void	check_str_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i - 1] != '\\')
			break ;
		i++;
	}
	if (str[i] != '\0')
	{
		write(2, "ERROR\n", 6);
		write(2, "texture not valid\n", 18);
		ft_error();
	}
}

void	check_nbr_vrg(char *str)
{
	int	i;
	int	nbr_vrg;

	i = 0;
	nbr_vrg = 0;
	while (str[i])
	{
		if (str[i] == ',')
			nbr_vrg++;
		i++;
	}
	if (nbr_vrg != 2)
	{
		write(2, "ERROR\n", 6);
		write(2, "nbre of comma not equal three\n", 30);
		ft_error();
	}
}

int	wrong_color(void)
{
	write(2, "ERROR\n", 6);
	write(2, "The color's value doesn't include to 0-255\n", 43);
	ft_error();
	return (0);
}
