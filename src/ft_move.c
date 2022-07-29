/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 11:38:50 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/28 22:21:13 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lst	*ft_up_a(t_lst *lst)
{
	lst = lst->up;
	ft_putstr_fd("rra\n", 1);
	return (lst);
}

t_lst	*ft_down_a(t_lst *lst)
{
	lst = lst->down;
	ft_putstr_fd("ra\n", 1);
	return (lst);
}

t_lst	*ft_up_b(t_lst *lst)
{
	lst = lst->up;
	ft_putstr_fd("rrb\n", 1);
	return (lst);
}

t_lst	*ft_down_b(t_lst *lst)
{
	lst = lst->down;
	ft_putstr_fd("rb\n", 1);
	return (lst);
}
