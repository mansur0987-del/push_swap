/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansurkakushkin <mansurkakushkin@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:14:08 by armaxima          #+#    #+#             */
/*   Updated: 2021/10/13 14:28:39 by mansurkakus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	g;

	i = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (len > i && haystack[i] != '\0')
	{
		g = 0;
		while (needle[g] && needle[g] == haystack[i + g] && i + g < len)
			g++;
		if (needle[g] == '\0')
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}
