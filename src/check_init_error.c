/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** check_init_error
*/

#include "wolf3d.h"


static
int game_init_eror(game_t *game)
{
    if (!(game->mini_map))
        return sfTrue;
    if (!(game->column))
        return sfTrue;
    if (!(game->gun))
        return sfTrue;
    return sfFalse;
}

int wolf_init_error(wolf3d_t *w3d, int menu_init)
{
    if (!(w3d->win))
        return sfTrue;
    if (menu_init == 84)
        return sfTrue;
    if (game_init_eror(w3d->game))
        return sfTrue;
    return sfFalse;
}
