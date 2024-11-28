CC = gcc
CFLAGS = -O3 -Wall -Wextra -Werror
LDFLAGS = -lSDL2

# ----------------------------------- srcs ----------------------------------- #
SRC =	src/main.c \
		src/init.c \
		src/input.c \
		src/draw.c \
		src/map.c \
		src/rules.c
# --------------------------------- end srcs --------------------------------- #

OBJ_DIR = bin
SRC_DIR = src
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = game_of_life

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

v:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=sdl.supp ./$(NAME)

clean:
	rm -f *.o
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean
	make

.PHONY: clean fclean all re

# $@ Le nom de la cible
# $< Le nom de la première dépendance
# $^ La liste des dépendances
# $? La liste des dépendances plus récentes que la cible
# $* Le nom du fichier sans suffixe
