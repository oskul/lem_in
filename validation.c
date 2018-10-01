/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:28:02 by oskulska          #+#    #+#             */
/*   Updated: 2018/06/14 21:28:04 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		check_conection_end_start(char **map, t_all *param)
{
	int	x;
	int	x_c;
	int	y_c;

	x = 0;
	x_c = 0;
	y_c = 0;
	while (x < param->len)
	{
		if (map[param->len - 1][x] == '1')
			x_c++;
		if (map[0][x] == '1')
			y_c++;
		x++;
	}
	if (x_c == 0 || y_c == 0)
	{
		if (param->flag->error == 1)
			ft_printf("NO CONECTION WITH START OR END\n");
		else
			ft_printf("ERROR\n");
		exit(1);
	}
}

void			check_end_start_con(char **map, t_all *param)
{
	if (param->end == 0 || param->start == 0)
	{
		if (param->flag->error == 1)
			ft_printf("NO END OR START\n");
		else
			ft_printf("ERROR\n");
		exit(1);
	}
	check_conection_end_start(map, param);
}

static int		ft_check_cord_2(char **arr, int x)
{
	int	y;

	y = 1;
	while (arr[1][x])
	{
		if (ft_isdigit(arr[y][x]))
			x++;
		else
			return (-1);
		x++;
	}
	x = 0;
	if (arr[2])
		while (arr[2][x])
		{
			if (ft_isdigit(arr[2][x]))
				x++;
			else
				return (-1);
			x++;
		}
	else
		return (-1);
	return (0);
}

int				ft_check_cord(char *str, t_lemin *list)
{
	t_lemin	*tmp;
	char	**arr;

	arr = ft_strsplit(str, ' ');
	if (arr[1] == NULL || arr[0] == NULL ||
		arr[0][0] == 'L' || arr[0][0] == '#' || ft_strchr(arr[0], '-')
		|| arr[3] != NULL)
		return (cln(arr, -1));
	if (ft_check_cord_2(arr, 0) == -1)
		return (cln(arr, -1));
	tmp = list;
	if (tmp != NULL)
		while (tmp)
		{
			if (ft_strequ(tmp->name, arr[0]))
				return (cln(arr, -1));
			if (tmp->x == ft_atoi(arr[1]))
				if (tmp->y == ft_atoi(arr[2]))
					return (cln(arr, -1));
			tmp = tmp->next;
		}
	return (cln(arr, 0));
}

int				conect(char *str)
{
	char	**arr;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (-1);
		i++;
	}
	arr = ft_strsplit(str, '-');
	if (arr[2] == NULL)
		return (cln(arr, 0));
	else
		return (cln(arr, -1));
}
