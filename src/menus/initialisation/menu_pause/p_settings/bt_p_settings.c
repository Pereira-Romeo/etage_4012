/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** bt_p_settings
*/


#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int init_bt_p_settings(menu_t *pause, win_t *win)
{
    float x_ratio = 120.0f / 1920.0f;
    float y_ratio = 578.0f / 1080.0f;
    int w = win->mode.width;
    int h = win->mode.height;

    pause->buttons[P_SETTINGS].pos = (sfVector2f){w * x_ratio, h * y_ratio};
    pause->buttons[P_SETTINGS].size = (sfVector2f){256, 100};
    pause->buttons[P_SETTINGS].texture =
        sfTexture_createFromFile("assets/images/settings_text2.png", NULL);
    pause->buttons[P_SETTINGS].rect = sfRectangleShape_create();
    if (!pause->buttons[P_SETTINGS].rect ||
        !pause->buttons[P_SETTINGS].texture ||
        init_hover_right(pause, P_SETTINGS) == 84 ||
        init_sound_click(pause, P_SETTINGS) == 84)
        return 84;
    pause->buttons[P_SETTINGS].isclickable = 1;
    pause->buttons[P_SETTINGS].func_of = change_scene_options;
    return 0;
}
