/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:20:49 by oamairi           #+#    #+#             */
/*   Updated: 2025/06/24 22:47:37 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_argv_bis(int argc, char **argv)
{
	int	i;
	int j;

	i = 1;
	while (i < argc)
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
	return (1);
}

int	verify_argv(int argc, char **argv)
{
	char	**res;
	int		i;
	int		j;
	
	if (argc == 2)
	{
		res = ft_split(argv[1], ' ');
		j = 0;
		while (res[j])
		{
			i = 0;
			while (res[j][i])
			{
				if (!ft_isdigit(res[j][i]))
					return (free(res), 0);
				i++;
			}
			j++;
		}
		return (free(res), 1);
	}
	return (verify_argv_bis(argc, argv));
}

int	main(int argc, char **argv)
{
	//char	*a;

	if (argc <= 1)
		return (1);
	if (!verify_argv(argc, argv))
	{
		ft_printf("Error");
		return (1);
	}
	return (0);
}