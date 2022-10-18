/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 08:08:59 by mboukhal          #+#    #+#             */
/*   Updated: 2022/10/15 14:08:19 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../src/libft/libft.h"
# include "../src/get_next_line/get_next_line.h"

void	*ft_alloc(void *old_alloc, int old_size, int new_size);
void	free_it(void *ptr);
void	*var_init(int size);

#endif /* __UTILS_H__ */