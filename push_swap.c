/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:20:49 by oamairi           #+#    #+#             */
/*   Updated: 2025/07/12 13:05:29 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_argv_bis(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' && argv[i][j + 1])
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (i - 1);
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
			if (res[j][i] == '-' && res[j][i + 1])
				i++;
			while (res[j][i])
			{
				if (!ft_isdigit(res[j][i]))
					return (free_double(res), 0);
				i++;
			}
			j++;
		}
		return (free_double(res), j);
	}
	return (verify_argv_bis(argc, argv));
}

int	make_storage_bis(char **argv, t_list **a)
{
	int		i;
	t_list	*temp_lst;

	i = 1;
	while (argv[i])
	{
		temp_lst = ft_lstnew(ft_strdup(argv[i]));
		if (!temp_lst)
			return (ft_lstclear(a, free), 0);
		ft_lstadd_back(a, temp_lst);
		i++;
	}
	return (i);
}

int	make_storage(int argc, char **argv, t_list **a)
{
	char	**temp;
	int		i;
	t_list	*temp_lst;

	if (argc == 2)
	{
		temp = ft_split(argv[1], ' ');
		i = 0;
		while (temp[i])
		{
			temp_lst = ft_lstnew(ft_strdup(temp[i]));
			if (!temp_lst)
				return (ft_lstclear(a, free), 0);
			ft_lstadd_back(a, temp_lst);
			i++;
		}
		return (free_double(temp), 1);
	}
	return (make_storage_bis(argv, a));
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;
	int		taille;

	if (argc <= 1)
		return (1);
	taille = verify_argv(argc, argv);
	if (!taille)
	{
		ft_printf("Error");
		return (1);
	}
	a = malloc(sizeof(t_list));
	*a = NULL;
	b = malloc(sizeof(t_list));
	*b = NULL;
	make_storage(argc, argv, a);
	radix_sort(a, b);
	ft_lstclear(a, free);
	ft_lstclear(b, free);
	free(a);
	free(b);
	return (0);
}
