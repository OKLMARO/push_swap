/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:33:03 by oamairi           #+#    #+#             */
/*   Updated: 2025/07/05 17:35:12 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **c)
{
	char	*temp;

	if (*c && (*c)->next)
	{
		temp = (*c)->content;
		(*c)->content = (*c)->next->content;
		(*c)->next->content = temp;
	}
	else
		return ;
}

void	push(t_list **from, t_list **to)
{
	t_list	*temp;

	if (*from)
	{
		temp = *from;
		*from = (*from)->next;
		ft_lstadd_front(to, temp);
	}
}

void	rotate(t_list **c)
{
	t_list	*first;

	if (!*c)
		return ;
	first = *c;
	*c = first->next;
	first->next = NULL;
	ft_lstadd_back(c, first);
}

void	reverse_rotate(t_list **c)
{
	t_list	*avant_der;
	t_list	*last;

	last = *c;
	avant_der = *c;
	while (last->next)
		last = last->next;
	while (avant_der->next->next)
		avant_der = avant_der->next;
	avant_der->next = NULL;
	last->next = *c;
	*c = last;
}
