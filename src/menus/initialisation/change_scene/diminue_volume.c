/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** diminue_volume
*/

#include "wolf3d.h"
#include <unistd.h>

int diminue_volume_menu(wolf3d_t *w3d)
{
    float actual_volume = sfSound_getVolume(w3d->sounds.music_menu);

    if (actual_volume <= 10.0) {
        sfSound_setVolume(w3d->sounds.music_menu, 0.0);
        return 1;
    }
    sfSound_setVolume(w3d->sounds.music_menu, actual_volume - 10);
    return 0;
}

int diminue_volume_game(wolf3d_t *w3d)
{
    float actual_volume = sfSound_getVolume(w3d->sounds.music_game);

    if (actual_volume <= 0.0)
        return 1;
    sfSound_setVolume(w3d->sounds.music_game, actual_volume - 10);
    return 0;
}

static
int change_volume_for_all_buttons(int count, menu_t *menu, float actual_volume)
{
    for (int i = 0; i < bt_count[count]; i++) {
        if (menu->buttons[i].click_sound == NULL)
            continue;
        if (actual_volume <= 10.0) {
            sfSound_setVolume(menu->buttons[i].click_sound, 0.0);
            continue;
        }
        sfSound_setVolume(menu->buttons[i].click_sound, actual_volume - 10.0);
    }
    return 0;
}

int diminue_volume_sfx(wolf3d_t *w3d)
{
    float actual_volume =
        sfSound_getVolume(w3d->menus[MAIN].buttons[START].click_sound);

    for (int i = 0; i < NB_MENU; i++) {
        change_volume_for_all_buttons(i, &(w3d->menus[i]),
            actual_volume);
    }
    return 0;
}
