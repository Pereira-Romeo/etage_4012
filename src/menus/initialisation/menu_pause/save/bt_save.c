/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** bt_save
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int init_bt_save(menu_t *pause, win_t *win)
{
    float x_ratio = 120.0f / 1920.0f;
    float y_ratio = 656.0f / 1080.0f;
    int w = win->mode.width;
    int h = win->mode.height;

    pause->buttons[SAVE].pos = (sfVector2f){w * x_ratio, h * y_ratio};
    pause->buttons[SAVE].size = (sfVector2f){169.3, 90.25};
    pause->buttons[SAVE].texture =
        sfTexture_createFromFile("assets/images/save_text.png", NULL);
    pause->buttons[SAVE].rect = sfRectangleShape_create();
    if (!pause->buttons[SAVE].rect || !pause->buttons[SAVE].texture ||
        init_hover_right(pause, SAVE) == 84 ||
        init_sound_click(pause, SAVE) == 84)
        return 84;
    pause->buttons[SAVE].isclickable = 1;
    pause->buttons[SAVE].func_of = save_game_func;
    return 0;
}
