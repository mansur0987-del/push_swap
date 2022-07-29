/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansurkakushkin <mansurkakushkin@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:13:31 by armaxima          #+#    #+#             */
/*   Updated: 2021/10/13 13:03:25 by mansurkakus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*tmp;

	tmp = (const unsigned char *) s;
	while (*tmp)
	{
		if (*tmp == (unsigned char)c)
			return ((char *)tmp);
		tmp++;
	}
	if (c == '\0')
		return ((char *) tmp);
	return (NULL);
}
