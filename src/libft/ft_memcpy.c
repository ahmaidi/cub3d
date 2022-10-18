/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:50:45 by mboukhal          #+#    #+#             */
/*   Updated: 2021/11/15 13:57:19 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int			i;
	char		*t_dst;
	const char	*t_src;

	if (!dst && !src)
		return (NULL);
	if (!n)
		return (dst);
	t_dst = (char *) dst;
	t_src = (const char *) src;
	i = -1;
	while (i++ < (int)(n - 1))
		t_dst[i] = t_src[i];
	return (dst);
}
