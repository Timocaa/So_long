# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlafont <tlafont@student.42angouleme.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 09:21:47 by tlafont           #+#    #+#              #
#    Updated: 2022/06/08 15:21:28 by tlafont          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================================================================
#---------------------------- progress indicator --------------------------------

ifndef PERC
BASENAME	= `basename $(PWD)`
CR			= "\r"$(CLEAR)
CLEAR		= "\\033[0K"

HIT_TOTAL != ${MAKE} ${MAKECMDGOALS} --dry-run PERC="HIT_MARK" | grep -c "HIT_MARK"
HIT_COUNT = $(eval HIT_N != expr ${HIT_N} + 1)${HIT_N}
PERC = `expr ${HIT_COUNT} '*' 100 / ${HIT_TOTAL}`
endif

# ================================================================================
#---------------------------------- Colors ---------------------------------------

EOC:="\033[0;0m"
CLIC:="\033[01;05m"
GREEN:="\033[1;32m"
WHITE:="\033[1;37m"
FRED:="\033[01;41m"
FBLUE:="\033[01;44m"

# ================================================================================
#---------------------------------- General --------------------------------------

NAME	= so_long
NAMEB	= so_long_bonus

# ================================================================================
#--------------------------------- GNU compiler ----------------------------------

CC		= gcc -g

CFLAGS	= -Wall -Wextra -Werror

MLX	= -Lmlx/ -lmlx -L/usr/lib -lXext -lX11 -lm -lz

# ================================================================================
#------------------------------- System Commands ---------------------------------

RM			= rm

RD			= -rf

RF			= -f

SIL			= --no-print-directory

#================================================================================
#---------------------------------- Files Source ---------------------------------

SRC		= main.c ft_error.c ft_check_args.c ft_init_game.c ft_move_player.c
SRCB	= main_bonus.c ft_error_bonus.c ft_check_args_bonus.c ft_init_game_bonus.c ft_open_img_bonus.c ft_update_bonus.c ft_update_map_bonus.c ft_move_pnj_bonus.c ft_move_player_bonus.c


# ================================================================================
#------------------------------- Directory source ----------------------------------

SRCDIR	= src/
DINC	= inc/
DLIB	= libft/
DMLX	= mlx/

# ================================================================================
#------------------------------- Auto Directory ----------------------------------

OBJS = $(addprefix $(SRCDIR), $(SRC:.c=.o))
OBJSB = $(addprefix $(SRCDIR), $(SRCB:.c=.o))

# ================================================================================
#------------------------------------- Rules -------------------------------------

$(NAME):	$(OBJS)
			@clear
			@$(MAKE) $(SIL) -C $(DLIB)
			@$(MAKE) $(SIL) -C $(DMLX)
			@$(CC) -o $(NAME) $(OBJS) -L$(DLIB) -lft $(MLX)
			@printf $(CR)$(GREEN)$(CLIC)"successfully created program !\n"$(EOC)$(CLEAR) $@

$(NAMEB):	$(OBJSB)
			@clear
			@$(MAKE) $(SIL) -C $(DLIB)
			@$(MAKE) $(SIL) -C $(DMLX)
			@$(CC) -o $(NAMEB) $(OBJSB) -L$(DLIB) -lft $(MLX)
			@printf $(CR)$(GREEN)$(CLIC)"successfully created bonus !\n"$(EOC)$(CLEAR) $@

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $@
			@printf $(CR)"[ \e[32m$(PERC)\e[39m/100] $(BASENAME)/%s"$(CLEAR) $@

all:		$(NAME)

bonus:		$(NAMEB)

clean:
			clear
			@$(MAKE) $(SIL) -C $(DLIB) clean
			@$(RM) $(RF) $(OBJS)
			@$(RM) $(RF) $(OBJSB)
			@printf $(CR)$(FBLUE)"pipex files.o deleted !\n"$(EOC)$(CLEAR) $@

fclean:
			clear
			@$(MAKE) $(SIL) -C $(DLIB) fclean
			@$(MAKE) -C $(DMLX) clean
			@$(RM) $(RF) $(OBJS)
			@$(RM) $(RF) $(OBJSB)
			@$(RM) $(RF) $(NAME)
			@$(RM) $(RF) $(NAMEB)
			@printf $(CR)$(FRED)"all binaries deleted !\n"$(EOC)$(CLEAR) $@

re:
			clear
			@$(MAKE) $(SIL) -C $(DLIB) fclean
			@$(MAKE) -C $(DMLX) clean
			@$(RM) $(RF) $(OBJS)
			@$(RM) $(RF) $(NAME)
			@printf $(CR)$(FRED)"all binaries deleted !\n"$(EOC)$(CLEAR) $@
			@$(MAKE) --no-print-directory

.PHONY:	all bonus clean fclean re
