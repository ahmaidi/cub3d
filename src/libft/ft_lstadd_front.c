/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 10:39:03 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/20 09:07:08 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// int main(){
// 	t_list * r = NULL ;
// 	ft_lstadd_front(&r, ft_lstnew((void*)1));
// 	ft_lstadd_front(&r, ft_lstnew((void*)2));
// 	if (r->content == (void*)2)
// 		printf("2\n");
// 	if (r->next->content == (void*)1)
// 		printf("1\n");
// 	if (!r->next->next)
// 		printf("0\n");
//}