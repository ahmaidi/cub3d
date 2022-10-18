/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:50:18 by mboukhal          #+#    #+#             */
/*   Updated: 2022/09/20 09:06:34 by ahmaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	t = *lst;
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (t->next)
		t = t->next;
	t->next = new;
}

// int main ()
// {
// 	t_list* s = NULL;

// 	ft_lstadd_back(&s, ft_lstnew((void*) 1));
// 	ft_lstadd_back(&s, ft_lstnew((void*) 2));
// 	if (s->content == (void*)1)
// 		printf("1");
// 	if (s->next->content == (void*)2)
// 		printf("2");
// 	if (s->next == NULL)
// 		printf("0");

// }