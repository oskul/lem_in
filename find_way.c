/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:28:55 by oskulska          #+#    #+#             */
/*   Updated: 2018/06/14 21:28:57 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_way(t_all *all)
{
	t_way	*tmp;
	t_lemin	*curr;
	int		i;

	tmp = all->way;
	while (tmp)
	{
		i = 0;
		ft_printf("POSSIBLE WAY FOUNDED\n");
		while (i < tmp->len)
		{
			curr = ft_find_list(all->lemin, tmp->way[i]);
			ft_printf("Room name: %s\n", curr->name);
			i++;
		}
		ft_printf("-----------\n");
		ft_printf("Total len %d\n\n", tmp->len);
		tmp = tmp->next;
	}
}

void	find_all_way(char **map, t_all *all)
{
	t_lemin	*tmp;
	t_way	*new;
	int		len;
	int		y;

	new = NULL;
	len = all->len;
	while (1)
	{
		tmp = all->lemin;
		all->map = map;
		y = len - 1;
		reset_pass(all->lemin);
		find_pass(all, y, len, 0);
		if (create_way_list(tmp, &new) == -1)
			break ;
		map = reset_map(all->lemin, map, len);
	}
	check_way(new, all);
	all->way = new;
	if (all->flag->way == 1)
		print_way(all);
}

int		create_way_list(t_lemin *list, t_way **way)
{
	t_lemin	*start;
	t_way	*way_tmp;
	t_way	*new_node;

	start = ft_find_start(list);
	if (start->pass < 0)
		return (-1);
	new_node = create_node_way(start->pass);
	ft_find_way(list, new_node, 1, 1);
	if (*way == NULL)
		*way = new_node;
	else
	{
		way_tmp = *way;
		while (way_tmp->next)
			way_tmp = way_tmp->next;
		way_tmp->next = new_node;
	}
	if (ft_find_way(list, new_node, 1, 1) < start->pass)
		return (-1);
	return (0);
}

int		ft_find_way(t_lemin *list, t_way *new_node, int i, int k)
{
	t_lemin	*copy;
	t_lemin	*start;
	t_lemin	*prev;

	start = ft_find_start(list);
	copy = list;
	prev = start;
	while (list)
		if (is_neighbour(list, prev->id) != 0)
		{
			fill_end_start(list, new_node, start);
			if (list->pass > 0 && list->pass + i == start->pass)
			{
				new_node->way[k++] = list->id;
				list->way = 1;
				i++;
				prev = list;
				list = copy;
			}
			else
				list = list->next;
		}
		else
			list = list->next;
	return (k);
}

void	filter_way(t_all *all, t_way *way)
{
	int	l;
	int	a;
	int	k;
	int	an;

	a = 1;
	k = 0;
	an = all->ants;
	if (way != NULL)
		l = way->len;
	while (an > 0)
	{
		an -= a;
		while (an && way->next && (l + k == way->next->len))
		{
			way->filter_way = 1;
			an--;
			a++;
			way = way->next;
		}
		k++;
		way->filter_way = 1;
	}
	if (way->next)
		way->next->filter_way = 0;
}
