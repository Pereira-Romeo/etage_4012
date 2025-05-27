/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** error_displayer
*/

#include "wolf3d.h"
#include <string.h>

static
void free_err_displayer(sfRenderWindow *win, sfText *text, sfFont *font)
{
    sfFont_destroy(font);
    sfText_destroy(text);
    sfRenderWindow_close(win);
    sfRenderWindow_destroy(win);
}

static
void setup_error_text(sfText *err_text, sfFont *font, char *err)
{
    sfText_setFont(err_text, font);
    sfText_setCharacterSize(err_text, 20);
    sfText_setOutlineThickness(err_text, 0.1);
    sfText_setString(err_text, err);
}

static
void display_err_window(sfRenderWindow *err_win,
    sfFont *font, sfText *err_text, char *err)
{
    sfRenderWindow_setPosition(err_win, (sfVector2i){100, 100});
    sfRenderWindow_clear(err_win, sfRed);
    setup_error_text(err_text, font, err);
    sfRenderWindow_drawText(err_win, err_text, NULL);
    sfRenderWindow_display(err_win);
    sleep(5);
    free_err_displayer(err_win, err_text, font);
}

/** check for errors while initializing error_display
 * if an error is detected, close the window to initiate shutdown
 */
static
int init_error(win_t *win,
    sfRenderWindow *err_win, sfText *err_text, sfFont *font)
{
    if (!err_win || !err_text || !font) {
        if (err_win) {
            sfRenderWindow_close(err_win);
            sfRenderWindow_destroy(err_win);
        }
        if (font)
            sfFont_destroy(font);
        if (err_text)
            sfText_destroy(err_text);
        if (win->sfwin)
            sfRenderWindow_close(win->sfwin);
        return sfTrue;
    }
    return sfFalse;
}

int display_error(win_t *win, char *err, int val)
{
    sfRenderWindow *err_win = sfRenderWindow_create(
    (sfVideoMode){400, 230, 32}, "wolf3d - error window", 0, NULL);
    sfFont *font = sfFont_createFromFile("assets/fonts/arial.ttf");
    sfText *err_text = sfText_create();

    write(STDERR_FILENO, "Wolf3d Error Manager:\n", 22);
    write(STDERR_FILENO, err, strlen(err));
    if (val == 84) {
        write(STDERR_FILENO, "Fatal error, shutdown required...\n", 34);
        if (win->sfwin)
            sfRenderWindow_close(win->sfwin);
    }
    if (!init_error(win, err_win, err_text, font))
        display_err_window(err_win, font, err_text, err);
    return val;
}
