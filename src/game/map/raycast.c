/*
** EPITECH PROJECT, 2023
** linked_list
** File description:
** bootstrap.h
*/

#include "wolf3d.h"

sfColor apply_flashlight(int x, int lineHeight, float dist)
{
    sfUint8 brightness;
    sfVector2f light_center = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};
    sfVector2f wall_pos = {(float)x,
        (float)((WINDOW_HEIGHT - lineHeight) / 2 + lineHeight / 2)};
    float intensity = 0;
    float dx = wall_pos.x - light_center.x;
    float dy = wall_pos.y - light_center.y;
    float distance_screen = sqrtf(dx * dx + dy * dy);

    if (distance_screen < DEFAULT_LIGHT_RAD)
        intensity = powf(1 - (distance_screen / DEFAULT_LIGHT_RAD), 2);
    if (dist <= DEFAULT_LIGHT_MAX_DIST)
        intensity *= (dist <= DEFAULT_LIGHT_MAX_DIST)
        ? powf(1 - (dist / DEFAULT_LIGHT_MAX_DIST), 2) : 0;
    if (intensity < 0)
        intensity = 0;
    if (intensity > 1)
        intensity = 1;
    brightness = (sfUint8)(intensity * 255);
    return (sfColor){brightness, brightness, brightness, 255};
}

sfColor apply_light(float dist, float max_light)
{
    float dist_light = (dist > max_light) ? max_light : dist;
    float darkness = 1 - (dist_light / max_light);
    float rgb = (darkness > 0.4) ? 0.4 * 255 : darkness * 255;
    sfColor darkcolor = {rgb, rgb, rgb, 255};

    return darkcolor;
}

static
void add_to_column(column_t *column, raycast_hit_t *hit)
{
    column->distance = hit->distance;
    column->wall_height = (TILE_SIZE / hit->distance) * (WINDOW_HEIGHT);
    column->texture_offset = hit->is_vertical
        ? fmodf(hit->hit_y, TILE_SIZE) / TILE_SIZE
        : fmodf(hit->hit_x, TILE_SIZE) / TILE_SIZE;
    if ((hit->is_vertical && hit->ray_up_left.y) ||
    (!hit->is_vertical && hit->ray_up_left.x))
        column->texture_offset = 1 - column->texture_offset;
    column->type_wall = hit->type_wall;
}

static
void append_wall_quad(game_t *g, float wall_top,
    float wall_bot, float col_width)
{
    int wall_tex_id = g->column->type_wall - 2;
    int tex_width = g->texture_size[wall_tex_id].x;
    int tex_height = g->texture_size[wall_tex_id].y;
    float texture_offset = g->column->texture_offset * tex_width;
    sfColor darkcolor = (g->level.player->flashlight == 1)
        ? apply_flashlight(g->column->i,
            g->column->wall_height, g->column->distance)
        : apply_light(g->column->distance, 250);
    float x0 = g->column->i * col_width;
    float x1 = x0 + col_width;
    sfVertex v0 = {{x0, wall_top}, darkcolor, {texture_offset, 0}};
    sfVertex v1 = {{x1, wall_top}, darkcolor, {texture_offset, 0}};
    sfVertex v2 = {{x1, wall_bot}, darkcolor, {texture_offset, tex_height}};
    sfVertex v3 = {{x0, wall_bot}, darkcolor, {texture_offset, tex_height}};

    sfVertexArray_append(g->column->render_3d_wall, v0);
    sfVertexArray_append(g->column->render_3d_wall, v1);
    sfVertexArray_append(g->column->render_3d_wall, v2);
    sfVertexArray_append(g->column->render_3d_wall, v3);
}

void draw_wall(sfRenderWindow *window, game_t *g,
    float wall_top, float wall_bot)
{
    sfRenderStates states_wall = {0};
    int wall_tex_id = g->column->type_wall - 2;

    append_wall_quad(g, wall_top, wall_bot, g->column->col_width);
    states_wall.shader = NULL;
    states_wall.blendMode = sfBlendAlpha;
    states_wall.transform = sfTransform_Identity;
    states_wall.texture = g->wall_textures[wall_tex_id];
    sfRenderWindow_drawVertexArray(window,
        g->column->render_3d_wall, &states_wall);
    sfVertexArray_clear(g->column->render_3d_wall);
}

void do_column(sfRenderWindow *window, game_t *g, float look)
{
    float wall_bot;
    float wall_top;
    float ray_angle = g->level.player->cam.yaw
    - (FOV / 2) + (g->column->i / (float)NUM_RAYS) * FOV;
    raycast_hit_t hit = get_small_ray(&(g->level), ray_angle);

    hit.distance *= cosf(ray_angle - g->level.player->cam.yaw);
    add_to_column(g->column, &hit);
    wall_top = (WINDOW_HEIGHT - g->column->wall_height) / look;
    wall_bot = wall_top + g->column->wall_height;
    draw_ceiling(g, wall_top);
    draw_wall(window, g, wall_top, wall_bot);
}

int func_raycast(sfRenderWindow *window, game_t *g)
{
    sfRenderStates states = {0};
    float look = 2 + g->level.player->cam.pitch;

    g->column->col_width = WINDOW_WIDTH / NUM_RAYS;
    g->column->dir_player.x = cosf(g->level.player->cam.yaw);
    g->column->dir_player.y = sinf(g->level.player->cam.yaw);
    g->column->plane.x = -(g->column->dir_player.y) * tanf(FOV / 2);
    g->column->plane.y = g->column->dir_player.x * tanf(FOV / 2);
    g->column->cam_center = WINDOW_HEIGHT / look + g->level.player->cam.pitch;
    for (int i = 0; i < NUM_RAYS; i++) {
        g->column->i = i;
        do_column(window, g, look);
    }
    states.shader = NULL;
    states.blendMode = sfBlendAlpha;
    states.transform = sfTransform_Identity;
    states.texture = g->wall_textures[3];
    sfRenderWindow_drawVertexArray(window, g->column->render_3d, &states);
    sfVertexArray_clear(g->column->render_3d);
    return 0;
}
