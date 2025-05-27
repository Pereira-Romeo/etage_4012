/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** bt_p_guide
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int init_bt_p_guide(menu_t *pause, win_t *win)
{
    float x_ratio = 1700.0f / 1920.0f;
    float y_ratio = 400.0f / 1080.0f;
    int w = win->mode.width;
    int h = win->mode.height;

    pause->buttons[P_GUIDE].pos = (sfVector2f){w * x_ratio, h * y_ratio};
    pause->buttons[P_GUIDE].size = (sfVector2f){169.5, 75};
    pause->buttons[P_GUIDE].texture =
        sfTexture_createFromFile("assets/images/guide_text.png", NULL);
    pause->buttons[P_GUIDE].rect = sfRectangleShape_create();
    if (!pause->buttons[P_GUIDE].rect || !pause->buttons[P_GUIDE].texture ||
        init_hover_left(pause, P_GUIDE) == 84 ||
        init_sound_click(pause, P_GUIDE) == 84)
        return 84;
    pause->buttons[P_GUIDE].isclickable = 1;
    pause->buttons[P_GUIDE].func_of = change_scene_guide;
    return 0;
}
