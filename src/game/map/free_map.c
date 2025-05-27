/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** free_map
*/

#include "wolf3d.h"
#include <stdlib.h>

void free_map(int **map, int mapy)
{
    if (!map)
        return;
    for (int y = 0; y < mapy; y++)
        free(map[y]);
    free(map);
}
