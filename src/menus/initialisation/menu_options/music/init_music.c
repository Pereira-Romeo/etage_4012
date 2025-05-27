/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_music
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

static
int check_malloc(menu_t *options)
{
    if (!options->buttons[MUSIC_MAX].texture ||
        !options->buttons[MUSIC_MAX].rect ||
        !options->buttons[MUSIC_MIN].texture ||
        !options->buttons[MUSIC_MIN].rect ||
        init_sound_click(options, MUSIC_MAX) == 84 ||
        init_sound_click(options, MUSIC_MIN) == 84) {
        return 84;
        }
    return 0;
}

int init_music(menu_t *options, win_t *win)
{
    (void)win;
    options->buttons[MUSIC_MAX].pos = (sfVector2f){671.8, 370.9};
    options->buttons[MUSIC_MAX].size = (sfVector2f){91, 92};
    options->buttons[MUSIC_MAX].texture =
        sfTexture_createFromFile("assets/images/plus_text.png", NULL);
    options->buttons[MUSIC_MAX].rect = sfRectangleShape_create();
    options->buttons[MUSIC_MAX].isclickable = 1;
    options->buttons[MUSIC_MAX].func_of = augmente_volume_menu;
    options->buttons[MUSIC_MIN].pos = (sfVector2f){194.9, 375.6};
    options->buttons[MUSIC_MIN].size = (sfVector2f){107, 82};
    options->buttons[MUSIC_MIN].texture =
        sfTexture_createFromFile("assets/images/minus_text.png", NULL);
    options->buttons[MUSIC_MIN].rect = sfRectangleShape_create();
    options->buttons[MUSIC_MIN].isclickable = 1;
    options->buttons[MUSIC_MIN].func_of = diminue_volume_menu;
    return check_malloc(options);
}
