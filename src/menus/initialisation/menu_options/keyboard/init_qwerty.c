/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_qwerty
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

static
int check_malloc(menu_t *options)
{
    if (!options->buttons[QWERTY].texture ||
        !options->buttons[QWERTY].rect) {
        return 84;
    }
    return 0;
}

int init_qwerty(menu_t *options, win_t *win)
{
    (void)win;
    options->buttons[QWERTY].pos = (sfVector2f){1222.8, 689.1};
    options->buttons[QWERTY].size = (sfVector2f){403, 101};
    options->buttons[QWERTY].texture =
        sfTexture_createFromFile("assets/images/qwertywasd.png", NULL);
    options->buttons[QWERTY].rect = sfRectangleShape_create();
    options->buttons[QWERTY].isclickable = 0;
    return check_malloc(options);
}
