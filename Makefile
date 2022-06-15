# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 09:48:37 by thhusser          #+#    #+#              #
#    Updated: 2022/06/15 15:00:34 by thhusser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_NC=`tput sgr0`
_RED=\033[0;31m
_GREEN=\033[0;32m
_YELLOW=\033[0;33m
_BLUE=\033[0;34m
_PURPLE=\033[0;95m
_CYAN=\033[0;36m
_WHITE=\033[0;37m

NAME	=	debug

HEADER 	=	-I ./srcs/

SRCS	=	main.cpp \

OBJS	=	$(SRCS:.cpp=.o)

RM		= rm -f

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror -std=c++98

.cpp.o:
			@printf "$(_WHITE)Generating $(NAME) objects... %-33.33s\r$(_NC)" $@
			@$(CC) $(FLAGS) $(HEADER) -c $< -o $(<:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo ""
			@$(CC) $(FLAGS) $(HEADER) $(OBJS) -o $(NAME)
			@echo "$(_GREEN)Generating $(NAME)$(_NC)"

clean:
			@$(RM) $(OBJS)
			@echo "$(_GREEN)Deletes objects files $(NAME)$(_NC)"

fclean: 	clean
			@$(RM) $(NAME)
			@echo "$(_GREEN)Delete $(NAME)$(_NC)"

re:			fclean all
