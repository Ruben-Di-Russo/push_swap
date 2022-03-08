# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 12:07:07 by agenoves          #+#    #+#              #
#    Updated: 2022/03/02 20:12:52 by rdi-russ         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc 
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

FILES = ft_array \
		ft_checkarg \
		ft_lstadd_front \
		ft_push_swap \
		ft_sort \
		ft_utils \
		ft_pushelem \
		ft_putstr \
		ft_revrotate_elem \
		ft_rotate_elem \
		ft_swapelem \
		ft_atoi \
		ft_split 
		
		
		
SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS = ${SRCS:.c=.o}

${NAME}:
	${CC} ${CFLAGS} ${SRCS} -o $@

all: ${NAME} 
${NAME}: ${OBJS}

clean: 
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re