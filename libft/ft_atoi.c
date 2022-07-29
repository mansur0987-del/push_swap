/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:12:01 by armaxima          #+#    #+#             */
/*   Updated: 2021/12/02 15:18:16 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_to_max_min(unsigned long long out, long long g, const char *str)
{
	if (str[g] == '-')
	{
		if (out > 9223372036854775807)
			return (0);
		return (-out);
	}
	if (out > 9223372036854775806)
		return (-1);
	return (out);
}

int	ft_atoi(const char *str)
{
	unsigned long long	out;
	long long			i;
	long long			g;

	i = 0;
	out = 0;
	while (str[i] && ((str[i] > 9 && str[i] < 13) || str[i] == 32))
		i++;
	g = i;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0')
		out = out * 10 + (str[i++] - '0');
	if (str[g] == '-' && out > 9223372036854775807)
		return (0);
	else if (str[g] != '-' && out > 9223372036854775806)
		return (-1);
	if (str[g] == '-')
		return (-out);
	return (out);
}
