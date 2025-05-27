/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_keyboard
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int init_keybord_bt(menu_t *options, win_t *win)
{
    if (init_azerty(options, win) == 84 || init_qwerty(options, win) == 84)
        return 84;
    return 0;
}
