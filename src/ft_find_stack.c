/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:22:26 by armaxima          #+#    #+#             */
/*   Updated: 2021/12/02 12:13:54 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_score(t_swap *sw)
{
	int	score;
	int	i;
	int	numb;

	score = 0;
	while (sw->lst_b->move != score)
	{
		i = 0;
		while (sw->lst_b->move != score && i++ < sw->size_b)
			sw->lst_b = sw->lst_b->down;
		if (sw->lst_b->move == score)
			break ;
		score++;
	}
	numb = sw->lst_b->numb;
	i = 0;
	while (i++ < sw->size_b)
	{
		if (sw->lst_b->move == score && sw->lst_b->numb > numb)
			numb = sw->lst_b->numb;
		sw->lst_b = sw->lst_b->down;
	}
	return (numb);
}

t_lst	*ft_find_near_b(t_lst *lst_down, t_lst *lst_up, int numb)
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
			ft_putstr_fd("rb\n", 1);
		return (lst_down);
	}
	while (up-- > 0)
		ft_putstr_fd("rrb\n", 1);
	return (lst_up);
}

t_lst	*ft_find_small(t_lst *lst_down, t_lst *lst_up, int numb)
{
	int	down;
	int	up;

	down = 0;
	up = 0;
	while (lst_down->up->numb > numb || lst_down->numb < numb)
	{
		lst_down = lst_down->down;
		down++;
	}
	while (lst_up->up->numb > numb || lst_up->numb < numb)
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

static int	ft_find_numb_small(t_lst *lst_down, t_lst *lst_up, int numb)
{
	int	down;
	int	up;

	down = 0;
	up = 0;
	while (lst_down->up->numb > numb || lst_down->numb < numb)
	{
		lst_down = lst_down->down;
		down++;
	}
	while (lst_up->up->numb > numb || lst_up->numb < numb)
	{
		lst_up = lst_up->up;
		up++;
	}
	if (down <= up)
		return (down);
	return (up);
}

void	ft_put_move(t_swap *sw, t_lst *lst_a)
{
	int		i;
	t_lst	*tmp;

	tmp = sw->lst_b;
	i = 0;
	while (i++ < sw->size_b)
	{
		tmp->move = i - 1;
		tmp->move += ft_find_numb_small(lst_a, lst_a, tmp->numb);
		tmp = tmp->down;
	}
	i = 0;
	while (i++ <= sw->size_b / 2)
	{
		tmp->move = i - 1;
		tmp->move += ft_find_numb_small(lst_a, lst_a, tmp->numb);
		tmp = tmp->up;
	}
}
