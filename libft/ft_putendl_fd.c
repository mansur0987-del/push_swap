/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <armaxima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:13:14 by armaxima          #+#    #+#             */
/*   Updated: 2021/10/10 14:13:15 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	c;

	if (!s || !fd)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		c = s[i++];
		write(fd, &c, 1);
	}
	c = '\n';
	write(fd, &c, 1);
}
