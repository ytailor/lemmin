/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 19:34:21 by ytailor           #+#    #+#             */
/*   Updated: 2014/03/17 19:01:07 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int		word;
	int		i;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			word++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (word);
}

static int	ft_len_word(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		j;
	int		len;
	int		word;

	j = -1;
	if (s == NULL)
		return (NULL);
	word = ft_count(s, c);
	if ((tab = (char **)malloc(sizeof(char *) * (word + 1))) == NULL)
		return (NULL);
	while (++j < word)
	{
		while (*s != '\0' && *s == c)
			s++;
		len = ft_len_word(s, c);
		if ((tab[j] = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		ft_strncpy(tab[j], s, len);
		while (*s != '\0' && *s != c)
			s++;
	}
	tab[j] = NULL;
	return (tab);
}
