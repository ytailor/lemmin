/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 16:52:04 by ytailor           #+#    #+#             */
/*   Updated: 2014/03/19 19:08:52 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_init(t_data *d)
{
	d->start = NULL;
	d->end = NULL;
	d->nb_ants = 0;
	d->flag_start = 0;
	d->flag_end = 0;
	d->flag_ants = 0;
	d->list = NULL;
}
