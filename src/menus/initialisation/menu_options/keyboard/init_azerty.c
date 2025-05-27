/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_azerty
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

static
int check_malloc(menu_t *options)
{
    if (!options->buttons[AZERTY].texture ||
        !options->buttons[AZERTY].rect ||
        init_sound_click(options, AZERTY) == 84) {
        return 84;
    }
    return 0;
}

int init_azerty(menu_t *options, win_t *win)
{
    (void)win;
    options->buttons[AZERTY].pos = (sfVector2f){1236.9, 376.3};
    options->buttons[AZERTY].size = (sfVector2f){373, 101};
    options->buttons[AZERTY].texture =
        sfTexture_createFromFile("assets/images/Azerttzqsd_text.png", NULL);
    options->buttons[AZERTY].rect = sfRectangleShape_create();
    options->buttons[AZERTY].isclickable = 0;
    return check_malloc(options);
}
