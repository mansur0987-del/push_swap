/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <armaxima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:12:54 by armaxima          #+#    #+#             */
/*   Updated: 2021/10/10 17:25:57 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	long			i;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	tmp_s1 = (unsigned char *) s1;
	tmp_s2 = (unsigned char *) s2;
	i = 0;
	while (n-- != 0)
	{
		if (tmp_s1[i] - tmp_s2[i] != 0)
			return (tmp_s1[i] - tmp_s2[i]);
		i++;
	}
	return (tmp_s1[i - 1] - tmp_s2[i - 1]);
}
