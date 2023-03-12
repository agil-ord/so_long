INCLUDE 	= 	-I ./libft/includes -I ./includes -I ./MLX42/include/MLX42 -I ./memory-leaks/include

MLX_DIR		=	./MLX42

LIB_GLFW	=	-lglfw -L /Users/agil-ord/.brew/opt/glfw/lib 

LIB_MLX		=	-lmlx42 -L${MLX_DIR}

NAME		=	so_long

DIR_LEAKS	=	./memory-leaks

DIR_SO_LONG = ./src

SRC_SO_LONG =	so_long.c check_map.c move.c \
				map.c draw_images.c collectibles.c \
				check_map2.c

SRCS		=	${addprefix ${DIR_SO_LONG}/,${SRC_SO_LONG}}

#OBJS		=	${addprefix ${DIR_SO_LONG}/,${SRC_SO_LONG:.c=.o}}

#LMX_FLAG 	= 	-lmlx -framework OpenGL -framework AppKit

LIBFT_DIR	=	./libft

AR			=	ar	-crs ${INCLUDE}

CC			=	gcc

CFLAG		= ${INCLUDE}

RM			=	rm -f

ifdef DEBUG 
	CC += -g
	MAKE += DEBUG=1
endif

all: submodules ${NAME}

submodules: 
	@git submodule update --init

${NAME}: 		submodules	${SRCS}
		
		@${MAKE} -C ${DIR_LEAKS}
		@${MAKE} -C ${LIBFT_DIR}
		${MAKE} -C ${MLX_DIR}
		@${CC} ${CFLAG} ${SRCS} ${LIBFT_DIR}/libft.a ${LIB_GLFW} ${LIB_MLX}  -o ${NAME} -g ./memory-leaks/memory_leaks.a

clean:	
		@make clean -C ${LIBFT_DIR} 
		@make clean -C ${MLX_DIR}

fclean:	clean
		@make fclean -C ${LIBFT_DIR} 
		@make fclean -C ${MLX_DIR}
		${RM} ${NAME}
		
re:	fclean all

.PHONY: all	clean fclean re
