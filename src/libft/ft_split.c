/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:00:01 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/01 23:21:19 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_str(char *str, char ch)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ch)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != ch)
			i++;
	}
	return (count);
}

static int	strlen_m(char *str, char ch)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ch)
		i++;
	return (i);
}

static void	*ft_w(char **s, char *str, char ch, int wNumber)
{
	int		len_w;
	int		i;
	char	*w;

	i = 0;
	len_w = strlen_m(str, ch);
	w = (char *)malloc(sizeof(char) * (len_w + 1));
	if (!w)
	{
		while (wNumber)
		{
			ft_bzero(s[wNumber], ft_strlen(s[wNumber]));
			free(s[wNumber]);
			wNumber--;
		}
		free(s);
		return (NULL);
	}
	while (i < len_w)
	{
		w[i] = str[i];
		i++;
	}
	w[i] = 0;
	return (w);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i[2];

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *)
			* (count_str((char *)s, c) + 1));
	if (!str)
		return (NULL);
	i[0] = 0;
	i[1] = 1;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			str[i[0]] = ft_w(str, (char *)s, c, i[1]++);
			i[0]++;
		}
		while (*s && *s != c)
			s++;
	}
	str[i[0]] = 0;
	return (str);
}
