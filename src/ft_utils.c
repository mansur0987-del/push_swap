/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:20:35 by armaxima          #+#    #+#             */
/*   Updated: 2021/12/01 21:55:43 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_clear_lst(t_lst **lst, int size)
{
	t_lst	*tmp;
	t_lst	*tmp_2;

	if (!lst || !(*lst))
		return ;
	tmp = (*lst);
	while (size-- > 0)
	{
		tmp_2 = tmp->down;
		free(tmp);
		tmp = NULL;
		tmp = tmp_2;
	}
	*lst = NULL;
}

int	ft_free(t_swap *swap, char *str)
{
	if (swap->lst_a != NULL)
		ft_clear_lst(&(swap->lst_a), swap->size_a);
	if (swap->stack_a != NULL)
		free(swap->stack_a);
	free(swap);
	return (ft_error(str));
}

int	ft_free_al(t_swap *swap, char *str)
{
	if (swap->lst_b != NULL)
		ft_clear_lst(&(swap->lst_b), swap->size_b);
	return (ft_free(swap, str));
}

int	ft_free_split(t_swap *swap, int result)
{
	int	i;

	i = 0;
	while (swap->spl_numbers[i] != NULL)
		free(swap->spl_numbers[i++]);
	free(swap->spl_numbers);
	return (result);
}

int	ft_error(char *str)
{
	if (str[0] != '\0')
		ft_putstr_len(2, "Error\n");
	ft_putstr_len(2, str);
	return (0);
}
