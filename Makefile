# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 09:48:37 by thhusser          #+#    #+#              #
#    Updated: 2022/10/13 13:53:33 by thhusser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_RED=\033[0;31m
_GREEN=\033[0;32m
_YELLOW=\033[0;33m
_BLUE=\033[0;34m
_PURPLE=\033[0;95m
_CYAN=\033[0;36m
_WHITE=\033[0;37m

OS		=		$(shell echo -n ${GDMSESSION})

FT_NAME		=		ft_containers

STD_NAME	=	std_containers

STD	=	std

FT	=	ft

RM	=	rm -rf

CC	=	c++

FLAGS	=	-Wall -Wextra -Werror -std=c++98

DIR_INC		= -I ./srcs/

SRCS		:= 	vector.cpp \
				main.cpp \
				stack.cpp \
				map.cpp \

DIR_SRCS	:= ./test

DIR_OBJ_FT		:= obj_ft
OBJS_FT		:= \
				$(addprefix ${DIR_OBJ_FT}/, ${SRCS:.cpp=.o})


DIR_OBJ_STD	:= obj_std
OBJS_STD	:= \
			$(addprefix ${DIR_OBJ_STD}/, ${SRCS:.cpp=.o})

DEPS_FT = $(OBJS_FT:.o=.d)

DEPS_STD = $(OBJS_STD:.o=.d)

all: $(FT_NAME) ${STD_NAME}

-include $(DEPS_FT)
-include $(DEPS_STD)

$(DIR_OBJ_FT)/%.o  :	$(DIR_SRCS)/%.cpp
		@mkdir -p $(dir $@)
		@${CC} ${FLAGS} ${DIR_INC} -DNM=$(FT) -o $@ -c $< -MMD

$(DIR_OBJ_STD)/%.o:	$(DIR_SRCS)/%.cpp
		@mkdir -p $(dir $@)
		@${CC} ${FLAGS} ${DIR_INC} -DNM=$(STD) -DUSE=0 -o $@ -c $< -MMD

$(FT_NAME):			$(OBJS_FT)
				 @$(CC) $(FLAGS) ${DIR_INC} $(OBJS_FT) -o $(FT_NAME)
				@echo "$(_GREEN)Generating $(FT_NAME)$(_NC)"

$(STD_NAME): $(OBJS_STD)
				@$(CC) $(FLAGS) ${DIR_INC} $(OBJS_STD) -o $(STD_NAME)
				@echo "$(_GREEN)Generating $(STD_NAME)$(_NC)"
clean:
		@$(RM) $(DIR_OBJ_STD) $(DIR_OBJ_FT)
		@echo "$(_GREEN)Deletes objects files $(FT_NAME) and $(STD_NAME)$(_NC)"

fclean:		clean
			@$(RM) $(FT_NAME) $(STD_NAME)
			@echo "$(_GREEN)Delete $(FT_NAME) and $(STD_NAME)$(_NC)"

re:			fclean all
