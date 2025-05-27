/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** free_menus
*/

#include "wolf3d.h"
#include <stdlib.h>

static
void free_buttons(button_t *bt, int count_bt)
{
    for (int i = 0; i < count_bt; i++) {
        sfRectangleShape_destroy(bt[i].rect);
        sfTexture_destroy(bt[i].texture);
        sfText_destroy(bt[i].hover);
        sfSound_destroy(bt[i].click_sound);
        sfSoundBuffer_destroy(bt[i].click_buffer);
    }
    free(bt);
}

void free_menus(wolf3d_t *w3d)
{
    for (int i = 0; i < NB_MENU; i++) {
        free_buttons(w3d->menus[i].buttons, bt_count[i]);
        sfTexture_destroy(w3d->menus[i].bg_texture);
        sfSprite_destroy(w3d->menus[i].bg_sprite);
    }
}
