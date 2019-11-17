# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/25 18:25:30 by lhuang            #+#    #+#              #
#    Updated: 2019/11/17 14:51:30 by lhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_create_cuts.c ft_cuts_lists.c ft_get_precision.c ft_get_width.c ft_is_check.c ft_printf.c ft_put_characters.c ft_put_characters2.c ft_put_cuts_nbr_utils.c ft_put_cuts_nbr.c ft_put_cuts.c ft_put_flags.c ft_put_numbers.c ft_put_utils.c ft_put_utils2.c
OBJS = $(SRCS:.c=.o)
HEADER = ft_printf.h

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

${NAME}: $(OBJS) $(HEADER)
	ar rc $(NAME) $(OBJS) $(HEADER)

all: $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
