/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** change_scene_stats
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int change_scene_stats(wolf3d_t *w3d)
{
    w3d->prev_scene = w3d->scene;
    w3d->scene = STATS;
    return 0;
}
