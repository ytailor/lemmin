/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 13:49:06 by ytailor           #+#    #+#             */
/*   Updated: 2014/03/22 14:50:45 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			ft_put_weight(t_room *end, int nb)
{
	t_room			*tmp;
	t_link			*tmp2;

	tmp = end;
	tmp2 = tmp->link;
	if (tmp->weight == -1 || tmp->weight > nb)
		tmp->weight = nb;
	else
		return ;
	nb++;
	while (tmp2)
	{
		ft_put_weight(tmp2->room, nb);
		tmp2 = tmp2->next;
	}
}

static void			ft_print_weight(t_room *room, int *a, t_way **way, int nb)
{
	t_room		*tmp;
	t_link		*tmp2;

	tmp = room;
	tmp2 = tmp->link;

	if (tmp->flag == 2)
	{
		ft_push_back_way(way, tmp, nb);
		*a = 1;
		return ;
	}
	while (tmp2)
	{
		if (*a == 1)
			return ;
		if (tmp->weight > tmp2->room->weight)
		{
			ft_push_back_way(way, tmp, nb);
			ft_print_weight(tmp2->room, a, way, nb);
		}
		else
			tmp2 = tmp2->next;
	}
}

int					ft_find_way(t_data *d)
{
	int		toto;
	t_way	*way;

	way = NULL;
	toto = 0;
	ft_put_weight(d->end, 0);
	if (d->start->weight == -1)
		ft_error(d, "");
	ft_print_weight(d->start, &toto, &way, d->nb_ants);
	ft_print_way(*d, way);
	ft_putchar('\n');
	return (0);
}
