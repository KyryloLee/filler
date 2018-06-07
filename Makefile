# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 10:55:03 by klee              #+#    #+#              #
#    Updated: 2018/02/07 10:55:04 by klee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = klee.filler

SRCS = filler.c\
		libft.a\
		dop_file1.c\
		dop_file.c

SRCS_PREFIX = srcs

SRCS_DIR = $(addprefix $(SRCS_PREFIX)/, $(SRCS))

INCLUDE = ./includes/

INCLUDE_LIB = ./libft/includes

all: $(NAME)

$(NAME):
	@make -C ./libft
	@cp libft/libft.a ./srcs
	@gcc -Wall -Wextra -Werror -I $(INCLUDE) $(SRCS_DIR) -o $(NAME)

clean:
	@make clean -C libft
fclean:
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
