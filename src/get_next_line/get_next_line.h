/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:21:42 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/09/01 17:39:35 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin_g(char const *s1, char const *s2);
size_t	ft_strlen_g(const char *s);
int		ft_strchr_g(const char *s, int c);
char	*ft_strdup_g(const char *s1);
char	*ft_substr_g(char const *s, unsigned int start, size_t len);
#endif