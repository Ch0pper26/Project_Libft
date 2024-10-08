# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eblondee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 13:40:34 by eblondee          #+#    #+#              #
#    Updated: 2023/10/30 17:17:39 by eblondee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=	./srcs/libft/ft_isalpha.c \
		./srcs/libft/ft_isdigit.c \
		./srcs/libft/ft_isalnum.c \
		./srcs/libft/ft_isascii.c \
		./srcs/libft/ft_isprint.c \
		./srcs/libft/ft_strlen.c \
		./srcs/libft/ft_memset.c \
		./srcs/libft/ft_bzero.c \
		./srcs/libft/ft_memcpy.c \
		./srcs/libft/ft_memmove.c \
		./srcs/libft/ft_strlcpy.c \
		./srcs/libft/ft_toupper.c \
		./srcs/libft/ft_tolower.c \
		./srcs/libft/ft_strchr.c \
		./srcs/libft/ft_strrchr.c \
		./srcs/libft/ft_strncmp.c \
		./srcs/libft/ft_memchr.c \
		./srcs/libft/ft_memcmp.c \
		./srcs/libft/ft_strlcat.c \
		./srcs/libft/ft_strnstr.c \
		./srcs/libft/ft_atoi.c \
		./srcs/libft/ft_strdup.c \
		./srcs/libft/ft_calloc.c \
		./srcs/libft/ft_substr.c \
		./srcs/libft/ft_strjoin.c \
		./srcs/libft/ft_strtrim.c \
		./srcs/libft/ft_split.c \
		./srcs/libft/ft_itoa.c \
		./srcs/libft/ft_strmapi.c \
		./srcs/libft/ft_striteri.c \
		./srcs/libft/ft_putchar_fd.c \
		./srcs/libft/ft_putstr_fd.c \
		./srcs/libft/ft_putendl_fd.c \
		./srcs/libft/ft_putnbr_fd.c \
		./srcs/libft/ft_lstnew.c \
		./srcs/libft/ft_lstadd_front.c \
		./srcs/libft/ft_lstsize.c \
		./srcs/libft/ft_lstlast.c \
		./srcs/libft/ft_lstadd_back.c \
		./srcs/libft/ft_lstdelone.c \
		./srcs/libft/ft_lstclear.c \
		./srcs/libft/ft_lstiter.c \
		./srcs/libft/ft_lstmap.c \
		./srcs/get_next_line/get_next_line.c \
		./srcs/get_next_line/get_next_line_utils.c \
		./srcs/printf/ft_printf.c \
		./srcs/printf/ft_printf_utils.c \
		./srcs/printf/ft_printf_utils_bis.c \
		./srcs/error/print_error.c \
		./srcs/error/ft_is.c \
		./srcs/libft_lstdc/ft_create_lstdc.c \
		./srcs/libft_lstdc/ft_free_lstdc.c \
		./srcs/libft_lstdc/ft_add_lstdc.c \
		./srcs/libft_lstdc/ft_index_lstdc.c \
		./srcs/libft_lstdc/ft_move_in_lstdc.c \
		./srcs/libft_lstdc/ft_print_lstdc.c \
        ./srcs/libft_lstdc/ft_get_lstdc.c \
        ./srcs/libft_lstdc/ft_move_elem_lstdc.c \
        ./srcs/libft_lstdc/ft_merge_lstdc.c \
        ./srcs/libft_lstdc/ft_int_lstdc.c \
        ./srcs/libft_lstdc/ft_str_lstdc.c \
        ./srcs/libft_lstdc/ft_char_lstdc.c \
        ./srcs/libft_lstdc/ft_anything_to_void.c \
        ./srcs/libft_lstdc/ft_void_to_anything.c \
		./srcs/libft_bis/ft_atoll.c \
		./srcs/libft_bis/ft_strcmp.c \
		./srcs/libft_bis/ft_strcpy.c \
		./srcs/libft_bis/ft_search_int_in_tab.c \
		./srcs/libft_bis/ft_free.c \
		./srcs/libft_bis/ft_len.c \
		./srcs/libft_bis/ft_tabchar.c \
		./srcs/libft_bis/ft_splitters.c \

OBJS = ${SRCS:.c=.o}

NAME = libft.a

CC	= gcc

RM	= rm -rf

INC = libft.h 

CFLAG = -Wall -Wextra -Werror -g -I.${INC}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

$(NAME):	${OBJS}
	ar rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
