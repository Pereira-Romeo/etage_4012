/*
** EPITECH PROJECT, 2023
** linked_list
** File description:
** bootstrap.h
*/

#include "wolf3d.h"

static
float calculate_distance(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    return sqrtf(dx * dx + dy * dy);
}

static
void init_find_hit(var_find_hit_t *vfh, entity_t *player,
    float ray_angle, sfVector2i ray_up_left)
{
    if (vfh->is_vertical) {
        vfh->intercept = floorf(player->move.pos.x / TILE_SIZE) * TILE_SIZE;
        if (!ray_up_left.y)
            vfh->intercept += TILE_SIZE;
        vfh->next_x = vfh->intercept;
        vfh->next_y = player->move.pos.y
        + (vfh->intercept - player->move.pos.x) * tanf(ray_angle);
        vfh->step = TILE_SIZE * (ray_up_left.y ? -1 : 1);
    } else {
        vfh->intercept = floorf(player->move.pos.y / TILE_SIZE) * TILE_SIZE;
        if (!ray_up_left.x)
            vfh->intercept += TILE_SIZE;
        vfh->next_y = vfh->intercept;
        vfh->next_x = player->move.pos.x
        + (vfh->intercept - player->move.pos.y) / tanf(ray_angle);
        vfh->step = TILE_SIZE * (ray_up_left.x ? -1 : 1);
    }
}

static
void add_hit(raycast_hit_t *hit,
    var_find_hit_t *vfh, level_t *level, int is_vertical)
{
    hit->hit_x = vfh->next_x;
    hit->hit_y = vfh->next_y;
    if (vfh->map_x < level->mapx && vfh->map_y < level->mapy)
        hit->type_wall = level->map[vfh->map_y][vfh->map_x];
    hit->distance = calculate_distance(level->player->move.pos.x,
        level->player->move.pos.y, vfh->next_x, vfh->next_y);
    hit->is_vertical = is_vertical;
}

static
void get_coor_map(var_find_hit_t *vfh, sfVector2i ray_up_left)
{
    if (vfh->is_vertical) {
        if (ray_up_left.y)
            vfh->map_x = (vfh->next_x - 1) / TILE_SIZE;
        else
            vfh->map_x = vfh->next_x / TILE_SIZE;
        vfh->map_y = vfh->next_y / TILE_SIZE;
    } else {
        vfh->map_x = vfh->next_x / TILE_SIZE;
        if (ray_up_left.x)
            vfh->map_y = (vfh->next_y - 1) / TILE_SIZE;
        else
            vfh->map_y = vfh->next_y / TILE_SIZE;
    }
}

static
raycast_hit_t find_hit(level_t *level, float ray_angle,
    sfVector2i ray_up_left, int is_vertical)
{
    raycast_hit_t hit = {0};
    var_find_hit_t vfh = {0, 0, 0, 0, 0, 0, is_vertical};

    init_find_hit(&vfh, level->player, ray_angle, ray_up_left);
    while (sfTrue) {
        get_coor_map(&vfh, ray_up_left);
        if (vfh.map_x >= level->mapx || vfh.map_y >= level->mapy
            || level->map[vfh.map_y][vfh.map_x] >= 2) {
            add_hit(&hit, &vfh, level, is_vertical);
            break;
        }
        vfh.next_x += is_vertical ? vfh.step : vfh.step / tanf(ray_angle);
        vfh.next_y += is_vertical ? vfh.step * tanf(ray_angle) : vfh.step;
    }
    hit.ray_up_left = ray_up_left;
    return hit;
}

raycast_hit_t get_small_ray(level_t *level, float ray_angle)
{
    sfVector2i ray_up_left = {sinf(ray_angle) < 0, cosf(ray_angle) < 0};
    raycast_hit_t vertical_hit = find_hit(level, ray_angle, ray_up_left, 1);
    raycast_hit_t horizontal_hit = find_hit(level, ray_angle, ray_up_left, 0);

    return (vertical_hit.distance < horizontal_hit.distance)
    ? vertical_hit : horizontal_hit;
}
