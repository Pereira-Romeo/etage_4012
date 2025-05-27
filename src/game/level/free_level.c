/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** free_level
*/

#include "wolf3d.h"
#include <stdlib.h>

void free_level(level_t *level)
{
    free_map(level->map, level->mapy);
    level->map = NULL;
    level->mapx = 0;
    level->mapy = 0;
    free_entity(level->player);
    level->player = NULL;
    free_entity_list(level->ennemies);
    level->ennemies = NULL;
}
