/*
** EPITECH PROJECT, 2025
** wolf3D_re
** File description:
** entity_hp_funcs
*/

#include "entity.h"

void lower_entity_hp(entity_t *entity, float dmg)
{
    entity->hp -= dmg;
    if (entity->hp < 0)
        entity->hp = 0;
}
