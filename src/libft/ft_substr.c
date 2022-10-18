/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:28:41 by mboukhal          #+#    #+#             */
/*   Updated: 2021/11/15 11:26:04 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*sub_copy(size_t len, char const *s, unsigned int start)
{
	char	*strc;

	strc = ft_calloc(len + 1, sizeof(char));
	if (!strc)
		return (NULL);
	ft_strlcpy(strc, &(s[start]), len + 1);
	return (strc);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s) - start;
	if (start > (s_len + start))
		return (sub_copy (1, (const char *)"\0", 0));
	if (s_len < len)
		return (sub_copy (s_len, s, start));
	else
		return (sub_copy (len, s, start));
}
