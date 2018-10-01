/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:27:27 by oskulska          #+#    #+#             */
/*   Updated: 2018/06/14 21:27:29 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		param_start(t_all *param, char *str)
{
	param->start = 1;
	if (ft_check_cord(str, param->lemin) == 0)
	{
		param->lemin = ft_find_room(str, 1, 0, param->lemin);
		return (0);
	}
	else
		return (-1);
}

static int		param_end(t_all *param, char *str)
{
	param->end = 1;
	if (ft_check_cord(str, param->lemin) == 0)
	{
		param->lemin = ft_find_room(str, 0, 1, param->lemin);
		return (0);
	}
	else
		return (-1);
}

int				main_parce(char **str, int *y, t_all *param)
{
	if (str[*y] && ft_strequ(str[*y], "##start") && param->start == 0)
	{
		(*y)++;
		while (str[*y] && str[*y][0] == '#')
			(*y)++;
		if (param_start(param, str[*y]) == -1)
			return (-1);
	}
	else if (str[*y] && ft_strequ(str[*y], "##end") && param->end == 0)
	{
		(*y)++;
		while (str[*y] && str[*y][0] == '#')
			(*y)++;
		if (param_end(param, str[*y]) == -1)
			return (-1);
	}
	else if (!(str[*y] && str[*y][0] == '#' && str[*y][1] == '#'
		&& !ft_strequ(str[*y], "##start")
		&& !ft_strequ(str[*y], "##end")))
		return (-1);
	return (0);
}

void			main_check(char **str, t_all *param, char **map, int y)
{
	int	i;

	i = 0;
	param->real_len = y;
	is_start_end(map, param->lemin);
	check_end_start_con(map, param);
	find_neighbour(map, param);
	find_all_way(map, param);
	filter_way(param, param->way);
	if (param->flag->filter == 1)
	{
		ft_printf("FILTERED WAY\n\n");
		print_filter_way(param);
	}
	if (param->way)
		while (i < y)
		{
			ft_printf("%s\n", param->file[i]);
			i++;
		}
	param->output = create_lemin(param);
	output(param);
	ft_clear(str);
	if (map)
		ft_clear(map);
}

int				main(int argc, char **argv)
{
	t_all	*param;
	int		i;

	i = 0;
	param = init_struct();
	if (argc > 2)
	{
		ft_printf("This is the help for lem-in\n""Options are:\n"
			"    -w: display all finded ways\n"
			"    -l: display leaks\n"
			"    -t: display total step\n"
			"    -f: show all filtered way\n"
			"    -e: extended error management\n");
		exit(1);
	}
	if (argc != 1)
		while (++i < argc)
			check_flag(param, argv[i]);
	read_to_file(param);
	if (param->flag->leaks == 1)
		system("leaks lem-in > leaks.txt");
	return (0);
}
