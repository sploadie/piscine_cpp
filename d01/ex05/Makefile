# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/04 11:04:01 by tgauvrit          #+#    #+#              #
#    Updated: 2016/04/05 16:04:46 by tgauvrit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				./hello_human

CC =				clang++

FLAGS =				-Wall -Werror -Wextra

HEADERS =			-I ./

SRC_DIR =			./

COMPILED_DIR_NAME =	compiled
COMPILED_DIR =		./$(COMPILED_DIR_NAME)/

FILENAMES =			Brain Human main

COMPILED_PATHS :=	$(addsuffix .o,$(FILENAMES))
COMPILED_PATHS :=	$(addprefix $(COMPILED_DIR),$(COMPILED_PATHS))

all: $(NAME)

$(NAME): $(COMPILED_PATHS)
	$(CC) -o $(NAME) $(FLAGS) $(HEADERS) $(COMPILED_PATHS)

$(COMPILED_PATHS): $(COMPILED_DIR)%.o: $(SRC_DIR)%.cpp
	@/bin/mkdir -p $(COMPILED_DIR)
	$(CC) -c $(FLAGS) $(HEADERS) $< -o $@

clean:
	-/bin/rm -f $(COMPILED_PATHS)
	/usr/bin/find . -name "$(COMPILED_DIR_NAME)" -maxdepth 1 -type d -empty -delete

fclean: clean
	-/bin/rm -f $(NAME)

re: fclean all
