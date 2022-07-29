/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_sw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 22:22:19 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/28 22:22:36 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*ft_strdup_sp(const char *src)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *) malloc(ft_strlen((char *) src) + 2);
	if (str == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i++] = ' ';
	str[i] = '\0';
	return (str);
}
