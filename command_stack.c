/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:33:03 by oamairi           #+#    #+#             */
/*   Updated: 2025/07/04 01:21:46 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **c)
{
	t_list	*temp;
	t_list	*temp_next;

	if (!*c)
		return ;
	temp = *c;
	temp_next = temp->next;
	if (!temp_next)
		return;
	temp->next = temp_next->next;
	temp_next->next = temp;
}

void	push(t_list **from, t_list **to)
{
	t_list	*temp;

	temp = *from;
	ft_lstadd_front(to, temp);
	from = &temp->next;
	ft_lstdelone(temp, free);
}

void	rotate(t_list **c)
{
	t_list	*temp;
	t_list	*boucle;

	temp = *c;
	c = &temp->next;
	boucle = *c;
	while (boucle->next)
		boucle = boucle->next;
	boucle->next = temp;
}

void	reverse_rotate(t_list **c)
{
	
}
