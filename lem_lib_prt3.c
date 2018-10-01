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

void	check_way(t_way *way, t_all *all)
{
	t_way	*tmp;

	tmp = way;
	if (tmp == NULL)
	{
		if (all->flag->error == 1)
			ft_printf("NO POSSIBLE WAY FOUNDED\n");
		else
			ft_printf("ERROR\n");
		exit(1);
	}
}
