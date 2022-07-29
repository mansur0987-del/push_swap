/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansurkakushkin <mansurkakushkin@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:13:48 by armaxima          #+#    #+#             */
/*   Updated: 2021/10/13 13:52:41 by mansurkakus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	len_dst = 0;
	len_src = 0;
	while (dst[len_dst] != '\0')
		len_dst++;
	while (src[len_src] != '\0')
		len_src++;
	if (len_dst > dstsize)
		len_src = len_src + dstsize;
	else
		len_src = len_src + len_dst;
	i = 0;
	while (src[i] != '\0' && len_dst + 1 < dstsize)
		dst[len_dst++] = src[i++];
	dst[len_dst] = '\0';
	return (len_src);
}
