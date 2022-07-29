/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <armaxima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:48:18 by armaxima          #+#    #+#             */
/*   Updated: 2021/10/13 21:13:17 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(char *s, unsigned int start)
{
	while (s[start] != '\0')
		start++;
	return ((size_t)start);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr_of_s;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	if ((int)start >= ft_strlen((char *)s))
	{
		substr_of_s = malloc (sizeof(char));
		if (substr_of_s == NULL)
			return (NULL);
		substr_of_s[i] = '\0';
		return (substr_of_s);
	}
	if (ft_strnlen((char *)s, start) < len)
		substr_of_s = malloc (ft_strnlen((char *)s, start) + 1);
	else
		substr_of_s = malloc ((sizeof(char) * len) + 1);
	if (substr_of_s == NULL)
		return (NULL);
	while (s[start] != '\0' && len-- > 0)
		substr_of_s[i++] = (char)s[start++];
	substr_of_s[i] = '\0';
	return (substr_of_s);
}
