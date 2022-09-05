# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 09:48:37 by thhusser          #+#    #+#              #
#    Updated: 2022/09/05 18:45:23 by thhusser         ###   ########.fr        #
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

# GDMSESSION
OS 		=  $(shell echo -n ${twat})

NAME	=	debug

HEADER 	=	-I ./srcs/

HEADER_T	= -I ./tests/map/

SRCS_LINUX	= 	$(addprefix ./tests/, ${SRCS_FILES}) $(addprefix ./tests/, ${SRCS_MAIN_L})

SRCS_MAC	= 	$(addprefix ./tests/, ${SRCS_FILES}) $(addprefix ./tests/, ${SRCS_MAIN_M})

SRCS_FILES	=

SRCS_MAIN_L =	map/main_linux.cpp \

SRCS_MAIN_M =	map/main_mac.cpp \

# OBJS		=	$(SRCS_LINUX:.cpp=.o)

RM		= rm -f

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror -std=c++98


OBJS	=	$(OBJS_OS)

ifeq ($(OS), ubuntu)
	OBJS_OS		=	$(SRCS_LINUX:.cpp=.o)
else
	OBJS_OS		=	$(SRCS_MAC:.cpp=.o)
endif


all:  $(NAME)
	@echo -n ${OS}
	echo -n ${GDMSESSION}
	echo $(OBJS)


#FIND_OS:
#	if [ "${OS}" == "ubnutu" ]; then  OBJS_OS = $(SRCS_LINUX:.cpp=.o); fi; 
#	if [ "$(OS)" != "ubuntu" ]; then OBJS_OS = $(SRCS_MAC:.cpp=.o) ; fi;


# FIND_OS:	
# 	@echo $(OS)

.cpp.o:
			@printf "$(_WHITE)Generating $(NAME) objects... %-33.33s\r$(_NC)" $@
			@$(CC) $(FLAGS) $(HEADER) $(HEADER_T) -c $< -o $(<:.cpp=.o)

$(NAME):	 $(OBJS)
			@echo ""
			@$(CC) $(FLAGS) $(HEADER) $(HEADER_T) $(OBJS) -o $(NAME)
			@echo "$(_GREEN)Generating $(NAME)$(_NC)"

clean:
			@$(RM) $(OBJS)
			@echo "$(_GREEN)Deletes objects files $(NAME)$(_NC)"

fclean: 	clean
			@$(RM) $(NAME)
			@echo "$(_GREEN)Delete $(NAME)$(_NC)"

re:			fclean all
