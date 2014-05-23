/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 15:41:59 by ytailor           #+#    #+#             */
/*   Updated: 2014/03/17 15:43:39 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_tabdel(char ***tab)
{
	int		i;

	i = ft_tablen(*tab);
	if (*tab)
	{
		while (i >= 0)
		{
			free((*tab)[i]);
			(*tab)[i] = NULL;
			i--;
		}
		free(*tab);
		*tab = NULL;
	}
}
