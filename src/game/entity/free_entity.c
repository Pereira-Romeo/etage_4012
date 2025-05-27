/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** free_entity
*/

#include "wolf3d.h"
#include <stdlib.h>

void free_entity(entity_t *entity)
{
    if (!entity)
        return;
    if (entity->body2d) {
        sfCircleShape_destroy(entity->body2d);
        entity->body2d = NULL;
    }
    if (entity->sprite) {
        sfSprite_destroy(entity->sprite);
        entity->sprite = NULL;
    }
    free(entity);
}

void free_entity_list(entity_t **entities)
{
    if (!entities)
        return;
    for (int i = 0; entities[i]; i++)
        free_entity(entities[i]);
    free(entities);
}
