# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpauline <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 16:53:57 by jpauline          #+#    #+#              #
#    Updated: 2023/02/03 16:56:07 by jpauline         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	ft_containers

SRCS	=	main.cpp

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror
OBJS	=	${SRCS:.cpp=.o}

all		:	${NAME}

$(NAME)	:	$(OBJS)
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean	:
		rm -f ${OBJS}

fclean	:
		rm -f ${OBJS}
		rm -f ${NAME}

re		:	fclean all

.PHONY	:	all clean fclean re
