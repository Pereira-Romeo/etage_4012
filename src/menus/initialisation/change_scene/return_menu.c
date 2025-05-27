/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** return_menu
*/

#include "wolf3d.h"

int return_func(wolf3d_t *w3d)
{
    int tmp = w3d->scene;

    w3d->scene = w3d->prev_scene;
    if (w3d->scene == PAUSE)
        w3d->prev_scene = GAME;
    else
        w3d->prev_scene = tmp;
    return 0;
}
