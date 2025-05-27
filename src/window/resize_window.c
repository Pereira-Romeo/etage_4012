/*
** EPITECH PROJECT, 2025
** wolf3D_re
** File description:
** resize_window
*/

#include "wolf3d.h"

int resize_window(win_t *win, sfVideoMode mode, sfBool fullscreen)
{
    sfUint32 style = (fullscreen) ? sfFullscreen : sfClose;
    sfVector2u win_size = {0, 0};
    sfVideoMode new_mode = {mode.width, mode.height, mode.bitsPerPixel};

    sfRenderWindow_close(win->sfwin);
    sfRenderWindow_destroy(win->sfwin);
    win->sfwin = sfRenderWindow_create(mode, WIN_NAME4, style, NULL);
    if (!(win->sfwin))
        return display_error(win, "Window resize failure\n", 84);
    if (fullscreen) {
        win_size = sfRenderWindow_getSize(win->sfwin);
        new_mode = (sfVideoMode){win_size.x, win_size.y, mode.bitsPerPixel};
    }
    win->mode = new_mode;
    sfRenderWindow_setFramerateLimit(win->sfwin, WIN_FPS);
    return 0;
}
