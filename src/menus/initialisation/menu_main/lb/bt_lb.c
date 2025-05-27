/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** bt_lb
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int init_hover_left(menu_t *menu, int bt)
{
    sfFont *font = sfFont_createFromFile("assets/fonts/Celsius Flower.ttf");
    int pos_x = menu->buttons[bt].pos.x - 10;
    int pos_y = 0;
    sfFloatRect local_bounds;

    menu->buttons[bt].hover = sfText_create();
    if (!font || !menu->buttons[bt].hover)
        return 84;
    sfText_setFont(menu->buttons[bt].hover, font);
    sfText_setString(menu->buttons[bt].hover, ">");
    sfText_setCharacterSize(menu->buttons[bt].hover, 30);
    sfText_setFillColor(menu->buttons[bt].hover, sfWhite);
    local_bounds = sfText_getLocalBounds(menu->buttons[bt].hover);
    pos_y = menu->buttons[bt].pos.y -
        (menu->buttons[bt].size.y / 6.2f) + (local_bounds.height / 2.0f)
        + local_bounds.top;
    sfText_setPosition(menu->buttons[bt].hover, (sfVector2f){pos_x, pos_y});
    return 0;
}

int init_bt_lb(menu_t *main, win_t *win)
{
    float x_ratio = 1624.0f / 1920.0f;
    float y_ratio = 346.0f / 1080.0f;
    int w = win->mode.width;
    int h = win->mode.height;

    main->buttons[LB].pos = (sfVector2f){w * x_ratio, h * y_ratio};
    main->buttons[LB].size = (sfVector2f){252, 60};
    main->buttons[LB].texture =
        sfTexture_createFromFile("assets/images/lb_text.png", NULL);
    main->buttons[LB].rect = sfRectangleShape_create();
    if (!main->buttons[LB].rect || !main->buttons[LB].texture ||
        init_hover_left(main, LB) == 84 ||
        init_sound_click(main, LB) == 84)
        return 84;
    main->buttons[LB].isclickable = 1;
    main->buttons[LB].func_of = change_scene_stats;
    return 0;
}
