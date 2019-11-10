# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/25 18:25:30 by lhuang            #+#    #+#              #
#    Updated: 2019/11/10 13:04:00 by lhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c ft_create_cuts.c ft_cuts_lists.c ft_put_cuts.c ft_put_utils.c ft_put_flags.c
OBJS = $(SRCS:.c=.o)
HEADER = libftprintf.h
PATH = libft/
LIBFT_NAME = libft.a

$(LIBFT_NAME):
	make all -C libft/

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

${NAME}: $(OBJS) $(HEADER)
	ar rc $(NAME) $(OBJS) $(HEADER)

all: $(NAME)

clean: 
	make clean -C libft/
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft/
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
