/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 13:16:22 by ytailor           #+#    #+#             */
/*   Updated: 2014/03/22 14:49:37 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_fct		tb[6] =
{
	{-1, ft_error},
	{2, ft_get_ants},
	{3, ft_id_room},
	{4, ft_get_room},
	{5, ft_get_tube},
	{0, NULL}
};

int					ft_get_ants(t_data *d, char *line)
{
	if (ft_count_word(line, ' ') == 1 && ft_isdigitloop(line))
	{
		d->nb_ants = ft_atoi(line);
		if (d->nb_ants < 1)
			return (-1);
		else
			d->flag_ants = 1;
	}
	else if (ft_count_word(line, ' ') >= 1 || !ft_isdigitloop(line))
		return (-1);
	return (1);
}

int					ft_get_room(t_data *d, char *line)
{
	char			**tmp;

	if (d->flag_start == 1 && d->flag_end == 1)
		return (-1);
	tmp = ft_strsplit_space(line);
	if (ft_isdigitloop(tmp[1]) && ft_isdigitloop(tmp[2]))
	{
		if ((d->list = ft_add_list(d, tmp[0], ft_check_room(d))) == NULL)
		{
			ft_tabdel(&tmp);
			return (0);
		}
		ft_tabdel(&tmp);
		return (1);
	}
	else
	{
		ft_tabdel(&tmp);
		return (0);
	}
}

int					ft_get_tube(t_data *d, char *line)
{
	char			**tmp;
	t_room			*tmp2;
	int				flag;

	flag = 0;
	tmp2 = d->list;
	tmp = ft_strsplit(line, '-');
	if (ft_tablen(tmp) != 2 || ft_check_tube(d, tmp[0], tmp[1]) == 0)
		flag = 1;
	else
	{
		if (!(tmp2 = ft_search(*d, tmp[0])))
			flag = 1;
		if (flag == 0 && !(tmp2->link = ft_add_link(d, tmp2->link, tmp[1])))
			flag = 1;
		tmp2 = d->list;
		if (flag == 0 && !(tmp2 = ft_search(*d, tmp[1])))
			flag = 1;
		if (flag == 0 && !(tmp2->link = ft_add_link(d, tmp2->link, tmp[0])))
			flag = 1;
	}
	ft_tabdel(&tmp);
	if (flag == 1)
		return (0);
	return (1);
}

void		ft_get_file(t_data *d)
{
	char	*line;
	int		nb;
	int		i;

	nb = 1;
	while (get_next_line(0, &line) > 0 && nb > 0)
	{
		ft_putendl(line);
		i = -1;
		nb = ft_dispatcher(*d, line);
		while (++i < 6)
		{
			if (nb == tb[i].check)
			{
				nb = tb[i].ptr(d, line);
				break ;
			}
		}
		ft_strdel(&line);
	}
	if (nb == -1)
		ft_error(d, line);
	if (ft_check_all(d) == -1)
		ft_error(d, line);
	ft_get_start_end(d);
}
