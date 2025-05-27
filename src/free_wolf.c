/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** free_wolf
*/

#include "wolf3d.h"

void free_wolf(wolf3d_t *w3d)
{
    free_window(w3d->win);
    free_game(w3d->game);
    free_musics(w3d->sounds);
    free_menus(w3d);
}
