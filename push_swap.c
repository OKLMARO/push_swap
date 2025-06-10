/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:20:49 by oamairi           #+#    #+#             */
/*   Updated: 2025/06/10 16:23:10 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_a(int argc, char **argv)
{
	char	**res_2;
	int		i;

	if (argc == 2)
	{
		res_2 = ft_split(argv, ' ');
		if (!res_2)
			return (0);
		i = 0;
		while (res_2[i][0])
		{
			if (!ft_isdigit(res_2[i][0]))
			{
				free()
			}
		}
		
	}
}

int	main(int argc, char **argv)
{
	char	*a;
	if (argc >= 1)
		return (1);
	if (!make_a(argc, argv))
	{
		ft_printf("Error");
		return (1);
	}
}