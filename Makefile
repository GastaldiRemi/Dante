##
## Makefile for makefie in /home/gastal_r/rendu/CPE_2015/CPE_2015_Lemin/remi
##
## Made by remi gastal_r
## Login   <gastal_r@epitech.net>
##
## Started on  Tue Apr 19 14:47:11 2016 remi gastal_r
## Last update Thu Jun 23 10:07:59 2016 
##

ECHO			=	/bin/echo -e
DEFAULT			=	"\033[00m"
GREEN			=	"\033[0;32m"
TEAL			=	"\033[1;36m"
RED			=	"\033[0;31m"

CC			=       gcc -O3

RM			=       rm -rf

PROFONDEUR		=	profondeur/solver

LARGEUR			=	largeur/solver

ASTAR			=	astar/solver

SRC_ASTAR		=	sources/astar/main.c			\
				sources/common/my_str_to_wordtab.c	\
				sources/astar/get_path.c		\
				sources/astar/my_math.c			\
				sources/astar/utils.c			\
				sources/astar/list_fonc.c		\
				sources/astar/check_dir.c		\
				sources/astar/check_list.c

SRC_PROFONDEUR		=       sources/profondeur/main.c		\
				sources/profondeur/utils.c		\
				sources/profondeur/list_fonc.c		\
				sources/profondeur/get_path.c		\
				sources/common/my_str_to_wordtab.c	\
				sources/profondeur/check_dir.c		\
				sources/profondeur/check_fonc.c

SRC_LARGEUR		=       sources/largeur/main.c			\
				sources/largeur/utils.c			\
				sources/largeur/list_fonc.c		\
				sources/largeur/get_path.c		\
				sources/largeur/check_case.c		\
				sources/common/my_str_to_wordtab.c

OBJS_PROFONDEUR		=       $(SRC_PROFONDEUR:.c=.o)
OBJS_LARGEUR		=       $(SRC_LARGEUR:.c=.o)
OBJS_ASTAR		=	$(SRC_ASTAR:.c=.o)

CFLAGS			+=	-Wextra -Wall -Werror
CFLAGS			+=	-ansi -pedantic
CFLAGS			+=	-I./include

all     		:        title $(PROFONDEUR) $(LARGEUR) $(ASTAR)
				 cd generateur && make
				 cp -f profondeur/solver tournoi/solver
title			:
				@$(ECHO) $(GREEN)DANTE$(DEFAULT)

$(PROFONDEUR) 		:       $(OBJS_PROFONDEUR)
				@$(CC) -o $(PROFONDEUR) $(OBJS_PROFONDEUR) && \
				 $(ECHO) $(GREEN) "[OK]" $(TEAL) $(PROFONDEUR) $(DEFAULT)  || \
				 $(ECHO) $(RED) "[XX]" $(TEAL) $(PROFONDEUR)

$(LARGEUR) 		:       $(OBJS_LARGEUR)
				@$(CC) -o $(LARGEUR) $(OBJS_LARGEUR) && \
				 $(ECHO) $(GREEN) "[OK]" $(TEAL) $(LARGEUR) $(DEFAULT)  || \
				 $(ECHO) $(RED) "[XX]" $(TEAL) $(LARGEUR)

$(ASTAR)		:	$(OBJS_ASTAR)
				@$(CC) -o $(ASTAR) $(OBJS_ASTAR) && \
				 $(ECHO) $(GREEN) "[OK]" $(TEAL) $(ASTAR) $(DEFAULT)  || \
				 $(ECHO) $(RED) "[XX]" $(TEAL) $(ASTAR)

clean			:
				@$(RM) $(PROFONDEUR) $(LARGEUR) $(ASTAR)

fclean			:       clean
				@$(RM) $(OBJS_PROFONDEUR) $(OBJS_LARGEUR) $(OBJS_ASTAR)
				 cd generateur && make fclean
				 rm -f tournoi/*

re			:       clean fclean all

.PHONNY			:       all clean fclean re

.c.o			:
				@$(CC) $(CFLAGS) -c $< -o $@  && \
				 $(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) || \
				 $(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)

$(shell   mkdir -p profondeur largeur astar tournoi)
