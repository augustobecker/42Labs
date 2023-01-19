# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesar-l <acesar-l@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 16:53:41 by acesar-l          #+#    #+#              #
#    Updated: 2023/01/19 19:34:53 by acesar-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ENCODER			= $(ENCODER_PATH)/encoder
DECODER			= $(DECODER_PATH)/decoder

ENCODER_PATH	= ./encoder
DECODER_PATH	= ./decoder

GREY			= \033[0;30m
GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

all:			$(ENCODER) $(DECODER)

$(ENCODER):
				@make --no-print-directory -C $(ENCODER_PATH)

$(DECODER):
				@make --no-print-directory -C $(DECODER_PATH)

clean:			
				@make --no-print-directory clean -C $(ENCODER_PATH)
				@make --no-print-directory clean -C $(DECODER_PATH)

fclean:			
				@make --no-print-directory fclean -C $(ENCODER_PATH)
				@make --no-print-directory fclean -C $(DECODER_PATH)

re:
				@make --no-print-directory fclean
				@make --no-print-directory all

.PHONY:			all clean fclean re