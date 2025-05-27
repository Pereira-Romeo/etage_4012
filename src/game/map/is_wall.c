/*
** EPITECH PROJECT, 2024
** main
** File description:
** .
*/

#include "wolf3d.h"

int is_wall(size_t x, size_t y, level_t *level)
{
    if (x >= level->mapx || y >= level->mapy)
        return 0;
    return level->map[y][x] >= 2;
}
