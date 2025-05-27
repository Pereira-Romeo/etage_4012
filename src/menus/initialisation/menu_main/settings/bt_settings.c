/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** bt_settings
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int init_bt_settings(menu_t *main, win_t *win)
{
    float x_ratio = 120.0f / 1920.0f;
    float y_ratio = 578.0f / 1080.0f;
    int w = win->mode.width;
    int h = win->mode.height;

    main->buttons[SETTINGS].pos = (sfVector2f){w * x_ratio - 4, h * y_ratio};
    main->buttons[SETTINGS].size = (sfVector2f){256, 100};
    main->buttons[SETTINGS].texture =
        sfTexture_createFromFile("assets/images/settings_text2.png", NULL);
    main->buttons[SETTINGS].rect = sfRectangleShape_create();
    if (!main->buttons[SETTINGS].rect || !main->buttons[SETTINGS].texture ||
        init_hover_right(main, SETTINGS) == 84 ||
        init_sound_click(main, SETTINGS) == 84)
        return 84;
    main->buttons[SETTINGS].isclickable = 1;
    main->buttons[SETTINGS].func_of = change_scene_options;
    return 0;
}
