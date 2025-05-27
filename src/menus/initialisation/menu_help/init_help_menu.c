/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_help_menu
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int init_struct_help(menu_t *help, win_t *win)
{
    (void)win;
    help->bg_texture =
        sfTexture_createFromFile("assets/images/bg_controls.png", NULL);
    help->bg_sprite = sfSprite_create();
    if (!help->bg_texture || !help->bg_sprite)
        return 84;
    sfSprite_setTexture(help->bg_sprite, help->bg_texture, sfTrue);
    if (init_bt_return_help(help, win) == 84)
        return 84;
    return 0;
}
