/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansurkakushkin <mansurkakushkin@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:14:12 by armaxima          #+#    #+#             */
/*   Updated: 2021/10/13 13:08:15 by mansurkakus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*tmp_last;

	tmp_last = (0);
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			tmp_last = (unsigned char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	if (tmp_last)
		return ((char *)tmp_last);
	return (0);
}
