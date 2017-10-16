#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yguzman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/18 11:38:09 by yguzman           #+#    #+#              #
#    Updated: 2017/10/16 16:57:33 by yguzman          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC			=		clang

NAME		=		./resources/players/yguzman.filler

DIR_SRC		=		./src/

SRCS		=		$(DIR_SRC)main.c					\
					$(DIR_SRC)free.c					\
					$(DIR_SRC)go_algo.c					\
					$(DIR_SRC)try_all_pos.c				\
					$(DIR_SRC)find_better_pos.c			\
					$(DIR_SRC)fill_map_and_piece.c		\
					$(DIR_SRC)fill_player.c				\
					$(DIR_SRC)brut_force.c				\
					$(DIR_SRC)pos_func.c				\
					$(DIR_SRC)stick_piece.c				\
					$(DIR_SRC)check_line.c				\
					$(DIR_SRC)direction.c				\
					$(DIR_SRC)rush.c					\
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
					@makedepend -- -Yinclude/ -- $^ 2> /dev/null

.PHONY		:		all depend clean flean re

# DO NOT DELETE THIS LINE -- make depend depends on it.

src/main.o: include/libft.h include/filler.h
src/go_algo.o: include/filler.h include/libft.h
src/fill_map_and_piece.o: include/libft.h include/filler.h
src/fill_player.o: include/libft.h include/filler.h
src/tools.o: include/libft.h
