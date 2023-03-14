# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpauline <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 16:53:57 by jpauline          #+#    #+#              #
#    Updated: 2023/03/14 16:20:19 by jpauline         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	containers
NAME_FT		=	ft__containers
NAME_STD	=	std_containers

SRCS_FT		=	main_ft.cpp
SRCS_STD	=	main_std.cpp
# SRCS_V		=	main_vector.cpp
# SRCS_ST		=	main_stack.cpp
# SRCS_M		=	main_map.cpp
# SRCS_SE		=	main_set.cpp

CC		=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
OBJS_FT		=	${SRCS_FT:.cpp=.o}
OBJS_STD	=	${SRCS_STD:.cpp=.o}
DEPS_FT		=	${OBJS_FT:.o=.d}
DEPS_STD	=	${OBJS_STD:.o=.d}

all		:	${NAME}

-include $(DEPS)

# $(NAME)		:	$(OBJS_FT) $(OBJS_STD)
# 			${CC} ${CFLAGS} ${OBJS_FT} -o ${NAME_FT}
# 			${CC} ${CFLAGS} ${OBJS_STD} -o ${NAME_STD}

$(NAME)		:	$(NAME_FT) $(NAME_STD)

$(NAME_FT)		:	$(OBJS_FT)
			${CC} ${CFLAGS} ${OBJS_FT} -o ${NAME_FT}

$(NAME_STD)		:	$(OBJS_STD)
			${CC} ${CFLAGS} ${OBJS_STD} -o ${NAME_STD}

# vector		:	
# 			${CC} ${CFLAGS} ${SRCS_V} -o ft_vector -D NS=ft
# 			${CC} ${CFLAGS} ${SRCS_V} -o std_vector -D NS=std
# 			./ft_vector > ft_vector.txt && ./std_vector > std_vector.txt
# 			diff ft_vector.txt std_vector.txt

# stack		:
# 			${CC} ${CFLAGS} ${SRCS_ST} -o ft_stack -D NS=ft
# 			${CC} ${CFLAGS} ${SRCS_ST} -o std_stack -D NS=std
# 			./ft_stack > ft_stack.txt && ./std_stack > std_stack.txt
# 			diff ft_stack.txt std_stack.txt

# map		:
# 			${CC} ${CFLAGS} ${SRCS_M} -o ft_map -D NS=ft
# 			${CC} ${CFLAGS} ${SRCS_M} -o std_map -D NS=std
# 			./ft_map > ft_map.txt && ./std_map > std_map.txt
# 			diff ft_map.txt std_map.txt

# set		:
# 			${CC} ${CFLAGS} ${SRCS_SE} -o ft_set -D NS=ft
# 			${CC} ${CFLAGS} ${SRCS_SE} -o std_set -D NS=std
# 			./ft_set > ft_set.txt && ./std_set > std_set.txt
# 			diff ft_set.txt std_set.txt

%.o:%.cpp		
			$(CC) -MMD $(CFLAGS) -c $< -o $@

clean		:
			rm -f ${OBJS_FT} ${DEPS_FT} ${OBJS_STD} ${DEPS_STD}

# cleantest	:
# 			rm -f std_vector std_stack std_map std_set ft_vector ft_stack ft_map ft_set *.txt

fclean		: clean cleantest
			rm -f ${NAME_FT} ${NAME_STD}

re		:	fclean all

.PHONY		:	all vector stack map set clean cleantest fclean re
