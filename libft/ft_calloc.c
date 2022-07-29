/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <armaxima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:12:14 by armaxima          #+#    #+#             */
/*   Updated: 2021/10/10 14:12:15 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*buf;
	size_t	len;
	int		i;

	if (!count)
		count = 1;
	if (!size)
		size = 1;
	len = count * size;
	buf = (char *) malloc(len);
	if (!buf)
		return (NULL);
	i = 0;
	while (len-- > 0)
		buf[i++] = '\0';
	return (buf);
}
