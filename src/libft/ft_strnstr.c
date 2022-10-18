/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:45:54 by mboukhal          #+#    #+#             */
/*   Updated: 2021/11/12 20:22:34 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	r;
	char	*str;

	i = 0;
	str = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			str = (char *)haystack + i;
			r = 0;
			while (haystack[i + r] == needle[r] && i + r < len)
			{
				if (!needle[r + 1])
					return (str);
				r++;
			}
			str = 0;
		}
		i++;
	}
	return (NULL);
}
