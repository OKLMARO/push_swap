/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:38:19 by oamairi           #+#    #+#             */
/*   Updated: 2025/07/09 12:49:34 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **a, t_list **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	swap_a(t_list **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	rotate_a(t_list **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rotate_a_b(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

void	reverse_rotate_a(t_list **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}
