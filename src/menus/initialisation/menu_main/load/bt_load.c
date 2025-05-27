/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** bt_load
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int init_bt_load(menu_t *main, win_t *win)
{
    float x_ratio = 120.0f / 1920.0f;
    float y_ratio = 656.0f / 1080.0f;
    int w = win->mode.width;
    int h = win->mode.height;

    main->buttons[LOAD].pos = (sfVector2f){w * x_ratio, h *y_ratio};
    main->buttons[LOAD].size = (sfVector2f){170, 84.7};
    main->buttons[LOAD].texture =
        sfTexture_createFromFile("assets/images/load_text.png", NULL);
    main->buttons[LOAD].rect = sfRectangleShape_create();
    if (!main->buttons[LOAD].rect || !main->buttons[LOAD].texture ||
        init_hover_right(main, LOAD) == 84 ||
        init_sound_click(main, LOAD) == 84)
        return 84;
    main->buttons[LOAD].isclickable = 1;
    main->buttons[LOAD].func_of = change_scene_load;
    return 0;
}
