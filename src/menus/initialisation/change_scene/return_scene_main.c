/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** return_scene_main
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int return_scene_main(wolf3d_t *w3d)
{
    w3d->prev_scene = w3d->scene;
    w3d->scene = MAIN;
    return 0;
}
