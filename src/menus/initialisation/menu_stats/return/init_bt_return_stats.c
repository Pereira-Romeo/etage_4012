/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_bt_return_stats
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int init_bt_return_stats(menu_t *stats, win_t *win)
{
    (void)win;
    stats->buttons[RETURN_STATS].pos = (sfVector2f){63.7, 44};
    stats->buttons[RETURN_STATS].size = (sfVector2f){115, 51};
    stats->buttons[RETURN_STATS].texture =
        sfTexture_createFromFile("assets/images/back_maj_text.png", NULL);
    if (!stats->buttons[RETURN_STATS].texture)
        return 84;
    stats->buttons[RETURN_STATS].rect = sfRectangleShape_create();
    if (!stats->buttons[RETURN_STATS].rect ||
        init_sound_click(stats, RETURN_STATS) == 84)
        return 84;
    stats->buttons[RETURN_STATS].isclickable = 1;
    stats->buttons[RETURN_STATS].func_of = return_func;
    return 0;
}
