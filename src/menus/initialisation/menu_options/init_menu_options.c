/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_menu_options
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

static
int init_return_bt(menu_t *options, win_t *win)
{
    (void)win;
    options->buttons[RETURN_OPTIONS].pos = (sfVector2f){63.7, 44};
    options->buttons[RETURN_OPTIONS].size = (sfVector2f){115, 51};
    options->buttons[RETURN_OPTIONS].texture =
        sfTexture_createFromFile("assets/images/back_maj_text.png", NULL);
    if (!options->buttons[RETURN_OPTIONS].texture)
        return 84;
    options->buttons[RETURN_OPTIONS].rect = sfRectangleShape_create();
    if (!options->buttons[RETURN_OPTIONS].rect ||
        init_sound_click(options, RETURN_OPTIONS) == 84)
        return 84;
    options->buttons[RETURN_OPTIONS].isclickable = 1;
    options->buttons[RETURN_OPTIONS].func_of = return_func;
    return 0;
}

int init_struct_options(menu_t *options, win_t *win)
{
    options->bg_texture =
        sfTexture_createFromFile("assets/images/bg_settings4.png", NULL);
    options->bg_sprite = sfSprite_create();
    if (!options->bg_texture || !options->bg_sprite)
        return 84;
    sfSprite_setTexture(options->bg_sprite, options->bg_texture, sfTrue);
    if (init_keybord_bt(options, win) == 84 ||
        init_music(options, win) == 84 ||
        init_sfx(options, win) == 84 ||
        init_return_bt(options, win) == 84)
        return 84;
    return 0;
}
