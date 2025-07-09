/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:37:51 by oamairi           #+#    #+#             */
/*   Updated: 2025/07/09 12:52:20 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_list **b, t_list **a)
{
	push(a, b);
	ft_printf("pb\n");
}

void	swap_b(t_list **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	rotate_b(t_list **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	reverse_rotate_b(t_list **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	reverse_rotate_a_b(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
