/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:54:26 by oamairi           #+#    #+#             */
/*   Updated: 2025/08/02 17:16:33 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_list **a)
{
	int		min;
	int		pos;
	int		i;
	t_list	*temp;

	pos = 0;
	i = 0;
	temp = *a;
	min = temp->index;
	while (temp)
	{
		if (temp->index < min)
		{
			pos = i;
			min = temp->index;
		}
		temp = temp->next;
		i++;
	}
	return (pos);
}

void	sort_two(t_list **a)
{
	if ((*a)->index > (*a)->next->index)
		swap_a(a);
}

void	sort_three(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = ft_atoi((*a)->content);
	second = ft_atoi((*a)->next->content);
	third = ft_atoi((*a)->next->next->content);
	if ((first > second) && (second < third) && (first < third))
		swap_a(a);
	else if ((first > second) && (second > third))
		(swap_a(a), reverse_rotate_a(a));
	else if ((first > second) && (second < third) && (first > third))
		rotate_a(a);
	else if ((first < second) && (second > third) && (first < third))
		(swap_a(a), rotate_a(a));
	else if ((first < second) && (second > third) && (first > third))
		reverse_rotate_a(a);
}

void	sort_five(t_list **a, t_list **b)
{
	int	pos;

	while (ft_lstsize(*a) > 3)
	{
		pos = find_min_pos(a);
		if (pos == 0)
			push_b(b, a);
		else if (pos <= ft_lstsize(*a) / 2)
		{
			while (pos-- > 0)
				rotate_a(a);
			push_b(b, a);
		}
		else
		{
			pos = ft_lstsize(*a) - pos;
			while (pos-- > 0)
				reverse_rotate_a(a);
			push_b(b, a);
		}
	}
	sort_three(a);
	if ((*b)->index < (*b)->next->index)
		swap_b(b);
	(push_a(a, b), push_a(a, b));
}

void	radix_sort(t_list **a, t_list **b)
{
	int	i;
	int	count;
	int	max;
	int	size_a;

	size_a = ft_lstsize(*a);
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
