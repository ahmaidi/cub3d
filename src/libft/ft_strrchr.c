/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:52:56 by mboukhal          #+#    #+#             */
/*   Updated: 2021/11/12 18:58:01 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		str_len;
	char		*str;

	str = (char *)s;
	str_len = ft_strlen(str);
	while (str_len + 1)
	{
		if (str[str_len] == (char) c)
			return (&str[str_len]);
		str_len--;
	}
	return (NULL);
}
