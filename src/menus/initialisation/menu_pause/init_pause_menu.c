/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_pause_menu
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int init_struct_pause(menu_t *pause, win_t *win)
{
    pause->bg_texture =
        sfTexture_createFromFile("assets/images/bg2.jpg", NULL);
    pause->bg_sprite = sfSprite_create();
    if (!pause->bg_sprite || !pause->bg_texture) {
        return 84;
    }
    sfSprite_setTexture(pause->bg_sprite, pause->bg_texture, sfTrue);
    if (init_bt_resume(pause, win) == 84 || init_bt_save(pause, win) == 84 ||
        init_bt_p_settings(pause, win) == 84 ||
        init_bt_p_guide(pause, win) == 84 || init_bt_p_exit(pause, win) == 84)
        return 84;
    return 0;
}
