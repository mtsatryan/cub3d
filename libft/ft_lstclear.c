/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 05:25:23 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/05/31 17:46:40 by mtsatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*entry;

	entry = *lst;
	while (entry)
	{
		tmp = entry->next;
		del(entry->content);
		free(entry);
		entry = tmp;
	}
	*lst = NULL;
}
