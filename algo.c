/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:54:26 by oamairi           #+#    #+#             */
/*   Updated: 2025/07/09 00:00:52 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	
}