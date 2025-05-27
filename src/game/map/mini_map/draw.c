/*
** EPITECH PROJECT, 2023
** Wolf3d
** File description:
** .
*/

#include "wolf3d.h"

void draw_rays(sfRenderWindow *window,
    sfVector2f player_pos, sfVector2f hit)
{
    float fx = hit.x / TILE_SIZE;
    float fy = hit.y / TILE_SIZE;
    sfVector2f coord_hit = {MINIMAP_CENTER_X + (fx - player_pos.x) * MINI_TILE,
        MINIMAP_CENTER_Y + (fy - player_pos.y) * MINI_TILE};
    sfVertex line[2] = {
        {.position = {MINIMAP_CENTER_X, MINIMAP_CENTER_Y},
        .color = sfColor_fromRGBA(0, 255, 0, 120)},
        {.position = {coord_hit.x, coord_hit.y},
        .color = sfColor_fromRGBA(0, 255, 0, 60)}
    };

    sfRenderWindow_drawPrimitives(window, line, 2, sfLines, NULL);
}

void draw_tile(sfRenderWindow *window, sfVector2f origin,
    int type_wall, minimap_t *m_map)
{
    sfRectangleShape_setPosition(m_map->tile,
        (sfVector2f){origin.x, origin.y});
    if (type_wall == 0)
        sfRectangleShape_setFillColor(m_map->tile,
            sfColor_fromRGB(226, 216, 124));
    else if (type_wall == 4 || type_wall == 3)
        sfRectangleShape_setFillColor(m_map->tile,
            sfColor_fromRGB(123, 124, 39));
    else
        sfRectangleShape_setFillColor(m_map->tile,
            sfColor_fromRGB(158, 158, 158));
    sfRenderWindow_drawRectangleShape(window, m_map->tile, NULL);
}

void draw_player(sfRenderWindow *window, entity_t *player)
{
    sfCircleShape_setRadius(player->body2d, MINI_TILE / 3.0);
    sfCircleShape_setOrigin(player->body2d,
        (sfVector2f){MINI_TILE / 3.0, MINI_TILE / 3.0});
    sfCircleShape_setPosition(player->body2d,
        (sfVector2f){MINIMAP_CENTER_X, MINIMAP_CENTER_Y});
    sfCircleShape_setFillColor(player->body2d, sfYellow);
    sfRenderWindow_drawCircleShape(window, player->body2d, NULL);
}

void draw_enemy_minimap(sfRenderWindow *window,
    entity_t *enemy, sfVector2f player_pos)
{
    sfVector2f pos = {MINIMAP_CENTER_X
        + ((enemy->move.pos.x / TILE_SIZE) - player_pos.x) * MINI_TILE,
        MINIMAP_CENTER_Y + ((enemy->move.pos.y / TILE_SIZE) - player_pos.y)
        * MINI_TILE};

    sfCircleShape_setRadius(enemy->body2d, MINI_TILE / 3);
    sfCircleShape_setOrigin(enemy->body2d,
        (sfVector2f){MINI_TILE / 3, MINI_TILE / 3});
    sfCircleShape_setPosition(enemy->body2d, pos);
    sfCircleShape_setFillColor(enemy->body2d, sfRed);
    sfRenderWindow_drawCircleShape(window, enemy->body2d, NULL);
}
