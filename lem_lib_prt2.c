/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_lib_prt2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:37:29 by oskulska          #+#    #+#             */
/*   Updated: 2018/06/15 18:37:31 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		fill_end_start(t_lemin *list, t_way *new_node, t_lemin *start)
{
	if (list->pass == 0)
	{
		list->way = 1;
		new_node->way[start->pass] = list->id;
	}
	if (list->start == 1)
	{
		list->way = 1;
		new_node->way[0] = list->id;
	}
}

void		reset_pass(t_lemin *list)
{
	t_lemin	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->end == 1)
			tmp->pass = 0;
		else
			tmp->pass = -1;
		tmp = tmp->next;
	}
}

void		print_filter_way(t_all *all)
{
	t_way	*tmp;
	t_lemin	*curr;
	int		i;

	tmp = all->way;
	while (tmp)
	{
		i = 0;
		while (i < tmp->len && tmp->filter_way == 1)
		{
			curr = ft_find_list(all->lemin, tmp->way[i]);
			ft_printf("Room name: %s\n", curr->name);
			i++;
		}
		if (tmp->filter_way == 1)
			ft_printf("Total way len: %d\n\n", tmp->len);
		tmp = tmp->next;
	}
}

void		check_flag(t_all *param, char *str)
{
	if (ft_strequ(str, "-w"))
		param->flag->way = 1;
	else if (ft_strequ(str, "-l"))
		param->flag->leaks = 1;
	else if (ft_strequ(str, "-f"))
		param->flag->filter = 1;
	else if (ft_strequ(str, "-t"))
		param->flag->total = 1;
	else if (ft_strequ(str, "-e"))
		param->flag->error = 1;
	else
	{
		ft_printf("This is the help for lem-in\n"
			"Options are:\n"
			"    -w: display all finded ways\n"
			"    -l: display leaks\n"
			"    -t: display total step\n"
			"    -f: show all filtered way\n"
			"    -e: extended error management\n");
		exit(1);
	}
	if (param->flag->leaks == 1)
		ft_printf("open leaks.txt to check leaks\n");
}

int			check_room_con(char *line, t_all *all)
{
	t_lemin	*tmp;
	int		cor;
	int		len;
	char	**str;

	len = 0;
	cor = 0;
	all->room_readed = 1;
	str = ft_strsplit(line, '-');
	tmp = all->lemin;
	while (tmp)
	{
		if (ft_strequ(tmp->name, str[0]))
			cor++;
		if (ft_strequ(tmp->name, str[1]))
			cor++;
		len++;
		tmp = tmp->next;
	}
	if (str[0] == str[1] || cor == 1 || cor == 0)
		return (cln(str, -1));
	return (cln(str, len));
}
