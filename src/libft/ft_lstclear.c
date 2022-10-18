/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:26:30 by mboukhal          #+#    #+#             */
/*   Updated: 2021/11/15 13:38:52 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;

	head = *lst;
	while (head)
	{
		head = head->next;
		del((*lst)->content);
		free(*lst);
		*lst = head;
	}
}

// int main ()
// {
// 	t_list *r = ft_lstnew(malloc(2));

// 	t_list *m = ft_lstnew(malloc(1));
// 	ft_lstadd_front(&r, m);

// 	ft_lstclear(&r,free);
// 	if (r == 0)
// 		printf("kjdsgjldkfglk");
// }