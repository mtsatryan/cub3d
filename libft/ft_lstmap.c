/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 05:43:47 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/05/31 17:46:10 by mtsatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*newlist;

	if (!lst || !*f)
		return (NULL);
	first = ft_lstnew((*f)(lst->content));
	if (!first)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		newlist = ft_lstnew((*f)(lst->content));
		if (!newlist)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, newlist);
	}
	return (first);
}
