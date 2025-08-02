/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:53:07 by oamairi           #+#    #+#             */
/*   Updated: 2025/08/02 17:05:38 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_function(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) <= 1)
		return (ft_lstclear(b, free),
			ft_lstclear(a, free), free(b), free(a));
	if (ft_lstsize(*a) == 2)
		return (sort_two(a), ft_lstclear(b, free),
			ft_lstclear(a, free), free(b), free(a));
	if (ft_lstsize(*a) == 3)
		return (sort_three(a), ft_lstclear(b, free),
			ft_lstclear(a, free), free(b), free(a));
	if (ft_lstsize(*a) == 5)
		return (sort_five(a, b), ft_lstclear(b, free),
			ft_lstclear(a, free), free(b), free(a));
	return (radix_sort(a, b), ft_lstclear(b, free),
		ft_lstclear(a, free), free(b), free(a));
}
