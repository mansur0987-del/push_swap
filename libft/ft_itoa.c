/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mansurkakushkin <mansurkakushkin@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:12:37 by armaxima          #+#    #+#             */
/*   Updated: 2021/10/13 13:57:59 by mansurkakus      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_len_malloc(int n)
{
	int		i;
	char	*output;

	i = 1;
	if (n < 0)
		i++;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		i++;
	}
	output = malloc(sizeof(char) * i + 1);
	if (output == NULL)
		return (NULL);
	output[i] = '\0';
	while (i-- > 0)
		output[i] = '.';
	return (output);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*outp;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	outp = ft_len_malloc(n);
	if (outp == NULL)
		return (NULL);
	if (n < 0)
	{
		outp[0] = '-';
		n = -n;
	}
	len = ft_strlen(outp);
	while (outp[0] == '.' || (outp[0] == '-' && outp[1] == '.'))
	{
		outp[--len] = n % 10 + '0';
		n = n / 10;
	}
	return (outp);
}
