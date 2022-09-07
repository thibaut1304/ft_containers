# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 09:48:37 by thhusser          #+#    #+#              #
#    Updated: 2022/09/07 23:28:16 by thhusser         ###   ########.fr        #
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

OS 		=  $(shell echo -n ${GDMSESSION})

FT_NAME		=	ft_containers

STD_NAME	=	std_containers

HEADER	=	-I ./srcs/

STD 	= std

SRCS		= 	$(addprefix ./test_2/, ${SRCS_FILES})

SRCS_FILES	=	vector/main.cpp

RM		= rm -f

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror -std=c++98

OBJS_DIR = obj

OBJS	=	$(SRCS:.cpp=.o)

all: $(FT_NAME) $(STD_NAME)

.cpp.o:
			@printf "$(_WHITE)Generating $(FT_NAME) objects... %-33.33s\r$(_NC)" $@
			@$(CC) $(FLAGS) $(HEADER) -c $< -o $(<:.cpp=.o)

$(FT_NAME):	 $(OBJS)
			@echo ""
			@$(CC) $(FLAGS) $(HEADER) $(OBJS) -o $(FT_NAME)
			@echo "$(_GREEN)Generating $(FT_NAME)$(_NC)"

$(STD_NAME): FLAGS += -DNM=$(STD)

$(STD_NAME): $(OBJS)
			@echo ""
			@$(CC) $(FLAGS) $(HEADER) $(OBJS) -o $(STD_NAME)
			@echo "$(_GREEN)Generating $(STD_NAME) $(_NC)"

clean:
			@$(RM) $(OBJS)
			@echo "$(_GREEN)Deletes objects files $(FT_NAME) and $(STD_NAME)$(_NC)"

fclean: 	clean
			@$(RM) $(FT_NAME)
			@echo "$(_GREEN)Delete $(FT_NAME) and $(STD_NAME)$(_NC)"

re:			fclean all
