/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** free_gun
*/

#include "wolf3d.h"

void free_gun(gun_t *gun)
{
    sfSprite_destroy(gun->sprite);
    sfTexture_destroy(gun->texture);
    sfClock_destroy(gun->clock_gun);
}
