/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:13:18 by armaxima          #+#    #+#             */
/*   Updated: 2021/11/26 11:00:53 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (!fd)
		return ;
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
	}
	while (n >= 10)
	{
		ft_putnbr_fd (n / 10, fd);
		break ;
	}
	ft_putchar_fd(n % 10 + '0', fd);
}
