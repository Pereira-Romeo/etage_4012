/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** check_init_error
*/

#include "wolf3d.h"

int wolf_init_error(wolf3d_t *w3d, int menu_init)
{
    if (!(w3d->win))
        return sfTrue;
    if (menu_init == 84)
        return sfTrue;
    return sfFalse;
}
