#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/05 14:43:21 by ytailor           #+#    #+#              #
#    Updated: 2014/03/19 19:10:03 by ytailor          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

FLAGS = -Wall -Wextra -Werror

SRCS = main.c ft_get_file.c ft_init.c ft_list.c ft_check.c ft_parse.c \
		ft_path.c ft_print_ants.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	gcc $(FLAGS) $(SRCS) -o $(NAME) libft/libft.a

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
