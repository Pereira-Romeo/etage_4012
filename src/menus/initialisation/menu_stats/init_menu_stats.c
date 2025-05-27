/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_menu_stats
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int init_struct_stats(menu_t *stats, win_t *win)
{
    stats->bg_texture =
        sfTexture_createFromFile("assets/images/bg_lb2.png", NULL);
    stats->bg_sprite = sfSprite_create();
    if (!stats->bg_texture || !stats->bg_sprite)
        return 84;
    sfSprite_setTexture(stats->bg_sprite, stats->bg_texture, sfTrue);
    if (init_bt_return_stats(stats, win) == 84)
        return 84;
    return 0;
}
