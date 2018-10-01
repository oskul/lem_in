/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 22:05:59 by oskulska          #+#    #+#             */
/*   Updated: 2018/06/14 22:06:00 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	get_ants_num(char *line, t_all *param)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
		{
			if (param->flag->error == 1)
				ft_printf("ANT NUMBER IS NOT CORRECT\n");
			else
				ft_printf("ERROR\n");
			exit(1);
		}
		i++;
	}
	param->ants = ft_atoi(line);
}

void		read_to_file(t_all *param)
{
	char	*line;
	char	**file;
	int		y;
	int		res;

	y = 0;
	file = malloc(sizeof(char**) * 600000);
	while ((res = get_next_line(0, &line)) > 0)
	{
		file[y] = line;
		y++;
	}
	if (res == -1)
	{
		ft_printf("ERROR READING FILE\n");
		exit(1);
	}
	file[y] = 0;
	param->file_len = y;
	param->file = file;
	parce_map(param, file, NULL, -1);
}

void		parce_map(t_all *all, char **str, char **map, int y)
{
	while (++y < all->file_len)
	{
		while (str[y] && str[y][0] == '#' && !ft_strequ(str[y], "##start")
			&& !ft_strequ(str[y], "##end"))
			y++;
		if (str[y] && all->ants == 0)
			get_ants_num(str[y], all);
		else if (str[y] && ft_strchr(str[y], ' ') && all->room_readed == 0
				&& ft_check_cord(str[y], all->lemin) == 0)
			all->lemin = ft_find_room(str[y], 0, 0, all->lemin);
		else if (str[y] && ft_strchr(str[y], '-') && conect(str[y]) == 0 &&
				(all->end || all->start))
		{
			if ((all->len = check_room_con(str[y], all)) == -1)
				break ;
			map == NULL ? map = create_map(map, all->lemin, all) : map;
			fill_map(str[y], map, all->lemin);
		}
		else
		{
			if (main_parce(str, &y, all) == -1)
				break ;
		}
	}
	main_check(str, all, map, y);
}

void		is_start_end(char **map, t_lemin *list)
{
	int		len;
	t_lemin	*tmp;

	len = 1;
	tmp = list;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	if (len <= 2 || map == NULL)
	{
		ft_printf("ERROR\n");
		exit(1);
	}
}

int			cln(char **arr, int a)
{
	ft_clear(arr);
	return (a);
}
