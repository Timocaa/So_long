# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlafont <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 12:46:05 by tlafont           #+#    #+#              #
#    Updated: 2022/05/23 13:41:26 by tlafont          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef PERC
BASENAME = `basename $(PWD)`
CR = "\r"$(CLEAR)
CLEAR = "\\033[0K"

HIT_TOTAL != ${MAKE} ${MAKECMDGOALS} --dry-run PERC="HIT_MARK" | grep -c "HIT_MARK"
HIT_COUNT = $(eval HIT_N != expr ${HIT_N} + 1)${HIT_N}
PERC = `expr ${HIT_COUNT} '*' 100 / ${HIT_TOTAL}`
endif

EOC:="\033[0;0m"
CLIC:="\033[01;05m"
GREEN:="\033[1;32m"
WHITE:="\033[1;37m"
FRED:="\033[01;41m"
FBLUE:="\033[01;44m"

SRCS = ft_memset.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isprint.c ft_strlen.c ft_bzero.c ft_memcpy.c ft_isascii.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strcpy.c ft_strcat.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_isblank.c ft_iscntrl.c ft_isgraph.c ft_islower.c ft_isspace.c ft_isupper.c ft_memccpy.c ft_isxdigit.c ft_memalloc.c ft_memdel.c ft_putchar.c ft_putendl.c ft_putstr.c ft_putnbr.c ft_strcapitalize.c ft_strcasecmp.c ft_strcmp.c ft_strlowcase.c ft_strcasestr.c ft_strstr.c ft_strclr.c ft_strdel.c ft_strequ.c ft_str_is_alpha.c ft_str_is_lowercase.c ft_str_is_numeric.c ft_str_is_printable.c ft_str_is_uppercase.c ft_striter.c ft_strmap.c ft_strncasecmp.c ft_strncat.c ft_strncpy.c ft_strndup.c ft_strnequ.c ft_strnew.c ft_strupcase.c ft_intlen.c get_next_line.c ft_flags_and_arg.c ft_flags_utils.c ft_printaddr.c ft_printchar.c ft_printf.c ft_print_hexa.c ft_printint.c ft_printstr.c ft_printunsigned.c ft_structur.c ft_atoll.c ft_sort_int_tab.c

OBJS = $(addprefix src/, $(SRCS:.c=.o))

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CLIB = ar

LFLAGS = rcs

RM = rm -f

NAME = libft.a

.c.o:
				@$(CC) -D BUFFER_SIZE=1000 $(CFLAGS) -c $< -o $(<:.c=.o)
				@printf $(CR)"[ \e[32m$(PERC)\e[39m/100] $(BASENAME)/%s"$(CLEAR) $@

$(NAME):        $(OBJS)
				@$(CLIB) $(LFLAGS) $(NAME) $(OBJS)
				@printf $(CR)$(GREEN)$(CLIC)"libft.a created successfully !\n"$(EOC)$(CLEAR) $@

all:            $(NAME)

clean:
				clear
				@$(RM) $(OBJS)
				@printf $(CR)$(FBLUE)"Libft files.o deleted !\n"$(EOC)$(CLEAR) $@

fclean:
				clear
				@$(RM) $(OBJS)
				@$(RM) $(NAME)
				@printf $(CR)$(FRED)"Libft binaries deleted !\n"$(EOC)$(CLEAR) $@

re:
				@$(RM) $(OBJS)
				@$(RM) $(NAME)
				@printf $(CR)$(FRED)"Libft binaries deleted !\n"$(EOC)$(CLEAR) $@
				@$(MAKE) --no-print-directory all

.PHONY:         all clean fclean re
