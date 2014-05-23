/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 19:15:03 by ytailor           #+#    #+#             */
/*   Updated: 2014/03/19 19:08:50 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room		*ft_create_list(t_data d, char *name, int flag)
{
	t_room	*new;

	if ((new = (t_room *)malloc(sizeof(t_room))) == NULL)
		return (NULL);
	new->name = ft_strdup(name);
	new->flag = flag;
	if (flag == 1)
		new->nb_ants = d.nb_ants;
	else
		new->nb_ants = 0;
	new->next = NULL;
	new->link = NULL;
	new->weight = -1;
	new->ants_name = NULL;
	return (new);
}

t_room		*ft_add_list(t_data *d, char *name, int flag)
{
	t_room	*tmp;
	t_room	*new;

	new = ft_create_list(*d, name, flag);
	tmp = d->list;
	if (d->list == NULL)
		return (new);
	while (tmp->next)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (NULL);
		tmp = tmp->next;
	}
	tmp->next = new;
	return (d->list);
}

t_link		*ft_create_link(t_data d, char *name)
{
	t_link	*new;

	if ((new = (t_link *)malloc(sizeof(t_link))) == NULL)
		return (NULL);
	new->name = ft_strdup(name);
	new->next = NULL;
	if ((new->room = ft_search(d, name)) == NULL)
		return (NULL);
	return (new);
}

t_link		*ft_add_link(t_data *d, t_link *link, char *s2)
{
	t_link	*tmp;
	t_link	*new;

	tmp = link;
	if ((new = ft_create_link(*d, s2)) == NULL)
		return (NULL);
	if (!link)
		return (new);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		return (link);
	}
	return (NULL);
}
