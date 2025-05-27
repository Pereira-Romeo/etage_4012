/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** bt_return
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int init_bt_return_load(menu_t *load, win_t *win)
{
    (void)win;
    load->buttons[RETURN_LOAD].pos = (sfVector2f){63.7, 44};
    load->buttons[RETURN_LOAD].size = (sfVector2f){115, 51};
    load->buttons[RETURN_LOAD].texture =
        sfTexture_createFromFile("assets/images/back_maj_text.png", NULL);
    load->buttons[RETURN_LOAD].rect = sfRectangleShape_create();
    if (!load->buttons[RETURN_LOAD].texture ||
        !load->buttons[RETURN_LOAD].rect ||
        init_sound_click(load, RETURN_LOAD) == 84)
        return 84;
    load->buttons[RETURN_LOAD].isclickable = 1;
    load->buttons[RETURN_LOAD].func_of = return_func;
    return 0;
}
