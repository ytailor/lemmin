/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 12:58:13 by ytailor           #+#    #+#             */
/*   Updated: 2014/03/22 14:54:37 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_way		*ft_create_way(t_room *room, int nb)
{
	t_way	*new;

	if ((new = (t_way *)malloc(sizeof(t_way))) == NULL)
			return (NULL);
	new->room = room;
	if (room->flag == 1)
		new->ant = nb;
	else
		new->ant = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		ft_push_back_way(t_way **list, t_room *room, int nb)
{
	t_way	*new;

	if ((new = ft_create_way(room, nb)) == NULL)
		ft_putstr_fd("Erreur malloc create way", 2);
	new->next = *list;
	if (*list)
		(*list)->prev = new;
	*list = new;
}

int			ft_get_calcul(t_way *tmp, int *nb_s, t_data d)
{
	if (tmp->room->flag == 1 && *nb_s > 0)
		return (d.nb_ants - (*nb_s)--) + 1;
	else if (tmp->room->flag != 1)
		return (tmp->ant);
	else
		return (0);
}

void		ft_print_way(t_data d, t_way *way)
{
	t_way	*tmp;
	int		count;
	int		nb_s;

	nb_s = d.nb_ants;
	tmp = way;
	count = 0;
	while (count < d.nb_ants)
	{
		if (tmp->ant && tmp->room->flag != 2)
		{
			if ((tmp->prev->ant = ft_get_calcul(tmp, &nb_s, d)))
				ft_printf("L%d-%s ", tmp->prev->ant, tmp->prev->room->name);
			if (tmp->prev->room->flag == 2)
				count++;
		}
		if (tmp->room->flag == 1)
		{
			tmp = way;
			ft_putendl("");
		}
		else
			tmp = tmp->next;
	}
}
