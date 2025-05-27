/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** bt_p_exit
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int init_bt_p_exit(menu_t *pause, win_t *win)
{
    float x_ratio = 120.0f / 1920.0f;
    float y_ratio = 734.0f / 1080.0f;
    int w = win->mode.width;
    int h = win->mode.height;

    pause->buttons[P_EXIT].pos = (sfVector2f){w * x_ratio, h *y_ratio};
    pause->buttons[P_EXIT].size = (sfVector2f){142.25, 86.7};
    pause->buttons[P_EXIT].texture =
        sfTexture_createFromFile("assets/images/exit_text2.png", NULL);
    pause->buttons[P_EXIT].rect = sfRectangleShape_create();
    if (!pause->buttons[P_EXIT].rect || !pause->buttons[P_EXIT].texture ||
        init_hover_right(pause, P_EXIT) == 84 ||
        init_sound_click(pause, P_EXIT) == 84)
        return 84;
    pause->buttons[P_EXIT].isclickable = 1;
    pause->buttons[P_EXIT].func_of = exit_window;
    return 0;
}
