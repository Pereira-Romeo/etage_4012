/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** bt_quit
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int init_bt_quit(menu_t *main, win_t *win)
{
    float x_ratio = 120.0f / 1920.0f;
    float y_ratio = 734.0f / 1080.0f;
    int w = win->mode.width;
    int h = win->mode.height;

    main->buttons[EXIT].pos = (sfVector2f){w * x_ratio, h *y_ratio};
    main->buttons[EXIT].size = (sfVector2f){142.25, 86.7};
    main->buttons[EXIT].texture =
        sfTexture_createFromFile("assets/images/exit_text2.png", NULL);
    main->buttons[EXIT].rect = sfRectangleShape_create();
    if (!main->buttons[EXIT].texture || init_hover_right(main, EXIT) == 84 ||
        !main->buttons[EXIT].rect ||
        init_sound_click(main, EXIT) == 84)
        return 84;
    main->buttons[EXIT].isclickable = 1;
    main->buttons[EXIT].ishovered = 0;
    main->buttons[EXIT].func_of = exit_window;
    return 0;
}
