/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_sfx
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

static
int check_malloc(menu_t *options)
{
    if (!options->buttons[SFX_MAX].texture ||
        !options->buttons[SFX_MAX].rect ||
        !options->buttons[SFX_MIN].texture ||
        !options->buttons[SFX_MIN].rect ||
        init_sound_click(options, SFX_MAX) == 84 ||
        init_sound_click(options, SFX_MIN) == 84)
        return 84;
    return 0;
}

int init_sfx(menu_t *options, win_t *win)
{
    (void)win;
    options->buttons[SFX_MAX].pos = (sfVector2f){671.8, 543.9};
    options->buttons[SFX_MAX].size = (sfVector2f){91, 92};
    options->buttons[SFX_MAX].texture =
        sfTexture_createFromFile("assets/images/plus_text.png", NULL);
    options->buttons[SFX_MAX].rect = sfRectangleShape_create();
    options->buttons[SFX_MAX].isclickable = 1;
    options->buttons[SFX_MAX].func_of = augmente_volume_sfx;
    options->buttons[SFX_MIN].pos = (sfVector2f){194.9, 550};
    options->buttons[SFX_MIN].size = (sfVector2f){107, 82};
    options->buttons[SFX_MIN].texture =
        sfTexture_createFromFile("assets/images/minus_text.png", NULL);
    options->buttons[SFX_MIN].rect = sfRectangleShape_create();
    options->buttons[SFX_MIN].isclickable = 1;
    options->buttons[SFX_MIN].func_of = diminue_volume_sfx;
    return check_malloc(options);
}
