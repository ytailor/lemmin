/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 15:21:42 by ytailor           #+#    #+#             */
/*   Updated: 2014/03/23 16:17:37 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			ft_error(t_data *d, char *line)
{
	(void)d;
	ft_strdel(&line);
	ft_putstr("ERROR\n");
	exit(EXIT_FAILURE);
	return (1);
}

int			main()
{
	t_data	d;

	ft_init(&d);
	ft_get_file(&d);
	ft_find_way(&d);
	return (0);
}
