/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <armaxima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:12:46 by armaxima          #+#    #+#             */
/*   Updated: 2021/10/13 21:08:19 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_struct;

	new_struct = malloc (sizeof(t_list));
	if (new_struct == NULL)
		return (NULL);
	new_struct->content = content;
	new_struct->next = NULL;
	return (new_struct);
}
