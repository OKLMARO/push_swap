/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 02:35:29 by oamairi           #+#    #+#             */
/*   Updated: 2025/07/11 03:41:30 by oamairi          ###   ########.fr       */
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
	int		*l;
	t_list	*temp;
	int		i;

	l = malloc(sizeof(int) * ft_lstsize(*a));
	if (!l)
		return (0);
	temp = *a;
	i = 0;
	while (temp)
	{
		l[i] = ft_atoi(temp->content);
		i++;
		temp = temp->next;
	}
	tri_horrible(l, a);
	return (l);
}

void	init_lstindex(t_list **a)
{
	int		*l;
	t_list	*temp;
	int		i;

	l = init_lstindex_bis(a);
	i = 0;
	while (i < ft_lstsize(*a))
	{
		temp = *a;
		while (temp)
		{
			if (ft_atoi(temp->content) == l[i])
			{
				temp->index = i;
				break ;
			}
			else
				temp = temp->next;
		}
		i++;
	}
	free(l);
}

void	free_double(char **tab_str)
{
	int	i;

	i = 0;
	while (tab_str[i])
	{
		free(tab_str[i]);
		i++;
	}
	free(tab_str);
}
