/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:26:42 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/05/31 17:32:26 by mtsatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;

	s = (char *)str;
	while (*str)
		str++;
	while (s <= str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str--;
	}
	return (NULL);
}
