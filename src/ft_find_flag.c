/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:07:11 by armaxima          #+#    #+#             */
/*   Updated: 2021/12/01 21:56:32 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_find_mid(t_swap *swap, int *numbs)
{
	int	i;
	int	*g;
	int	q;

	i = -1;
	swap->mid = swap->small;
	g = NULL;
	g = malloc(sizeof(int) * swap->size_a);
	if (g == NULL)
		return (0);
	while (swap->size_a > ++i)
		g[i] = numbs[i];
	i = -1;
	while (swap->size_a > ++i)
	{
		q = i;
		while (swap->size_a > ++q)
		{
			if (g[i] > g[q])
				ft_swap(&g[i], &g[q]);
		}
	}
	swap->mid = g[swap->size_a / 2];
	free(g);
	return (1);
}

int	ft_find_flags(t_swap *swap)
{
	int	i;

	i = 0;
	swap->big = swap->stack_a[i];
	while (swap->size_a > i)
	{
		if (swap->stack_a[i] > swap->big)
			swap->big = swap->stack_a[i];
		i++;
	}
	i = 0;
	swap->small = swap->stack_a[i];
	while (swap->size_a > i)
	{
		if (swap->stack_a[i] < swap->small)
			swap->small = swap->stack_a[i];
		i++;
	}
	if (!(ft_find_mid(swap, swap->stack_a)))
		return (0);
	return (1);
}
