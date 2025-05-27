/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** init_window
*/

#include "window.h"
#include <unistd.h>
#include <errno.h>

int init_window_error(win_t *win)
{
    if (!(win->fps_clock) || !(win->sfwin)) {
        if (!(win->fps_clock))
            write(STDERR_FILENO, "Init window: clock failure\n", 27);
        if (!(win->sfwin))
            write(STDERR_FILENO, "Init window: window failure\n", 28);
        free_window(win);
        return sfTrue;
    }
    return sfFalse;
}

win_t *init_window(win_t *win)
{
    win->sfwin = sfRenderWindow_create(win->mode, WIN_NAME2,
    sfClose | sfResize, NULL);
    win->fps_clock = sfClock_create();
    if (init_window_error(win))
        return NULL;
    sfRenderWindow_setFramerateLimit(win->sfwin, WIN_FPS);
    return win;
}

void free_window(win_t *win)
{
    if (!win)
        return;
    if (win->sfwin)
        sfRenderWindow_destroy(win->sfwin);
    if (win->fps_clock)
        sfClock_destroy(win->fps_clock);
}
