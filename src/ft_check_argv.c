/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:25:53 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/26 19:33:15 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_check_argument(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ((str[i] > 9 && str[i] < 13) || str[i] == 32))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

static int	ft_check_long_numb(char *str)
{
	long long	out;
	long long	i;
	long long	g;

	i = 0;
	out = 0;
	while (str[i] && ((str[i] > 9 && str[i] < 13) || str[i] == 32))
		i++;
	g = i;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0')
		out = out * 10 + (str[i++] - '0');
	if (str[g] == '-' && out > 2147483648)
		return (0);
	else if (str[g] != '-' && out > 2147483647)
		return (0);
	return (1);
}

static int	ft_check_double(t_swap *swap)
{
	long long	i;
	long long	g;

	i = 0;
	while (i != swap->size_a)
	{
		g = 0;
		while (g != i && swap->stack_a[g] != swap->stack_a[i])
			g++;
		if (g != i)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_all_argv(int argc, char **argv, t_swap *swap)
{
	char	*tmp;

	swap->all_numbers = ft_strdup_sp(*(++argv));
	if (swap->all_numbers == NULL)
		return (0);
	while (--argc > 1)
	{
		tmp = ft_strdup_sp(swap->all_numbers);
		free(swap->all_numbers);
		if (tmp == NULL)
			return (0);
		swap->all_numbers = ft_strjoin(tmp, *(++argv));
		free(tmp);
		if (swap->all_numbers == NULL)
			return (0);
	}
	swap->spl_numbers = ft_split(swap->all_numbers, ' ');
	free(swap->all_numbers);
	if (swap->spl_numbers == NULL)
		return (0);
	swap->size_a = 0;
	while (swap->spl_numbers[swap->size_a] != NULL)
		swap->size_a++;
	return (1);
}

int	ft_check_arguments(int argc, char **argv, t_swap *swap)
{
	long long	i;

	if (!(ft_check_all_argv(argc, argv, swap)))
		return (0);
	swap->stack_a = NULL;
	swap->stack_a = malloc(sizeof(int) * swap->size_a);
	if (swap->stack_a == NULL)
		return (0);
	i = 0;
	while (swap->spl_numbers[i] != NULL)
	{
		if (!(ft_check_argument(swap->spl_numbers[i])) || \
		!(ft_check_long_numb(swap->spl_numbers[i])))
			return (ft_free_split(swap, 0));
		swap->stack_a[i] = ft_atoi(swap->spl_numbers[i]);
		i++;
	}
	if (!(ft_check_double(swap)))
		return (ft_free_split(swap, 0));
	return (ft_free_split(swap, 1));
}
