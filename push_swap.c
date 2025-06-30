/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:20:49 by oamairi           #+#    #+#             */
/*   Updated: 2025/06/30 12:58:24 by oamairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	free_double(char **tab_str)
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

int	make_storage(int argc, char **argv, t_list *a)
{
	char	**temp;
	int		i;
	int		*temp_int;
	t_list	*temp_lst;

	if (argc == 2)
	{
		temp = ft_split(argv[1], ' ');
		i = 0;
		while (temp[i])
		{
			temp_int = malloc(sizeof(int));
			if (!temp_int)
				return (ft_lstclear(&a, free), 0);
			temp_int[0] = ft_atoi(temp[i]);
			temp_lst = ft_lstnew(temp_int);
			if (!temp_lst)
				return (ft_lstclear(&a, free), 0);
			ft_lstadd_back(&a, temp_lst);
			free(temp_lst);
			i++;
		}
		return (1);
	}
	i = 1;
	while (argv[i])
	{
		temp_int = malloc(sizeof(int));
		if (!temp_int)
			return (ft_lstclear(&a, free), 0);
		temp_int[0] = ft_atoi(temp[i]);
		temp_lst = ft_lstnew(temp_int);
		if (!temp_lst)
			return (ft_lstclear(&a, free), 0);
		ft_lstadd_back(&a, temp_lst);
		free(temp_lst);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		taille;

	if (argc <= 1)
		return (1);
	taille = verify_argv(argc, argv);
	if (!taille)
	{
		ft_printf("Error");
		return (1);
	}
	make_storage(argc, argv, a);
	int i = 0;
	t_list *temp = a;
	while (temp)
	{
		int *temp_int = temp->content;
		ft_printf("%d", *temp_int);
		temp = temp->next;
	}
	return (0);
}
