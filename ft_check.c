/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 15:52:03 by ytailor           #+#    #+#             */
/*   Updated: 2014/03/23 16:16:00 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			ft_check_room(t_data *d)
{
	if (d->flag_start == 1)
	{
		d->flag_start++;
		return (1);
	}
	else if (d->flag_end == 1)
	{
		d->flag_end++;
		return (2);
	}
	return (0);
}

int			ft_isdigitloop(const char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

t_room		*ft_search(t_data d, char *name)
{
	t_room			*tmp;

	tmp = d.list;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int			ft_id_room(t_data *d, char *line)
{
	if (ft_strcmp(line, START) == 0)
	{
		if (d->flag_start >= 1)
			return (-1);
		else
			d->flag_start++;
	}
	else if (ft_strcmp(line, END) == 0)
	{
		if (d->flag_end >= 1)
			return (-1);
		else
			d->flag_end++;
	}
	return (1);
}

int			ft_check_tube(t_data *d, char *s1, char *s2)
{
	t_room	*tmp;
	int		flag;

	flag = 0;
	if (((tmp = d->list) == NULL) || ft_strcmp(s1, s2) == 0)
		return (0);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, s1) || !ft_strcmp(tmp->name, s2))
			flag++;
		tmp = tmp->next;
	}
	if (flag == 2)
		return (1);
	return (0);
}
