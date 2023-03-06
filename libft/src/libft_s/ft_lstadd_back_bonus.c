/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:17:50 by agil-ord          #+#    #+#             */
/*   Updated: 2022/11/26 13:45:56 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		temp = ft_lstlast(*lst);
		temp -> next = new;
	}
}

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*temp_lst;

// 	if (!lst || !new)
// 	{
// 		if (!new)
// 			return ;
// 		*lst = new;
// 		return ;
// 	}
// 	else
// 	{
// 		*temp_lst = *lst;
// 		*temp_lst = ft_lstlast(*lst);
// 		temp_lst -> next = new;
// 	}
// }
