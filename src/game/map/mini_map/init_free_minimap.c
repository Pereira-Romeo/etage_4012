/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** .
*/

#include "wolf3d.h"

int init_minimap_error(minimap_t *mini_map)
{
    if (!(mini_map->circle) || !(mini_map->tile)) {
        if (!(mini_map->circle))
            write(STDERR_FILENO, "Init minimap: circle failure\n", 29);
        if (!(mini_map->tile))
            write(STDERR_FILENO, "Init minimap: tile failure\n", 27);
        free_minimap(mini_map);
        return sfTrue;
    }
    return sfFalse;
}

void init_background(sfCircleShape *circle)
{
    sfCircleShape_setRadius(circle, MINIMAP_RADIUS);
    sfCircleShape_setOrigin(circle,
        (sfVector2f){MINIMAP_RADIUS, MINIMAP_RADIUS});
    sfCircleShape_setPosition(circle,
        (sfVector2f){MINIMAP_CENTER_X, MINIMAP_CENTER_Y});
    sfCircleShape_setFillColor(circle, sfColor_fromRGB(40, 40, 40));
    sfCircleShape_setOutlineColor(circle, sfWhite);
    sfCircleShape_setOutlineThickness(circle, 5);
}

minimap_t *init_minimap(minimap_t *mini_map)
{
    mini_map->circle = sfCircleShape_create();
    mini_map->tile = sfRectangleShape_create();
    if (init_minimap_error(mini_map))
        return NULL;
    init_background(mini_map->circle);
    sfRectangleShape_setSize(mini_map->tile,
        (sfVector2f){MINI_TILE, MINI_TILE});
    sfRectangleShape_setOrigin(mini_map->tile,
        (sfVector2f){MINI_TILE / 2, MINI_TILE / 2});
    return mini_map;
}

void free_minimap(minimap_t *mini_map)
{
    if (!mini_map)
        return;
    if (mini_map->tile) {
        sfRectangleShape_destroy(mini_map->tile);
        mini_map->tile = NULL;
    }
    if (mini_map->circle) {
        sfCircleShape_destroy(mini_map->circle);
        mini_map->circle = NULL;
    }
}
