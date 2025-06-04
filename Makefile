##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## general Makefile
##

SRC := main.c
SRC += $(wildcard src/*.c)
SRC += $(wildcard src/audio/*.c)
SRC += $(wildcard src/events/*.c)
SRC += $(wildcard src/game/*.c)
SRC += $(wildcard src/game/gun/*.c)
SRC += $(wildcard src/game/entity/*.c)
SRC += $(wildcard src/game/hud/*.c)
SRC += $(wildcard src/game/level/*.c)
SRC += $(wildcard src/game/map/*.c)
SRC += $(wildcard src/game/map/mini_map/*.c)
SRC += $(wildcard src/window/*.c)
SRC += $(wildcard src/menus/*.c)
SRC += $(wildcard src/menus/initialisation/*.c)
SRC += $(wildcard src/menus/initialisation/menu_options/*.c)
SRC += $(wildcard src/menus/initialisation/menu_options/keyboard/*.c)
SRC += $(wildcard src/menus/initialisation/menu_options/music/*.c)
SRC += $(wildcard src/menus/initialisation/menu_options/sfx/*.c)
SRC += $(wildcard src/menus/initialisation/menu_main/*.c)
SRC += $(wildcard src/menus/initialisation/menu_main/start/*.c)
SRC += $(wildcard src/menus/initialisation/menu_main/lb/*.c)
SRC += $(wildcard src/menus/initialisation/menu_main/settings/*.c)
SRC += $(wildcard src/menus/initialisation/menu_main/load/*.c)
SRC += $(wildcard src/menus/initialisation/menu_main/quit/*.c)
SRC += $(wildcard src/menus/initialisation/menu_main/guide/*.c)
SRC += $(wildcard src/menus/initialisation/menu_load/*.c)
SRC += $(wildcard src/menus/initialisation/menu_load/return/*.c)
SRC += $(wildcard src/menus/initialisation/menu_help/*.c)
SRC += $(wildcard src/menus/initialisation/menu_help/return/*.c)
SRC += $(wildcard src/menus/initialisation/menu_help/info/*.c)
SRC += $(wildcard src/menus/initialisation/menu_stats/*.c)
SRC += $(wildcard src/menus/initialisation/menu_stats/return/*.c)
SRC += $(wildcard src/menus/initialisation/menu_pause/*.c)
SRC += $(wildcard src/menus/initialisation/menu_pause/p_exit/*.c)
SRC += $(wildcard src/menus/initialisation/menu_pause/p_guide/*.c)
SRC += $(wildcard src/menus/initialisation/menu_pause/p_settings/*.c)
SRC += $(wildcard src/menus/initialisation/menu_pause/resume/*.c)
SRC += $(wildcard src/menus/initialisation/menu_pause/save/*.c)
SRC += $(wildcard src/menus/initialisation/change_scene/*.c)
SRC += $(wildcard src/musics/*.c)

OBJ = $(SRC:.c=.o)

NAME = wolf3d

CFLAGS = -Wall -Wextra -iquote include

LDFLAGS = -lm -lcsfml-graphics -lcsfml-system -lcsfml-audio

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
