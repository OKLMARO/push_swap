/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:54:26 by oamairi           #+#    #+#             */
/*   Updated: 2025/07/09 13:33:10 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_base(long int nb, char *base_to)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb != 0)
	{
		i++;
		nb = nb / ft_strlen(base_to);
	}
	return (i);
}

void	tri_horrible(int *L, t_list **a)
{
	int	i;
	int	temp;

	i = 0;
	while (i < ft_lstsize(*a) - 1)
	{
		if (L[i] > L[i + 1])
		{
			temp = L[i];
			L[i] = L[i + 1];
			L[i + 1] = temp;
			i = -1;
		}
		i++;
	}
}

int	*init_lstindex_bis(t_list **a)
{
	int		*L;
	t_list	*temp;
	int		i;

	L = malloc(sizeof(int) * ft_lstsize(*a));
	if (!L)
		return (0);
	temp = *a;
	i = 0;
	while (temp)
	{
		L[i] = ft_atoi(temp->content);
		i++;
		temp = temp->next;
	}
	tri_horrible(L, a);
	return (L);
}

void	init_lstindex(t_list **a)
{
	int		*L;
	t_list	*temp;
	int		i;

	L = init_lstindex_bis(a);
	i = 0;
	while (i < ft_lstsize(*a))
	{
		temp = *a;
		while (temp)
		{
			if (ft_atoi(temp->content) == L[i])
			{
				temp->index = i;
				break;
			}
			else
				temp = temp->next;
		}
		i++;
	}
	free(L);
}

void	radix_sort(t_list **a, t_list **b)
{
	int	i;
	int	count;

	init_lstindex(a);
	i = 0;
	while (i < len_base(ft_lstsize(*a) - 1, "01"));
	{
		count = 0;
		while (count < ft_lstsize(*a))
		{
			if ((((*a)->index >> i) & 1) == 0)
				push_b(b, a);
			else
				rotate_a(a);
			count++;
		}
		while (*b)
			push_a(a, b);
	}
}
