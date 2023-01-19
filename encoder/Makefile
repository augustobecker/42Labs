# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 19:23:21 by acesar-l          #+#    #+#              #
#    Updated: 2023/01/19 19:35:27 by acesar-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	encoder

COMPILER 	=	gcc -g
CFLAGS 		= 	-Wall -Wextra -Werror
CLEANUP 	= 	rm -rf

SRCS_PATH	=	./sources

PTHREAD		=	-pthread

INCLUDE		= 	-I ./includes

SRCS 		=	${SRCS_PATH}/main.c 						\
				${SRCS_PATH}/initial_validations.c			\
				${SRCS_PATH}/create.c						\
				${SRCS_PATH}/string_utils.c					\
				${SRCS_PATH}/utils.c						\
				${SRCS_PATH}/read_files.c					\
				${SRCS_PATH}/dictionary_utils.c				\
				${SRCS_PATH}/linked_list/memory.c			\
				${SRCS_PATH}/linked_list/populate.c			\
				${SRCS_PATH}/linked_list/functionalities.c	\
				${SRCS_PATH}/linked_list/sort.c				\
				${SRCS_PATH}/tree/memory.c					\
				${SRCS_PATH}/tree/convert_from.c			\
				${SRCS_PATH}/tree/functionalities.c			\
				${SRCS_PATH}/tree/sort.c					\
				${SRCS_PATH}/bit_array/memory.c				\
				${SRCS_PATH}/bit_array/populate.c			\
				${SRCS_PATH}/bit_array/functionalities.c	\
				${SRCS_PATH}/compress_text.c				\
				${SRCS_PATH}/shared.c						\
				${SRCS_PATH}/global_data_managment.c		\
				${SRCS_PATH}/semaphore.c					\
				${SRCS_PATH}/huffman_coding.c				\
				${SRCS_PATH}/local_shared_mem.c				\
				${SRCS_PATH}/error.c						

OBJS		=	$(SRCS:.c=.o)

GREY		= 	\033[0;30m
GREEN		=	\033[0;32m
RED			=	\033[0;31m
RESET		=	\033[0m

all:			$(NAME)

$(NAME):		$(OBJS)
				@$(COMPILER) $(CFLAGS) $(OBJS) $(PTHREAD) -o $(NAME)
				@echo "$(NAME): $(GREEN)$(NAME) was generated$(RESET)"

clean:
				@$(CLEANUP) $(OBJS)
				@echo "$(NAME): $(GREY)objects were deleted$(RESET)"

fclean: 		
				@$(CLEANUP) $(OBJS) $(NAME)
				@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

.c.o:
				@${COMPILER} -c ${CFLAGS} $< -o ${<:.c=.o} ${INCLUDE}

re:				fclean $(NAME)

.PHONY:			all clean fclean re