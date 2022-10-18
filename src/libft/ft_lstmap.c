/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:53:35 by mboukhal          #+#    #+#             */
/*   Updated: 2021/11/15 13:43:15 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;
	int		count;

	if (!lst || !f)
		return (NULL);
	temp = lst;
	count = 1;
	new = ft_lstnew(f(temp->content));
	temp = temp->next;
	while (temp)
	{
		ft_lstadd_back(&new, ft_lstnew(f(temp->content)));
		if (!new)
		{
			while (count--)
				ft_lstdelone(new, del);
			return (NULL);
		}
		count++;
		temp = temp->next;
	}
	return (new);
}
