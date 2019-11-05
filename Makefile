# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhuang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/25 18:25:30 by lhuang            #+#    #+#              #
#    Updated: 2019/10/26 20:19:27 by lhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)
HEADER = libftprintf.h
PATH = libft/
LIBFT_NAME = libft.a

$(LIBFT_NAME):
	make all -C libft/

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

${NAME}: $(OBJS) $(HEADER) $(LIBFT_NAME)
	ar rc $(NAME) $(OBJS) $(HEADER) $(PATH)$(LIBFT_NAME)

all: $(NAME)

clean: 
	make clean -C libft/
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft/
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
