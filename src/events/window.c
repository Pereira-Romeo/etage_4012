/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** window
*/

#include "wolf3d.h"

void window_resize_event(win_t *win, sfEvent *event)
{
    win->mode.height = event->size.height;
    win->mode.width = event->size.width;
    printf("Window resized to height: %u, width: %u\n",
    win->mode.height, win->mode.width);
}
