/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:54:26 by oamairi           #+#    #+#             */
/*   Updated: 2025/07/11 03:18:56 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		while (count < size_a)
		{
			if ((((*a)->index >> i) & 1) == 0)
				push_b(b, a);
			else
				rotate_a(a);
			count++;
		}
		push_a(a, b);
		i++;
	}
}
