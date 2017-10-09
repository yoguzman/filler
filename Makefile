#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yguzman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 11:38:09 by yguzman           #+#    #+#              #
#    Updated: 2017/10/09 15:34:08 by yguzman          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC			=		clang

NAME		=		./resources/players/yguzman.filler

DIR_SRC		=		./src/

SRCS		=		$(DIR_SRC)main.c					\
					$(DIR_SRC)free.c					\
					$(DIR_SRC)go_algo.c					\
					$(DIR_SRC)fill_map_and_piece.c		\
					$(DIR_SRC)fill_player.c				\
					$(DIR_SRC)tools.c					\

OBJS		=		$(SRCS:.c=.o)

CFLAGS		+=		-Iinclude
CFLAGS		+=		-Wall -Wextra

RM			=		rm -f

LIB			=		./libft/libft.a

ECHO		=		printf

all			:		$(NAME)

$(NAME)		:		$(OBJS)
					@make -C libft
					@$(ECHO) "\033[35m[~~~~COMPILATION PROJECT~~~~]\n\033[0m"
					@$(CC) -o $(NAME) -Llibft -lft -lncurses $(OBJS) && $(ECHO) "\033[33;32m["$@"]\n\033[0m" || $(ECHO) "\033[31m["$@"]\n\033[0m"

%.o			:		%.c
					@$(ECHO) "\033[35m[~~~Comipilation obj //project~~~]-->\033[0m"
					@$(CC) $(CFLAGS) -o $@ -c $< && $(ECHO) "\033[33;32m ["$@"]\n\033[0m" || $(ECHO) "\033[31m ["$@"]\n\033[0m"

clean_lib	:
					@make -C libft clean

clean		:		clean_lib
					@$(ECHO) "\033[31m[~~~~~~Supression des .o //project~~~~~~]\n\033[0m"
					@$(RM) $(OBJS)

fclean_lib	:
					@make -C libft fclean

fclean		:		fclean_lib
					@$(ECHO) "\033[31m[~~~~~~Supression des .o //project~~~~~~]\n\033[0m"
					@$(RM) $(OBJS)
					@$(ECHO) "\033[31m[~~~~Supression du Binaire~~~~]\n\033[0m"
					@$(RM) $(NAME)

re			:		fclean all

depend		:		$(SRCS)
					makedepend -- -Yinclude/ -- $^

.PHONY		:		all depend clean flean re

# DO NOT DELETE THIS LINE -- make depend depends on it.
