# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 19:28:38 by agil-ord          #+#    #+#              #
#    Updated: 2023/03/06 18:36:53 by agil-ord         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE = -I ./includes

NAME	= libft.a

DIR_LIBFT = ./src/libft_s

DIR_PRINTF = ./src/printf_s

DIR_GET_NEXT_LINE = ./src/get_next_line_s

SRCS		=	ft_isalnum.c ft_isalpha.c ft_isascii.c \
				ft_isdigit.c ft_isprint.c ft_memset.c \
				ft_strchr.c ft_strlen.c ft_strrchr.c \
				ft_tolower.c ft_toupper.c ft_bzero.c ft_strncmp.c \
				ft_memcpy.c ft_memmove.c ft_memchr.c \
				ft_memcmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_split.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_itoa.c \
				ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c \
				ft_lstmap_bonus.c

PRINTF_SRC	=	ft_printf.c ft_putchar_printf.c ft_putstr_printf.c \
			 	ft_putnbr_hex_p.c ft_putnbr_uns_printf.c \
				ft_putnbr_printf.c ft_putnbr_hex_cap.c

GET_NEXT_LINE_SRC	=	get_next_line_utils_bonus.c get_next_line_utils.c \
						get_next_line.c get_next_line_bonus.c		

SUPER_SRC = ${addprefix ${DIR_LIBFT}/,${SRCS}} \
			${addprefix ${DIR_PRINTF}/,${PRINTF_SRC}} \
			${addprefix ${DIR_GET_NEXT_LINE}/,${GET_NEXT_LINE_SRC}}

OBJS	=	${SUPER_SRC:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra ${INCLUDE}

RM		=	rm -f

ifdef DEBUG
	CC += -g
endif

all: ${NAME}

${NAME}: ${OBJS} 
			ar crs ${NAME} ${OBJS} 
%.o: %.c
			${CC} -c ${CFLAGS} $< -o $@

clean:		
				${RM} ${OBJS} 

fclean:		clean
						${RM} ${NAME}


re:			fclean all

.PHONY: all clean fclean re