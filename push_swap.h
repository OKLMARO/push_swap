/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:30:38 by oamairi           #+#    #+#             */
/*   Updated: 2025/09/15 17:03:39 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <limits.h>

void	swap(t_list **c);
void	push(t_list **from, t_list **to);
void	rotate(t_list **c);
void	reverse_rotate(t_list **c);
void	push_b(t_list **b, t_list **a);
void	swap_b(t_list **b);
void	rotate_b(t_list **b);
void	reverse_rotate_b(t_list **b);
void	reverse_rotate_a_b(t_list **a, t_list **b);
void	push_a(t_list **a, t_list **b);
void	swap_a(t_list **a);
void	rotate_a(t_list **a);
void	rotate_a_b(t_list **a, t_list **b);
void	reverse_rotate_a(t_list **a);
void	init_lstindex(t_list **a);
int		*init_lstindex_bis(t_list **a);
void	tri_horrible(int *L, t_list **a);
int		len_base(long int nb, char *base_to);
void	radix_sort(t_list **a, t_list **b);
void	free_double(char **tab_str);
int		verify_duplicate(t_list **a);
void	sort_five(t_list **a, t_list **b);
void	sort_three(t_list **a);
void	sort_two(t_list **a);
void	sorting_function(t_list **a, t_list **b);
int		is_sort(t_list **a);

#endif