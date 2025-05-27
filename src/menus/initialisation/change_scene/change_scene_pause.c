/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** change_scene_pause
*/

#include "wolf3d.h"

int change_scene_pause(wolf3d_t *w3d)
{
    w3d->prev_scene = GAME;
    w3d->scene = PAUSE;
    return 0;
}
