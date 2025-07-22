/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:54:26 by oamairi           #+#    #+#             */
/*   Updated: 2025/07/22 17:19:41 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_duplicate(t_list **a)
{
	t_list	*current;
	t_list	*next;

	current = *a;
	while (current)
	{
		next = current->next;
		while (next)
		{
			if (ft_atoi(current->content) == ft_atoi(next->content))
				return (0);
			next = next->next;
		}
		current = current->next;
	}
	return (1);
}

void	radix_sort(t_list **a, t_list **b)
{
	int	i;
	int	count;
	int	max;
	int	size_a;

	size_a = ft_lstsize(*a);
	init_lstindex(a);
	i = 0;
	max = len_base(size_a - 1, "01");
	while (i < max)
	{
		count = 0;
		size_a = ft_lstsize(*a);
		while (count < size_a && *a)
		{
			if ((((*a)->index >> i) & 1) == 0)
				push_b(b, a);
			else
				rotate_a(a);
			count++;
		}
		while (*b)
			push_a(a, b);
		i++;
	}
}
