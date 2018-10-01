/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:27:18 by oskulska          #+#    #+#             */
/*   Updated: 2018/06/14 21:27:21 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		**create_map(char **con_map, t_lemin *list, t_all *param)
{
	int	i;
	int	x;
	int	y;

	y = 0;
	i = -1;
	param->room_readed = 1;
	if (con_map == NULL)
	{
		add_id(list, param);
		con_map = (char **)malloc(sizeof(char *) * (param->len + 1));
		con_map[param->len] = NULL;
		while (++i < param->len)
			con_map[i] = ft_strnew(param->len);
		while (y < param->len)
		{
			x = -1;
			while (++x < param->len)
				con_map[y][x] = '0';
			y++;
		}
	}
	return (con_map);
}

static void	fill_map_2(char *a, char *b, char **con_map, t_lemin *list)
{
	t_lemin	*l;
	t_lemin	*tmp;

	tmp = list;
	while (tmp)
	{
		l = list;
		if (ft_strequ(tmp->name, a))
			while (l)
			{
				if (ft_strequ(l->name, b))
					con_map[tmp->id][l->id] = '1';
				l = l->next;
			}
		tmp = tmp->next;
	}
}

char		**fill_map(char *line, char **con_map, t_lemin *list)
{
	t_lemin	*tmp;
	t_lemin	*l;
	char	**str;

	str = ft_strsplit(line, '-');
	tmp = list;
	fill_map_2(str[0], str[1], con_map, tmp);
	while (tmp)
	{
		l = list;
		if (ft_strequ(tmp->name, str[1]))
			while (l)
			{
				if (ft_strequ(l->name, str[0]))
					con_map[tmp->id][l->id] = '1';
				l = l->next;
			}
		tmp = tmp->next;
	}
	ft_clear(str);
	return (con_map);
}

char		**reset_map(t_lemin *list, char **map, int len)
{
	int		y;
	int		x;
	t_lemin	*tmp;

	y = -1;
	while (++y < len)
	{
		x = len;
		while (--x > 0)
			if (map[y][x] == '1')
			{
				tmp = ft_find_list(list, x);
				if (tmp->id == x && tmp->way == 1 && !tmp->start && !tmp->end)
					map[y][x] = '0';
			}
	}
	tmp = list;
	while (tmp)
	{
		if (tmp->way == 1 && !tmp->start && !tmp->end)
			map[tmp->id] = ft_memset(map[tmp->id], '0', len);
		tmp = tmp->next;
	}
	return (map);
}

void		find_pass(t_all *all, int x, int len, int i)
{
	t_lemin	*curr_list;
	int		y;

	y = -1;
	curr_list = ft_find_list(all->lemin, x);
	curr_list->pass = i;
	while (++y < len)
	{
		if (all->map[y][x] == '1')
		{
			curr_list = ft_find_list(all->lemin, y);
			if (curr_list->pass == -1 || curr_list->pass > i + 1)
				curr_list->pass = i + 1;
		}
	}
	y = -1;
	while (++y < len)
	{
		if (all->map[y][x] == '1')
		{
			curr_list = ft_find_list(all->lemin, y);
			if (curr_list->pass == i + 1)
				find_pass(all, y, len, i + 1);
		}
	}
}
