/*
** EPITECH PROJECT, 2025
** wolf3D_re
** File description:
** set_tile
*/

#include "wolf3d.h"

void set_tile(level_t *level, int x, int y, int val)
{
    if ((size_t)x >= level->mapx || (size_t)y >= level->mapy ||
    x < 0 || y < 0)
        return;
    level->map[y][x] = val;
}

void set_tile_pos(level_t *level, sfVector2f pos, int val)
{
    set_tile(level, pos.x / TILE_SIZE, pos.y / TILE_SIZE, val);
}
