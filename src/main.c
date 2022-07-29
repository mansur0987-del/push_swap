/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:06:21 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/29 20:20:00 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_check_sort(t_swap *sw)
{
	int	i;

	i = 0;
	while (i + 1 != sw->size_a)
	{
		if (sw->stack_a[i] > sw->stack_a[i + 1])
			return (1);
		i++;
	}
	sw->lst_a = NULL;
	return (0);
}

int	main(int argc, char **argv)
{
	t_swap	*sw;

	if (argc < 2)
		return (ft_error(""));
	sw = NULL;
	sw = malloc(sizeof(t_swap));
	if (sw == NULL)
		return (ft_error("Not memory for stack_a\n"));
	if (!(ft_check_arguments(argc, argv, sw)))
		return (ft_free(sw, "Argument is not valid\n"));
	if (!(ft_check_sort(sw)))
		return (ft_free(sw, ""));
	if (!(ft_creat_a_list(sw)))
		return (ft_free(sw, "Not memory for stack A\n"));
	if (!(ft_create_stack_b(sw)))
		return (ft_free_al(sw, "Not memory for stack_b\n"));
	ft_free_al(sw, "");
	return (0);
}
