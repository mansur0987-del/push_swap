/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:02:44 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/24 15:02:49 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr_len(int fd, char	*str)
{
	size_t	i;
	char	*tmp;

	tmp = str;
	i = 0;
	if (!tmp || tmp == NULL)
	{
		i += ft_putstr_len(fd, "(null)");
		return (i);
	}
	while (tmp[i] != '\0')
	{
		ft_putchar_len(fd, tmp[i]);
		i++;
	}
	return (i);
}
