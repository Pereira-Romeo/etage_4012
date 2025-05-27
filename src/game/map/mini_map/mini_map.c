/*
** EPITECH PROJECT, 2023
** Wolf3d
** File description:
** .
*/

#include "wolf3d.h"

static
sfVector2f ray_hit(level_t *level, int i)
{
    float angle = level->player->cam.yaw
    - FOV / 2 + FOV * ((float)i / NUM_MINIMAP_RAYS);
    float dist = 0;
    sfVector2f hit = {level->player->move.pos.x, level->player->move.pos.y};
    sfVector2f dir_ray = {cosf(angle), sinf(angle)};
    size_t mx = 0;
    size_t my = 0;

    while (dist < 2) {
        hit.x += dir_ray.x * 0.05 * TILE_SIZE;
        hit.y += dir_ray.y * 0.05 * TILE_SIZE;
        mx = (size_t)(hit.x / TILE_SIZE);
        my = (size_t)(hit.y / TILE_SIZE);
        if (mx >= level->mapx || my >= level->mapy
            || level->map[my][mx] >= 2)
            break;
        dist += 0.05;
    }
    return hit;
}

void init_draw_rays(sfRenderWindow *window,
    level_t *level, sfVector2f player_pos)
{
    sfVector2f hit;

    for (int i = 0; i < NUM_MINIMAP_RAYS; i++) {
        hit = ray_hit(level, i);
        draw_rays(window, player_pos, hit);
    }
}

static
int in_background(int dx, int dy)
{
    float fx = dx - VIEW_RADIUS + 0.5;
    float fy = dy - VIEW_RADIUS + 0.5;

    return (fx * fx + fy * fy) <= (VIEW_RADIUS + 0.5) * (VIEW_RADIUS + 0.5);
}

int get_tile(size_t x, size_t y, level_t *level)
{
    if (x >= level->mapx || y >= level->mapy)
        return 0;
    return level->map[y][x];
}

void init_draw_tile(sfRenderWindow *window,
    sfVector2f player_pos, int dy, game_t *game)
{
    sfVector2f origin;
    size_t mx = 0;
    size_t my = 0;
    int type_tile = 0;

    for (int dx = -VIEW_RADIUS; dx <= VIEW_RADIUS; dx++) {
        if (!in_background(dx + VIEW_RADIUS, dy + VIEW_RADIUS))
            continue;
        mx = (size_t)(player_pos.x) + dx;
        my = (size_t)(player_pos.y) + dy;
        if (mx >= game->level.mapx || my >= game->level.mapy)
            continue;
        origin.x = MINIMAP_CENTER_X + ((mx + 0.5) - player_pos.x) * MINI_TILE;
        origin.y = MINIMAP_CENTER_Y + ((my + 0.5) - player_pos.y) * MINI_TILE;
        type_tile = get_tile(mx, my, &(game->level));
        draw_tile(window, origin, type_tile, game->mini_map);
    }
}

void init_draw_enemy(sfRenderWindow *window,
    level_t *level, sfVector2f player_pos, int e)
{
    float dx = level->ennemies[e]->move.pos.x - level->player->move.pos.x;
    float dy = level->ennemies[e]->move.pos.y - level->player->move.pos.y;
    float dist = sqrtf(dx * dx + dy * dy) / TILE_SIZE;
    float angle_to_enemy = atan2f(dy, dx);
    float rel = angle_to_enemy - level->player->cam.yaw;

    while (rel < - PI)
        rel += 2 * PI;
    while (rel > PI)
        rel -= 2 * PI;
    if (fabsf(rel) < FOV / 2 && dist < 2)
        draw_enemy_minimap(window, level->ennemies[e], player_pos);
}

void draw_minimap(sfRenderWindow *window, game_t *game)
{
    sfVector2f player_pos = {game->level.player->move.pos.x / TILE_SIZE,
        game->level.player->move.pos.y / TILE_SIZE};

    sfRenderWindow_drawCircleShape(window, game->mini_map->circle, NULL);
    for (int dy = -VIEW_RADIUS; dy <= VIEW_RADIUS; dy++)
        init_draw_tile(window, player_pos, dy, game);
    init_draw_rays(window, &(game->level), player_pos);
    draw_player(window, game->level.player);
    for (int e = 0; game->level.ennemies[e] != NULL; ++e)
        init_draw_enemy(window, &(game->level), player_pos, e);
}
