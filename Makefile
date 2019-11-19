# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vparekh <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 13:58:55 by vparekh           #+#    #+#              #
#*   Updated: 2019/11/18 13:58:58 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

.PHONY: all, ,clean, re, fclean

NAME = libftprintf.a

SRC = ft_putchar.c\
		ft_atoi.c\
		ft_isdigit.c\
		ft_nbrlen.c\
		ft_strlen.c\
		ft_putstr.c\
		ft_strchr.c\
		ft_itoa.c\
		ft_strdup.c\
		ft_uint_itoa.c\
		ft_print_main.c\
		ft_print_nbr.c\
		ft_decimal_to_hex.c\
		ft_print_char.c\
		ft_printf_utils.c\
		ft_print_str.c\

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib	$(NAME)

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all