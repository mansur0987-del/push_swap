/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:20:18 by armaxima          #+#    #+#             */
/*   Updated: 2021/12/01 20:20:46 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	numb;

	numb = *a;
	*a = *b;
	*b = numb;
}

t_lst	*ft_clear_stack(t_lst **lst)
{
	t_lst	*tmp;

	tmp = (*lst)->down;
	(*lst)->up->down = tmp;
	tmp->up = (*lst)->up;
	free((*lst));
	return (tmp);
}
