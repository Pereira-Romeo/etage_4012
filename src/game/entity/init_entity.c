/*
** EPITECH PROJECT, 2023
** wolf3d
** File description:
** .
*/

#include "wolf3d.h"
#include <stdlib.h>

const
ent_builder_t builders[] = {
    {PLAYER, &init_player},
    {ENNEMY, &init_ennemy},
    {-1, NULL}
};

int init_player(entity_t *player)
{
    player->body2d = sfCircleShape_create();
    if (player->body2d == NULL)
        return 84;
    sfCircleShape_setFillColor(player->body2d, sfYellow);
    player->cam = (ent_cam_t){0, 0, 0.07, 0.0, 0.0};
    player->move = (ent_move_t){0, 0, 0, 0, 0, 1, {100, 100}};
    player->hp = 20;
    player->dmg = 20;
    player->interact = sfFalse;
    player->flashlight = sfFalse;
    player->item_in_hand = 0;
    return 0;
}

int init_ennemy(entity_t *ennemy)
{
    ennemy->body2d = sfCircleShape_create();
    if (ennemy->body2d == NULL)
        return 84;
    sfCircleShape_setFillColor(ennemy->body2d, sfRed);
    ennemy->cam = (ent_cam_t){0, 0, 0.07, 0.0, 0.0};
    ennemy->move = (ent_move_t){0, 0, 0, 0, 0, 1, {100, 100}};
    ennemy->hp = 20;
    ennemy->dmg = 20;
    ennemy->interact = sfFalse;
    ennemy->flashlight = sfFalse;
    ennemy->item_in_hand = -1;
    return 0;
}

//should be responsible of loading the correct sprites
entity_t *init_entity(int type)
{
    entity_t *entity = calloc(1, sizeof(entity_t));

    if (!entity) {
        perror("init_entity");
        return NULL;
    }
    entity->type = type % NB_TYPES;
    if (builders[type % NB_TYPES].build_entity(entity) == 84) {
        free_entity(entity);
        return NULL;
    }
    sfCircleShape_setRadius(entity->body2d, MINIMAP_TILE_SIZE / 4);
    return entity;
}
