/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 15:23:38 by ytailor           #+#    #+#             */
/*   Updated: 2014/03/22 14:54:58 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/includes/libft.h"
# define START			"##start"
# define END			"##end"

typedef struct s_room	t_room;
typedef struct s_link	t_link;
typedef	struct s_way	t_way;

typedef struct			s_data
{
	int					nb_ants;
	int					flag_start;
	int					flag_end;
	int					flag_ants;
	t_room				*start;
	t_room				*end;
	t_room				*list;
}						t_data;

struct					s_link
{
	char				*name;
	t_room				*room;
	struct s_link		*next;
};

struct					s_room
{
	int					flag;
	int					nb_ants;
	int					weight;
	char				*name;
	char				*ants_name;
	t_link				*link;
	struct s_room		*next;
};

struct					s_way
{
	t_room				*room;
	int					ant;
	t_way				*next;
	t_way				*prev;
};

typedef struct			s_fct
{
	int					check;
	int					(*ptr)(t_data *, char *);
}						t_fct;

void	ft_print_map(t_data *d);
int		ft_error(t_data *d, char *line);

/*
**		ft_init.c
*/

void	ft_init(t_data *d);

/*
**		ft_parse.c
*/

int		ft_check_all(t_data *d);
int		ft_is_possible(t_data d);
int		ft_dispatcher(t_data d, char *line);
void	ft_get_start_end(t_data *d);

/*
**		ft_get_file.c
*/

void	ft_get_file(t_data *d);
int		ft_get_ants(t_data *d, char *line);
int		ft_get_room(t_data *d, char *line);
int		ft_get_tube(t_data *d, char *line);

/*
**		ft_list.c
*/

t_link	*ft_create_link(t_data d, char *name);
t_room	*ft_add_list(t_data *d, char *name, int flag);
t_link	*ft_add_link(t_data *d, t_link *link, char *s2);
t_room	*ft_create_list(t_data d, char *name, int flag);

/*
**		ft_check.c
*/

int		ft_check_room(t_data *d);
int		ft_isdigitloop(const char *str);
t_room	*ft_search(t_data d, char *name);
int		ft_id_room(t_data *d, char *line);
int		ft_check_tube(t_data *d, char *s1, char *s2);

/*
**		ft_path.c
*/

int		ft_find_way(t_data *d);


/*
**		ft_prints_way.c
*/

t_way	*ft_create_way(t_room *room, int nb);
void	ft_push_back_way(t_way **list, t_room *room, int nb);
void	ft_print_way(t_data d, t_way *way);

#endif
