/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:41:40 by armaxima          #+#    #+#             */
/*   Updated: 2021/12/02 11:57:19 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_lst	*ft_put_b(t_lst **list, t_lst *new, int stack)
{
	t_lst	*tmp;

	if (stack == 1)
		ft_putstr_fd("pb\n", 1);
	else
		ft_putstr_fd("pa\n", 1);
	tmp = (*list);
	if (tmp == NULL)
	{
		*list = new;
		return (new);
	}
	if (tmp->up == NULL)
		tmp->up = new;
	else
	{
		tmp->up->down = new;
		new->up = tmp->up;
	}
	new->down = tmp;
	tmp->up = new;
	return (new);
}

static t_lst	*ft_find_to_b(t_lst *lst_down, t_lst *lst_up, t_swap *sw)
{
	int	i[2];

	i[0] = 0;
	i[1] = 0;
	while (lst_down->numb == sw->big || \
	lst_down->numb == sw->small || lst_down->numb == sw->mid)
	{
		lst_down = lst_down->down;
		i[0]++;
	}
	while (lst_up->numb == sw->big || \
	lst_up->numb == sw->small || lst_up->numb == sw->mid)
	{
		lst_up = lst_up->up;
		i[1]++;
	}
	if (i[0] <= i[1])
	{
		while (i[0]-- > 0)
			ft_putstr_fd("ra\n", 1);
		return (lst_down);
	}
	while (i[1]-- > 0)
		ft_putstr_fd("rra\n", 1);
	return (lst_up);
}

static int	ft_create_move_in_b(t_swap *sw, t_lst **lst_a)
{
	while (sw->size_a > 3)
	{
		(*lst_a) = ft_find_to_b((*lst_a), (*lst_a), sw);
		if (sw->lst_b == NULL)
			sw->lst_b = ft_put_b(&sw->lst_b, ft_cr_lst((*lst_a)->numb), 1);
		else
		{
			while (sw->lst_b->down != NULL && sw->lst_b->numb < sw->mid && \
			(*lst_a)->numb > sw->mid)
				sw->lst_b = ft_down_b(sw->lst_b);
			while (sw->lst_b->up != NULL && sw->lst_b->numb > sw->mid && \
			(*lst_a)->numb < sw->mid)
				sw->lst_b = ft_up_b(sw->lst_b);
			sw->lst_b = ft_put_b(&sw->lst_b, ft_cr_lst((*lst_a)->numb), 1);
			if (sw->lst_b == NULL)
				return (0);
		}
		(*lst_a) = ft_clear_stack(lst_a);
		sw->size_a--;
		sw->size_b++;
	}
	return (1);
}

static t_lst	*ft_check_stack_a(t_swap *sw, t_lst **lst)
{
	int	i;

	i = 0;
	if ((*lst)->numb == sw->small && (*lst)->down->numb == sw->big)
		i = 1;
	if ((*lst)->numb == sw->mid && (*lst)->down->numb == sw->small)
		i = 1;
	if ((*lst)->numb == sw->big && (*lst)->down->numb == sw->mid)
		i = 1;
	if (i == 1)
	{
		ft_swap(&((*lst)->numb), &((*lst)->down->numb));
		ft_putstr_fd("sa\n", 1);
	}
	return ((*lst));
}

int	ft_create_stack_b(t_swap *sw)
{
	sw->lst_b = NULL;
	sw->size_b = 0;
	if (!(ft_find_flags(sw)) || !(ft_create_move_in_b(sw, &sw->lst_a)))
		return (0);
	sw->lst_a = ft_check_stack_a(sw, &sw->lst_a);
	if (sw->size_b != 0)
	{
		ft_last_lst(&sw->lst_b);
		sw->lst_a = ft_move(sw, sw->lst_a);
		if (sw->lst_a == NULL)
			return (0);
	}
	sw->lst_a = ft_find_finish(sw->lst_a, sw->lst_a, sw->small);
	return (1);
}
