/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 18:37:29 by ytailor           #+#    #+#             */
/*   Updated: 2014/03/23 16:16:50 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			ft_dispatcher(t_data d, char *line)
{
	char	*str;

	str = NULL;
	if ((line[0] == '#' && line[1] != '#') || (line[0] == '#' &&
		(ft_strcmp(line, START) != 0 && ft_strcmp(line, END) != 0)))
		return (1);
	if (line[0] == '\n' || line[0] == 'L' || ft_count_word(line, ' ') == 2 ||
			ft_count_word(line, ' ') > 3)
		return (0);
	if (d.flag_ants == 0)
		return (2);
	if (ft_strcmp(line, START) == 0 || ft_strcmp(line, END) == 0)
		return (3);
	if (d.flag_ants && ft_count_word(line, ' ') == 3)
		return (4);
	if (d.flag_ants && ft_count_word(line, ' ') == 1)
	{
		str = ft_strchr(line, '-');
		if (str && str[0] == '-')
			return (5);
	}
	return (-1);
}

void		ft_get_start_end(t_data *d)
{
	t_room	*tmp;

	tmp = d->list;
	while (tmp)
	{
		if (tmp->flag == 1)
			d->start = tmp;
		if (tmp->flag == 2)
			d->end = tmp;
		tmp = tmp->next;
	}
}

int			ft_istube(t_room *list)
{
	t_room	*tmp;
	int		flag;

	tmp = list;
	flag = 0;
	if (!tmp)
		return (-1);
	while (tmp->next)
	{
		if (tmp->link)
			flag++;
		tmp = tmp->next;
	}
	if (flag > 0)
		return (0);
	return (-1);
}

int			ft_check_all(t_data *d)
{
	if ((d->flag_start != 2 && d->flag_end != 2) || d->nb_ants < 1)
		return (-1);
	if (ft_istube(d->list) == -1)
		return (-1);
	return (0);
}
