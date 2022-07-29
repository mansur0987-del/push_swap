/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <armaxima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:13:26 by armaxima          #+#    #+#             */
/*   Updated: 2021/10/13 21:11:11 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_me(char *str, size_t len)
{
	char	*putout;
	int		i;

	if (!str)
		return (NULL);
	putout = malloc(sizeof(char) * len + 1);
	if (putout == NULL)
		return (NULL);
	i = 0;
	while (len-- > 0 && str[i] != '\0')
	{
		putout[i] = str[i];
		i++;
	}
	putout[i] = '\0';
	return (putout);
}

void	ft_free_all(char **out_split, long how_element)
{
	long	i;

	i = 0;
	while (how_element-- > 0)
	{
		free(out_split[i]);
		i++;
	}
	free(out_split);
}

char	*ft_search_element(char const *s, char c, long numb_elem)
{
	long	i;
	long	numb_split;
	long	start;

	numb_split = 0;
	start = 0;
	i = 0;
	while (s[i] && numb_split <= numb_elem)
	{
		while (s[i] && s[i] == c)
			++i;
		start = i;
		while (s[i] && s[i] != c)
			++i;
		++numb_split;
	}
	return (ft_strdup_me((char *)s + start, (size_t)i - start));
}

long	ft_how_element(char const *s, char c)
{
	long	how_element;
	long	flag;
	long	i;

	i = 0;
	flag = 0;
	how_element = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			how_element++;
		}
		if (s[i++] == c)
			flag = 0;
	}
	return (how_element);
}

char	**ft_split(char const *s, char c)
{
	char	**out_split;
	long	how_element;
	long	numb_elem;

	if (!s)
		return (NULL);
	how_element = ft_how_element(s, c);
	out_split = (char **)malloc(sizeof(char *) * (how_element + 1));
	if (out_split == NULL)
		return (NULL);
	numb_elem = 0;
	while (numb_elem < how_element)
	{
		out_split[numb_elem] = ft_search_element(s, c, numb_elem);
		if (out_split[numb_elem] == NULL)
		{
			ft_free_all(out_split, numb_elem);
			return (NULL);
		}
		numb_elem++;
	}
	out_split[numb_elem] = NULL;
	return (out_split);
}
