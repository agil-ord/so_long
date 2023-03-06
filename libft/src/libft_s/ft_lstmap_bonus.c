/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:21:01 by agil-ord          #+#    #+#             */
/*   Updated: 2022/11/26 13:45:56 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*new_nodo;

	if (!f && !lst)
		return (NULL);
	newlst = 0;
	while (lst)
	{
		new_nodo = ft_lstnew(0);
		if (!new_nodo)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		new_nodo -> content = f(lst -> content);
		ft_lstadd_back(&newlst, new_nodo);
		lst = lst -> next;
	}
	return (newlst);
}
