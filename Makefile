# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouchik <abouchik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 20:12:23 by abdelilah         #+#    #+#              #
#    Updated: 2024/11/09 17:21:54 by abouchik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJ = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c \
	ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c \
	ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c  \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_strjoin.c
	
BOBJ =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstclear.c ft_lstadd_back.c

SRC = ${OBJ:.c=.o}

BSRC = ${BOBJ:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRC)
	ar rcs $(NAME) $(SRC)

$(SRC) : $(OBJ)
	$(CC) $(CFLAGS) -c $(OBJ)

bonus :  $(BSRC)
	ar rcs $(NAME) $(BSRC)
	
$(BSRC) : $(BOBJ)
	$(CC) $(CFLAGS) -c $(BOBJ)
	
clean : 
	rm -rf $(SRC)
	
fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)
