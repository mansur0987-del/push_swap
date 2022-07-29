/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_moving.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:56:03 by armaxima          #+#    #+#             */
/*   Updated: 2021/12/02 12:40:36 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lst	*ft_find_finish(t_lst *lst_down, t_lst *lst_up, int numb)
{
	int	down;
	int	up;

	down = 0;
	up = 0;
	while (lst_down->numb != numb)
	{
		lst_down = lst_down->down;
		down++;
	}
	while (lst_up->numb != numb)
	{
		lst_up = lst_up->up;
		up++;
	}
	if (down <= up)
	{
		while (down-- > 0)
			ft_putstr_fd("ra\n", 1);
		return (lst_down);
	}
	while (up-- > 0)
		ft_putstr_fd("rra\n", 1);
	return (lst_up);
}

static t_lst	*ft_put_back_b(t_lst **list, t_lst *new)
{
	t_lst	*tmp;
	t_lst	*last;

	ft_putstr_fd("pa\n", 1);
	tmp = (*list);
	last = (*list);
	last = last->up;
	last->down = new;
	new->up = last;
	tmp->up = new;
	new->down = tmp;
	return (new);
}

t_lst	*ft_move(t_swap *sw, t_lst *lst_a)
{
	while (sw->size_b > 0)
	{
		ft_put_move(sw, lst_a);
		if (sw->size_b > 2)
			sw->lst_b = ft_find_near_b(sw->lst_b, \
			sw->lst_b, find_score(sw));
		else
		{
			if (sw->lst_b->down->numb > sw->lst_b->numb)
				sw->lst_b = ft_down_b(sw->lst_b);
		}
		lst_a = ft_find_small(lst_a, lst_a, sw->lst_b->numb);
		lst_a = ft_put_back_b(&lst_a, ft_cr_lst(sw->lst_b->numb));
		if (lst_a == NULL)
			return (NULL);
		sw->lst_b = ft_clear_stack(&sw->lst_b);
		sw->size_a++;
		sw->size_b--;
	}
	return (lst_a);
}
