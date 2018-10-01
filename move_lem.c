/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_lem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:27:51 by oskulska          #+#    #+#             */
/*   Updated: 2018/06/14 21:27:53 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		free_ants(t_all *all)
{
	t_output	*tmp;

	tmp = all->output;
	while (tmp)
	{
		if (tmp->room != all->len - 1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int		ft_find_next_room(t_way *way, int num)
{
	int		len;
	int		i;

	i = 0;
	len = way->len;
	while (i < len)
	{
		if (way->way[i] == num)
			return (way->way[i + 1]);
		i++;
	}
	return (-1);
}

static int		room_not_free(t_output *list, int room_num, int finish)
{
	t_output	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->room == room_num && tmp->room != finish)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void			move_ants(t_all *all, t_way *way, t_output *tmp)
{
	int		i;
	int		id;

	if (tmp->room != all->len - 1)
	{
		i = 1;
		way = all->way;
		while (way && i && way->filter_way == 1)
		{
			id = ft_find_next_room(way, tmp->room);
			if ((room_not_free(all->output, id, all->len - 1) || id == -1))
				way = way->next;
			else
			{
				ft_dod_pr(all->lemin, tmp->lemin, id, all);
				all->last_move = 1;
				tmp->room = id;
				i = 0;
			}
		}
	}
}

void			output(t_all *all)
{
	t_output	*tmp;
	int			i;

	i = 0;
	ft_printf("\n");
	all->last_move = 0;
	while (free_ants(all))
	{
		tmp = all->output;
		while (tmp)
		{
			move_ants(all, all->way, tmp);
			all->ants--;
			tmp = tmp->next;
		}
		all->last_move = 0;
		ft_printf("\n");
		i++;
	}
	if (all->flag->total == 1)
		ft_printf("TOTAL STEP NUMBER %d\n", i);
}
