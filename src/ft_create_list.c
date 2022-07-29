/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:56:09 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/30 19:40:13 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_lst	*ft_cr_lst(int numb)
{
	t_lst	*new;

	new = NULL;
	new = malloc(sizeof(t_lst));
	if (new == NULL)
		return (NULL);
	new->numb = numb;
	new->down = NULL;
	new->up = NULL;
	return (new);
}

void	ft_put_list_down(t_lst **list, t_lst *new)
{
	t_lst	*tmp;

	tmp = (*list);
	if (!(*list))
	{
		*list = new;
		return ;
	}
	while (tmp->down != NULL)
		tmp = tmp->down;
	tmp->down = new;
	new->up = tmp;
}

void	ft_last_lst(t_lst **list)
{
	t_lst	*tmp;
	t_lst	*last;

	tmp = (*list);
	last = (*list);
	while (tmp->up != NULL)
		tmp = tmp->up;
	while (last->down != NULL)
		last = last->down;
	last->down = tmp;
	tmp->up = last;
}

int	ft_creat_a_list(t_swap *sw)
{
	int	i;

	i = 0;
	while (i < sw->size_a)
	{
		ft_put_list_down(&sw->lst_a, \
		ft_cr_lst(sw->stack_a[i]));
		if (sw->lst_a == NULL)
			return (0);
		i++;
	}
	ft_last_lst(&sw->lst_a);
	return (1);
}
