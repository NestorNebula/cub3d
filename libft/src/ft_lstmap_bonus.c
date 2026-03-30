/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus.ft_lstmap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:33:30 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/11 08:42:37 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*lst_curr;
	t_list	*node;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_lst = ft_lstnew((*f)(lst->content));
	if (new_lst == NULL)
		return (NULL);
	lst_curr = lst->next;
	while (lst_curr != NULL)
	{
		node = ft_lstnew((*f)(lst_curr->content));
		if (node == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}	
		ft_lstadd_back(&new_lst, node);
		lst_curr = lst_curr->next;
	}
	return (new_lst);
}
