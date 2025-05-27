/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** bt_resume
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int init_bt_resume(menu_t *pause, win_t *win)
{
    float x_ratio = 120.0f / 1920.0f;
    float y_ratio = 500.0f / 1080.0f;
    int w = win->mode.width;
    int h = win->mode.height;

    pause->buttons[RESUME].pos = (sfVector2f){w * x_ratio, h * y_ratio};
    pause->buttons[RESUME].size = (sfVector2f){256, 90.25};
    pause->buttons[RESUME].texture =
        sfTexture_createFromFile("assets/images/resume_text.png", NULL);
    pause->buttons[RESUME].rect = sfRectangleShape_create();
    if (!pause->buttons[RESUME].rect || !pause->buttons[RESUME].texture ||
        init_hover_right(pause, RESUME) == 84 ||
        init_sound_click(pause, RESUME) == 84)
        return 84;
    pause->buttons[RESUME].isclickable = 1;
    pause->buttons[RESUME].func_of = return_func;
    return 0;
}
