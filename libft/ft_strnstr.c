/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:20:07 by mtsatrya          #+#    #+#             */
/*   Updated: 2021/02/05 14:32:46 by mtsatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	j = 0;
	while (j < len && haystack[j])
	{
		i = 0;
		while (j < len && haystack[j] == needle[i] && haystack[j] && needle[i])
		{
			i++;
			j++;
		}
		if (needle[i] == '\0')
			return ((char *)&haystack[j - i]);
		j = j - i + 1;
	}
	return (NULL);
}
