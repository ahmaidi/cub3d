/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:32:06 by mboukhal          #+#    #+#             */
/*   Updated: 2021/11/15 13:47:29 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	copy = ft_calloc (ft_strlen (s1) + 1, sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (*s1)
		copy[i++] = *s1++;
	copy[i] = '\0';
	return (copy);
}
