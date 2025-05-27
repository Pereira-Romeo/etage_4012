/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** bt_start
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int init_hover_right(menu_t *menu, int bt)
{
    sfFont *font = sfFont_createFromFile("assets/fonts/Celsius Flower.ttf");
    int pos_x = menu->buttons[bt].pos.x + menu->buttons[bt].size.x;
    int pos_y = 0;
    sfFloatRect local_bounds;

    menu->buttons[bt].hover = sfText_create();
    if (!font || !menu->buttons[bt].hover)
        return 84;
    sfText_setFont(menu->buttons[bt].hover, font);
    sfText_setString(menu->buttons[bt].hover, "<");
    sfText_setCharacterSize(menu->buttons[bt].hover, 50);
    sfText_setFillColor(menu->buttons[bt].hover, sfWhite);
    local_bounds = sfText_getLocalBounds(menu->buttons[bt].hover);
    pos_y = menu->buttons[bt].pos.y +
        (menu->buttons[bt].size.y / 1.8f) -
        (local_bounds.height / 2.0f) - local_bounds.top;
    sfText_setPosition(menu->buttons[bt].hover, (sfVector2f){pos_x, pos_y});
    return 0;
}

// divise par 4 puis 1.5
int init_bt_start(menu_t *main, win_t *win)
{
    float x_ratio = 120.0f / 1920.0f;
    float y_ratio = 500.0f / 1080.0f;
    int w = win->mode.width;
    int h = win->mode.height;

    main->buttons[START].pos = (sfVector2f){w * x_ratio, h * y_ratio};
    main->buttons[START].size = (sfVector2f){169.3, 85.3};
    main->buttons[START].texture =
        sfTexture_createFromFile("assets/images/start_text3.png", NULL);
    main->buttons[START].rect = sfRectangleShape_create();
    if (!main->buttons[START].texture || !main->buttons[START].rect ||
        init_hover_right(main, START) == 84 ||
        init_sound_click(main, START) == 84)
        return 84;
    main->buttons[START].isclickable = 1;
    main->buttons[START].func_of = change_scene_game;
    return 0;
}
