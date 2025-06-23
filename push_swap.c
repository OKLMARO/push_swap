/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:20:49 by oamairi           #+#    #+#             */
/*   Updated: 2025/06/23 21:45:17 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char**	make_a_bis(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (argv);
}

char**	make_a(int argc, char **argv)
{
	char	**res;
	int		i;
	int		j;

	if (argc == 2)
	{
		res = ft_split(argv, ' ');
		if (!res)
			return (0);
		i = 0;
		while (res[i])
		{
			j = 0;
			while (res[i][j])
			{
				if (!ft_isdigit(res[i][j]))
				{
					free_a(res);
					return (0);
				}
				j++;
			}
			i++;
		}
	}
	else
	{
		return (make_a_bis(argv));
	}
	return (res);
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