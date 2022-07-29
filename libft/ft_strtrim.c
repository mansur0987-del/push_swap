/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansurkakushkin <mansurkakushkin@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:14:16 by armaxima          #+#    #+#             */
/*   Updated: 2021/10/12 14:17:32 by mansurkakus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_to_search_start(char const *s1, char const *set)
{
	int	i;
	int	start;

	start = 0;
	while (s1[start] != '\0')
	{
		i = ft_strlen((char *)set) - 1;
		while (set[i] > 0 && s1[start] != set[i])
			i--;
		if (s1[start++] != set[i])
			break ;
	}
	return (start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;
	int	i;

	if (!s1 || !set)
		return (NULL);
	start = ft_to_search_start(s1, set);
	if (start == ft_strlen((char *)s1))
		return (ft_strdup(""));
	end = ft_strlen((char *)s1) - 1;
	while (end > 0)
	{
		i = ft_strlen((char *)set) - 1;
		while (set[i] > 0 && s1[end] != set[i])
			i--;
		if (s1[end--] != set[i])
			break ;
	}
	return (ft_substr(s1, start - 1, (end + 2) - (start - 1)));
}
