# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thgiraud <thgiraud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 17:47:51 by thgiraud          #+#    #+#              #
#    Updated: 2017/03/17 12:46:53 by thgiraud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= server

SRC		= main.cpp

OBJ		= $(addprefix $(OBJDIR),$(SRC:.cpp=.o))

# compiler
CC		= g++
CFLAGS	= -Wall -Wextra -Werror

# directories
SRCDIR	= ./srcs/
INCDIR	= ./incs/
OBJDIR	= ./objs/
LIBDIR  = ./libs/

# ft library
FT		= $(addprefix $(LIBDIR), libft/)
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I $(addprefix $(FT), includes)
FT_LNK	= -L $(FT) -l ft

all: obj $(FT_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.cpp
	$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) $(FT_INC) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FT_LNK) -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all