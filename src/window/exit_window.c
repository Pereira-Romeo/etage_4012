/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** exit_window
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int exit_window(wolf3d_t *w3d)
{
    sfRenderWindow_close(w3d->win->sfwin);
    return 0;
}
