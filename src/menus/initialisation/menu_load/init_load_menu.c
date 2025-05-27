/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_load_menu
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int init_struct_load(menu_t *load, win_t *win)
{
    load->bg_texture =
        sfTexture_createFromFile("assets/images/bg_load.png", NULL);
    load->bg_sprite = sfSprite_create();
    sfSprite_setTexture(load->bg_sprite, load->bg_texture, sfTrue);
    if (!load->bg_texture || !load->bg_sprite ||
        init_bt_return_load(load, win) == 84)
        return 84;
    return 0;
}
