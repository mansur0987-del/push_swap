/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <armaxima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:12:58 by armaxima          #+#    #+#             */
/*   Updated: 2021/10/10 16:17:55 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char		*tmp_dst;
	const char	*tmp_src;

	if (!len || (!dst && !src))
		return (dst);
	tmp_dst = (char *) dst;
	tmp_src = (const char *) src;
	while (len-- > 0)
	{
		*tmp_dst = *tmp_src;
		tmp_dst++;
		tmp_src++;
	}
	return (dst);
}
