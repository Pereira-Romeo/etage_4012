/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** func_save_game
*/

#include "wolf3d.h"

int save_game_func(wolf3d_t *w3d)
{
    char *save_name = "user_save";

    if (!handle_save_load(save_name, &(w3d->game->level), sfFalse))
        return 0;
    return 1;
}
