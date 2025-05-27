/*
** EPITECH PROJECT, 2025
** wolf3D_re
** File description:
** interactions
*/

#include "wolf3d.h"

static
sfBool pos_in_interaction_range(sfVector2f origin, sfVector2f pos)
{
    if (pos.x <= origin.x + INTERACTION_RANGE &&
    pos.x >= origin.x - INTERACTION_RANGE &&
    pos.y <= origin.y + INTERACTION_RANGE &&
    pos.y >= origin.y - INTERACTION_RANGE) {
        return sfTrue;
    }
    return sfFalse;
}

//return sfTrue to validate we interacted with a door
//if sfFalse is recieved, leaves possibility to interact with smth else
sfBool check_door(entity_t *entity, level_t *level)
{
    sfVector2f pos = entity->move.pos;
    sfVector2f i = {cos(entity->cam.yaw), sin(entity->cam.yaw)};

    while (pos_in_interaction_range(entity->move.pos, pos)) {
        if (pos_is_door(level, pos)) {
            set_tile_pos(level, pos, 0);
            return sfTrue;
        }
        pos.x += i.x * TILE_SIZE;
        pos.y += i.y * TILE_SIZE;
    }
    return sfFalse;
}

void manage_interaction(entity_t *entity, level_t *level)
{
    if (entity->interact) {
        check_door(entity, level);
    }
}
