/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_all_buttons
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

static
int init_background(menu_t *main)
{
    main->bg_texture =
        sfTexture_createFromFile(MENU_BG, NULL);
    if (!main->bg_texture)
        return 84;
    main->bg_sprite = sfSprite_create();
    if (!main->bg_sprite)
        return 84;
    return 0;
}

int init_struct_main(menu_t *main, win_t *win)
{
    int win_x = win->mode.width;
    int win_y = win->mode.height;
    sfVector2u texture_size;
    float scale_x;
    float scale_y;

    if (init_background(main) == 84)
        return 84;
    texture_size = sfTexture_getSize(main->bg_texture);
    scale_x = (float)win_x / texture_size.x;
    scale_y = (float)win_y / texture_size.y;
    sfSprite_setTexture(main->bg_sprite, main->bg_texture, sfTrue);
    sfSprite_setScale(main->bg_sprite, (sfVector2f){scale_x, scale_y});
    if ((init_bt_guide(main, win) == 84) || (init_bt_lb(main, win) == 84) ||
        (init_bt_load(main, win) == 84) || (init_bt_quit(main, win) == 84) ||
        (init_bt_settings(main, win) == 84) ||
        (init_bt_start(main, win) == 84)) {
        return 84;
    }
    return 0;
}
