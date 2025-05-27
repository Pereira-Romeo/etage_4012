/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** .
*/

#include "wolf3d.h"

static
void get_ceiling_tex(game_t *g, sfVector2f pos_world, int *tex_x, int *tex_y)
{
    *tex_x = ((int)(pos_world.x * g->texture_size[3].x / TILE_SIZE))
    % g->texture_size[3].x;
    *tex_y = ((int)(pos_world.y * g->texture_size[3].y / TILE_SIZE))
    % g->texture_size[3].y;
    if (*tex_x < 0)
        *tex_x += g->texture_size[3].x;
    if (*tex_y < 0)
        *tex_y += g->texture_size[3].y;
}

void append_ceiling_quad(game_t *g, int y,
    sfVector2i tex_offset, sfColor color)
{
    float x0 = g->column->i * g->column->col_width;
    float x1 = x0 + g->column->col_width;
    float y0 = y;
    float y1 = y + 2;
    sfVertex v0 = {{x0, y0}, color, {tex_offset.x, tex_offset.y}};
    sfVertex v1 = {{x1, y0}, color, {tex_offset.x + g->column->col_width,
        tex_offset.y}};
    sfVertex v2 = {{x1, y1}, color, {tex_offset.x + g->column->col_width,
        tex_offset.y + 2}};
    sfVertex v3 = {{x0, y1}, color, {tex_offset.x, tex_offset.y + 2}};

    sfVertexArray_append(g->column->render_3d, v0);
    sfVertexArray_append(g->column->render_3d, v1);
    sfVertexArray_append(g->column->render_3d, v2);
    sfVertexArray_append(g->column->render_3d, v3);
}

void get_color(game_t *g, sfVector2f pos_world, sfVector2i tex_offset, int y)
{
    sfColor color = sfImage_getPixel(g->copy_texture[3],
        tex_offset.x, tex_offset.y);
    float dx = pos_world.x - g->level.player->move.pos.x;
    float dy = pos_world.y - g->level.player->move.pos.y;
    float dist = sqrtf(dx * dx + dy * dy);
    float intensity = 1 - (dist / 2);

    if (g->level.player->flashlight == 1)
        color = apply_flashlight(g->column->i, y, dist);
    else {
        if (intensity < 0)
            intensity = 0;
        if (intensity > 1)
            intensity = 1;
        intensity = powf(intensity, 2);
        color.r *= intensity;
        color.g *= intensity;
        color.b *= intensity;
    }
    append_ceiling_quad(g, y, tex_offset, color);
}

static
void append_ceiling(game_t *g, float wall_top)
{
    int p;
    float row_dist;
    sfVector2f pos_world;
    sfVector2i tex_offset;

    for (int y = 0; y < (int)wall_top; y += 2) {
        p = y - g->column->cam_center;
        if (p == 0)
            continue;
        row_dist = (TILE_SIZE * g->column->cam_center) / - p;
        pos_world.x = g->level.player->move.pos.x
        + g->column->ray_dir.x * row_dist;
        pos_world.y = g->level.player->move.pos.y
        + g->column->ray_dir.y * row_dist;
        get_ceiling_tex(g, pos_world, &tex_offset.x, &tex_offset.y);
        get_color(g, pos_world, tex_offset, y);
    }
}

void draw_ceiling(game_t *g, float wall_top)
{
    float cam_x = 2 * g->column->i / (float)WINDOW_WIDTH - 1;

    g->column->ray_dir.x = g->column->dir_player.x
    + g->column->plane.x * cam_x;
    g->column->ray_dir.y = g->column->dir_player.y
    + g->column->plane.y * cam_x;
    append_ceiling(g, wall_top);
}
