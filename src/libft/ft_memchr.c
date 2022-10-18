/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:19:36 by mboukhal          #+#    #+#             */
/*   Updated: 2021/11/08 09:36:25 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*mem;

	i = 0;
	mem = (unsigned char *) s;
	while (i < n)
	{
		if (mem[i] == (unsigned char)c)
			return (mem + i);
		i++;
	}
	return (NULL);
}
