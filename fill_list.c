/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:27:37 by oskulska          #+#    #+#             */
/*   Updated: 2018/06/14 21:27:39 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_output	*create_lemin(t_all *param)
{
	t_output	*newlist;
	t_output	*tmp;
	t_output	*tmp_next;
	int			i;

	i = 2;
	tmp = create_lemin_new_node();
	tmp->lemin = 1;
	tmp->room = 0;
	newlist = tmp;
	while (i <= param->ants)
	{
		tmp_next = create_lemin_new_node();
		tmp_next->lemin = i;
		tmp_next->room = 0;
		tmp->next = tmp_next;
		tmp = tmp->next;
		i++;
	}
	return (newlist);
}

void		ft_fill_list(t_lemin *list, char *line, int start, int end)
{
	char	**str;

	str = ft_strsplit(line, ' ');
	list->name = ft_strdup(str[0]);
	list->x = ft_atoi(str[1]);
	list->y = ft_atoi(str[2]);
	list->start = start;
	list->end = end;
	list->way = 0;
	if (list->end == 1)
		list->pass = 0;
	else
		list->pass = -1;
	ft_clear(str);
}

void		add_id(t_lemin *list, t_all *param)
{
	int		id;

	id = 1;
	while (list)
	{
		list->id = id;
		if (list->start == 1)
			list->id = 0;
		else if (list->end == 1)
			list->id = param->len - 1;
		else if (!list->end && !list->start)
		{
			list->id = id;
			id++;
		}
		list = list->next;
	}
}

static void	output2(t_all *all, char **map)
{
	t_lemin		*curr;
	int			i;
	int			k;

	i = 1;
	k = -1;
	while (++k < all->real_len)
		ft_printf("%s\n", all->file[k]);
	ft_printf("\n");
	curr = ft_find_list(all->lemin, all->len - 1);
	while (i <= all->ants)
	{
		write(1, "L", 1);
		ft_putnbr(i);
		write(1, "-", 1);
		ft_putstr(curr->name);
		if (i < all->ants)
			write(1, " ", 1);
		i++;
	}
	ft_printf("\n");
	ft_clear(map);
	exit(1);
}

void		find_neighbour(char **map, t_all *param)
{
	int		x;
	int		y;
	int		id;
	t_lemin	*tmp;
	t_lemin	*curr;

	y = -1;
	tmp = param->lemin;
	if (map[0][param->len - 1] == '1')
		output2(param, map);
	while (++y < param->len)
	{
		x = -1;
		id = 0;
		while (++x < param->len)
			if (map[y][x] == '1')
			{
				curr = ft_find_list(tmp, y);
				curr->neighbor[id] = x;
				curr->number = id;
				id++;
			}
	}
}
