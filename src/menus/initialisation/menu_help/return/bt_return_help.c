/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** bt_return
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int init_bt_return_help(menu_t *help, win_t *win)
{
    (void)win;
    help->buttons[RETURN_HELP].pos = (sfVector2f){63.7, 44};
    help->buttons[RETURN_HELP].size = (sfVector2f){115, 51};
    help->buttons[RETURN_HELP].texture =
        sfTexture_createFromFile("assets/images/back_maj_text.png", NULL);
    if (!help->buttons[RETURN_HELP].texture)
        return 84;
    help->buttons[RETURN_HELP].rect = sfRectangleShape_create();
    if (!help->buttons[RETURN_HELP].rect ||
        init_sound_click(help, RETURN_HELP) == 84)
        return 84;
    help->buttons[RETURN_HELP].isclickable = 1;
    help->buttons[RETURN_HELP].func_of = return_func;
    return 0;
}
