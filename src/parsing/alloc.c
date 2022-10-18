/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 08:52:50 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/15 14:08:04 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game_action.h"

void	*var_init(int size)
{
	char	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	return (ptr);
}

void	free_it(void *ptr)
{
	int		i;
	char	*p;

	p = (char *)ptr;
	i = -1;
	while (p[++i])
		p[i] = 0;
	free(ptr);
}

void	*ft_alloc(void *old_ptr, int old_size, int new_size)
{
	unsigned char	*ptr;
	int				i;

	i = -1;
	if (old_ptr == NULL)
		return (malloc(new_size));
	ptr = (unsigned char *)malloc(new_size);
	if (ptr == NULL)
		return (NULL);
	while (++i < old_size && i < new_size)
		ptr[i] = ((unsigned char *)old_ptr)[i];
	free(old_ptr);
	return (ptr);
}
