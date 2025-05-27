/*
** EPITECH PROJECT, 2025
** wolf3D_re
** File description:
** is_door
*/

#include "wolf3d.h"

sfBool is_door(level_t *level, int x, int y)
{
    if ((size_t)x >= level->mapx || (size_t)y >= level->mapy ||
    x < 0 || y < 0)
        return sfFalse;
    return level->map[y][x] == 2 || level->map[y][x] == 3;
}

sfBool pos_is_door(level_t *level, sfVector2f pos)
{
    return is_door(level, pos.x / TILE_SIZE, pos.y / TILE_SIZE);
}
