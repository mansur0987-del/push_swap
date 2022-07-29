/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <armaxima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:13:44 by armaxima          #+#    #+#             */
/*   Updated: 2021/10/10 14:13:45 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*output;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	output = (char *) malloc (sizeof(char) * (len_s1 + len_s2) + 1);
	if (output == NULL)
		return (NULL);
	len_s2 = -1;
	while (s1[++len_s2] != '\0')
		output[len_s2] = s1[len_s2];
	len_s2 = 0;
	while (s2[len_s2] != '\0')
		output[len_s1++] = s2[len_s2++];
	output[len_s1] = '\0';
	return (output);
}
