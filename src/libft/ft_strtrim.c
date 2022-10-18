/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 09:29:00 by mboukhal          #+#    #+#             */
/*   Updated: 2021/11/15 11:08:12 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	while_not_in_table(const char *s, int *tab, size_t i)
{
	while (i)
	{
		if (tab[(size_t)s[i]] == 1 || !(s[i]))
			i--;
		else
			break ;
	}
	return (i);
}

static int	while_in_table(const char *s, int *tab)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (tab[(size_t)s[i]])
			i++;
		else
			break ;
	}
	return (i);
}

static int	get_len(size_t *start, size_t *end, char const *s1, char const *set)
{
	int		tab[128];
	size_t	s1_len;
	size_t	i;

	i = 0;
	while (i < 128)
		tab[i++] = 0;
	i = 0;
	s1_len = ft_strlen(s1);
	while (set[i])
		tab[(size_t)set[i++]] = 1;
	i = while_in_table(s1, tab);
	if (s1_len == i)
		return (1);
	*start = i;
	i = s1_len;
	i = while_not_in_table(s1, tab, i);
	*end = i + 1;
	return (0);
}

char	*ft_strtrim(const char *s1, char const *set)
{
	size_t	index[2];
	size_t	len[2];
	int		i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	len[0] = ft_strlen(s1);
	i = get_len(&index[0], &index[1], s1, set);
	if (i == 1)
	{
		str = malloc(1 * sizeof(char));
		if (!str)
			return (0);
		*str = '\0';
		return (str);
	}
	len[1] = len[0] - (index[0] + (len[0] - index[1])) + 1;
	str = ft_calloc(len[1], sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy (str, &(s1[index[0]]), len[1]);
	return (str);
}
