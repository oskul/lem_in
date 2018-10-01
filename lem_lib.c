/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_lib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:28:19 by oskulska          #+#    #+#             */
/*   Updated: 2018/06/14 21:28:21 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_clear(char **arr)
{
	size_t	count;

	count = 0;
	while (arr[count])
	{
		free(arr[count]);
		arr[count] = NULL;
		count++;
	}
	free(arr);
	arr = NULL;
}

t_lemin		*ft_find_list(t_lemin *list, int id)
{
	while (list)
	{
		if (list->id == id)
			return (list);
		list = list->next;
	}
	return (list);
}

void		ft_dod_pr(t_lemin *list, int a, int id, t_all *all)
{
	t_lemin *curr;

	if (all->last_move != 0)
		write(1, " ", 1);
	curr = ft_find_list(list, id);
	write(1, "L", 1);
	ft_putnbr(a);
	write(1, "-", 1);
	ft_putstr(curr->name);
}

t_lemin		*ft_find_start(t_lemin *list)
{
	t_lemin *tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->start == 1)
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

int			is_neighbour(t_lemin *list, int neighbor_id)
{
	t_lemin	*curr;
	int		i;

	i = 0;
	curr = ft_find_list(list, list->id);
	while (i < curr->number + 1)
	{
		if (curr->neighbor[i] == neighbor_id)
			return (1);
		i++;
	}
	return (0);
}
