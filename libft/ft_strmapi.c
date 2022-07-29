/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansurkakushkin <mansurkakushkin@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:14:05 by armaxima          #+#    #+#             */
/*   Updated: 2021/10/11 13:42:22 by mansurkakus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*putout;
	unsigned int	i;

	if (!s)
		return (NULL);
	putout = malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (putout == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		putout[i] = (*f)(i, (char)s[i]);
		i++;
	}
	putout[i] = '\0';
	return (putout);
}
