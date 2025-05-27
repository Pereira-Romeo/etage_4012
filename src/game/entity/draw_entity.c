/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** draw_entity
*/

#include "wolf3d.h"

void draw_entity_mini(sfRenderWindow *window, entity_t *entity)
{
    sfVector2f position;

    position.x = entity->move.pos.x * MINIMAP_SCALE - MINIMAP_TILE_SIZE / 4;
    position.y = entity->move.pos.y * MINIMAP_SCALE - MINIMAP_TILE_SIZE / 4;
    sfCircleShape_setPosition(entity->body2d, position);
    sfRenderWindow_drawCircleShape(window, entity->body2d, NULL);
}

void draw_entity_list_mini(sfRenderWindow *window, entity_t **entities)
{
    if (!entities)
        return;
    for (int i = 0; entities[i]; i++) {
        draw_entity_mini(window, entities[i]);
    }
}
