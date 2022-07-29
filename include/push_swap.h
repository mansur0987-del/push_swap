/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armaxima <<armaxima@student.42.fr>>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:06:16 by armaxima          #+#    #+#             */
/*   Updated: 2021/12/02 12:00:07 by armaxima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_lst
{
	int				numb;
	int				move;
	struct s_lst	*down;
	struct s_lst	*up;
}					t_lst;

typedef struct s_swap
{
	int		*stack_a;
	int		size_a;
	t_lst	*lst_a;
	int		size_b;
	t_lst	*lst_b;
	int		big;
	int		small;
	int		mid;
	char	*all_numbers;
	char	**spl_numbers;
}			t_swap;

int		ft_error(char *str);
int		ft_free(t_swap *swap, char *str);
int		ft_free_split(t_swap *swap, int result);
int		ft_free_al(t_swap *swap, char *str);
int		ft_check_arguments(int argc, char **argv, t_swap *swap);
int		ft_create_stack_b(t_swap *swap);
char	*ft_strdup_sp(const char *src);
t_lst	*ft_cr_lst(int numb);
void	ft_put_list_down(t_lst **list, t_lst *new);
void	ft_last_lst(t_lst **list);
int		ft_creat_a_list(t_swap *swap);
int		ft_find_flags(t_swap *swap);
t_lst	*ft_up_a(t_lst *lst);
t_lst	*ft_down_a(t_lst *lst);
t_lst	*ft_up_b(t_lst *lst);
t_lst	*ft_down_b(t_lst *lst);
t_lst	*ft_move(t_swap *sw, t_lst *lst_a);
t_lst	*ft_clear_stack(t_lst **lst);
int		ft_move_small(t_swap *sw);
void	ft_put_move(t_swap *sw, t_lst *lst_a);
t_lst	*ft_find_near_b(t_lst *lst_down, t_lst *lst_up, int score);
t_lst	*ft_find_finish(t_lst *lst_down, t_lst *lst_up, int numb);
t_lst	*ft_find_small(t_lst *lst_down, t_lst *lst_up, int numb);
void	ft_swap(int *a, int *b);
int		find_score(t_swap *sw);

#endif
