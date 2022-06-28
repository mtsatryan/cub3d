/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsatrya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 18:12:51 by mtsatrya          #+#    #+#             */
/*   Updated: 2022/05/31 17:38:49 by mtsatrya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_count(const char *s, char c)
{
	int	i;
	int	count;
	int	is_str;

	i = 0;
	count = 0;
	is_str = 0;
	while (s[i])
	{
		if (s[i] != c && is_str == 0)
		{
			is_str = 1;
			count++;
		}
		else
			is_str = 0;
		i++;
	}
	return (count + 1);
}

static char	*result_str(const char *s, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_calloc(sizeof(char), end - start + 1);
	while (start < end)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		start;
	char	**result;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	start = -1;
	result = ft_calloc(sizeof(char *), (str_count(s, c) + 1));
	if (!result)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start == -1)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			result[j++] = result_str(s, start, i);
			start = -1;
		}
		i++;
	}
	return (result);
}
