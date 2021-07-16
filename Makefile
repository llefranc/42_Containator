# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llefranc <llefranc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 11:24:58 by llefranc          #+#    #+#              #
#    Updated: 2021/07/16 16:29:55 by llefranc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	containers_test
CC			=	clang++
FLAGS		=	-g -fsanitize=address -Wall -Wextra -Werror -std=c++98

SRCS		=	select_your_tests/select_containers.cpp includes_and_utils/utils.cpp

HEADER_INC	=	print_type.hpp tester.hpp my_ft_pair.hpp utils.hpp
PATH_INC	=	includes_and_utils/

HEADER_TEST	=	create_containers.hpp vector_tests.hpp list_tests.hpp stack_tests.hpp \
				queue_tests.hpp map_tests.hpp
PATH_TEST	=	each_tests/

HEADER_SELE	=	select_list_tests.hpp select_vector_tests.hpp select_stack_tests.hpp \
				select_queue_tests.hpp select_map_tests.hpp
PATH_SELE	=	select_your_tests/

OBJS		=	$(SRCS:.cpp=.o)

all		: 	$(NAME)

$(NAME)	:	$(OBJS)
			@$(CC) -o $(NAME) $(FLAGS) $(OBJS)

$(OBJS)	:	$(addprefix $(PATH_CON), $(HEADER_CON)) $(addprefix $(PATH_TEM), $(HEADER_TEM)) \
			$(addprefix $(PATH_ITE), $(HEADER_ITE)) $(addprefix $(PATH_TEST), $(HEADER_TEST)) \
			$(addprefix $(PATH_INC), $(HEADER_INC))

clean	:	
				@rm -rf $(OBJS)

fclean	:	clean
				@rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re

%.o		:	%.cpp
			@$(CC) $(FLAGS) -o $@ -c $<
# for creating .o with flags