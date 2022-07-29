/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <armaxima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:13:02 by armaxima          #+#    #+#             */
/*   Updated: 2021/10/10 18:43:14 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmp_dst;
	unsigned const char	*tmp_src;

	if (dst == src)
		return (dst);
	tmp_dst = (unsigned char *) dst;
	tmp_src = (unsigned const char *) src;
	while (len > 0 && dst > src)
	{
		len--;
		tmp_dst[len] = tmp_src[len];
	}
	while (len-- > 0 && dst < src)
		*tmp_dst++ = *tmp_src++;
	return (dst);
}
