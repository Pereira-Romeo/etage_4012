/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** change_scene_guide
*/

#include "wolf3d.h"

int change_scene_game(wolf3d_t *w3d)
{
    setup_game(w3d->win, w3d->game, NULL);
    w3d->prev_scene = w3d->scene;
    w3d->scene = GAME;
    return 0;
}
