/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 21:27:08 by oskulska          #+#    #+#             */
/*   Updated: 2018/06/14 21:27:10 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_output		*create_lemin_new_node(void)
{
	t_output	*new_node;

	new_node = (t_output*)malloc(sizeof(t_output));
	if (new_node == NULL)
	{
		ft_printf("\nMemory was not allocated");
		return (0);
	}
	else
		new_node->next = NULL;
	return (new_node);
}

t_lemin			*create_node(void)
{
	t_lemin *new_node;

	new_node = (t_lemin*)malloc(sizeof(t_lemin));
	if (new_node == NULL)
	{
		ft_printf("\nMemory was not allocated");
		return (0);
	}
	else
		new_node->next = NULL;
	return (new_node);
}

t_way			*create_node_way(int i)
{
	t_way	*new_node;

	new_node = (t_way*)malloc(sizeof(t_way));
	new_node->way = malloc(sizeof(int *) * i + 1);
	new_node->len = i + 1;
	if (new_node == NULL)
	{
		ft_printf("\nMemory was not allocated\n");
		return (0);
	}
	else
		new_node->next = NULL;
	return (new_node);
}

void			*init_struct(void)
{
	t_all	*params;

	params = malloc(sizeof(t_all));
	params->ants = 0;
	params->len = 0;
	params->lemin = NULL;
	params->output = NULL;
	params->start = 0;
	params->end = 0;
	params->room_readed = 0;
	params->flag = malloc(sizeof(t_flag));
	params->flag->error = 0;
	params->flag->way = 0;
	params->flag->filter = 0;
	params->flag->leaks = 0;
	params->flag->total = 0;
	return (params);
}

t_lemin			*ft_find_room(char *line, int start, int end, t_lemin *tmp)
{
	t_lemin		*new_node;
	t_lemin		*header;
	static int	i;

	i = 1;
	if (tmp == NULL)
	{
		tmp = create_node();
		ft_fill_list(tmp, line, start, end);
	}
	else
	{
		new_node = create_node();
		header = tmp;
		while ((header)->next)
			header = header->next;
		header->next = new_node;
		i++;
		ft_fill_list(new_node, line, start, end);
	}
	return (tmp);
}
