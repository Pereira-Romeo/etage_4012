/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** func_save_game
*/

#include "wolf3d.h"

int save_game_func(wolf3d_t *w3d)
{
    const char *save_filename = "savelevel.sav";

    if (!save_level(save_filename, &(w3d->game->level))) {
        return 0;
    }
    return 1;
}
