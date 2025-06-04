/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** entity_move
*/

#include "wolf3d.h"

void normalize_camera(entity_t *entity)
{
    while (entity->cam.yaw < 0) {
        entity->cam.yaw += 2 * PI;
    }
    while (entity->cam.yaw >= 2 * PI) {
        entity->cam.yaw -= 2 * PI;
    }
}

//unused because it kills the fps loop even tho we're out of the event handler
//reason it kills everything is unknown, even to those who got it working...
void rotate_entity_with_mouse(win_t *win, entity_t *entity)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win->sfwin);
    sfVector2i center = {win->mode.width / 2, win->mode.height / 2};

    if (mouse_pos.x != center.x) {
        sfMouse_setPositionRenderWindow(center, win->sfwin);
        entity->cam.yaw += (mouse_pos.x - center.x) * entity->cam.sensitivity;
        normalize_camera(entity);
    }
}

void rotate_entity(entity_t *entity)
{
    float sensi = entity->cam.sensitivity;
    float new_pitch = entity->cam.pitch +
    entity->cam.a_pitch * sensi;

    entity->cam.yaw += entity->cam.a_yaw * sensi;
    normalize_camera(entity);
    if (entity->cam.a_pitch == 0) {
        new_pitch += (entity->cam.pitch > 0) ? -sensi : sensi;
        if (entity->cam.pitch >= - sensi && entity->cam.pitch <= sensi)
            new_pitch = 0;
    }
    if (new_pitch > MIN_PITCH && new_pitch < MAX_PITCH)
        entity->cam.pitch = new_pitch;
}

void move_entity(entity_t *entity, level_t *level)
{
    int walk = entity->move.forward + entity->move.backward;
    int strafe = entity->move.right + entity->move.left;
    float new_x = (walk * cos(entity->cam.yaw)) +
    (strafe * sin(entity->cam.yaw) * -1);
    float new_y = (walk * sin(entity->cam.yaw)) +
    (strafe * cos(entity->cam.yaw));
    float speed = entity->move.speed + (entity->move.speed * entity->move.run
    * 3);

    speed = (walk > 0) ? speed : 1;
    rotate_entity(entity);
    if (!is_wall((int)(entity->move.pos.x + new_x * speed * 10) / TILE_SIZE,
    (int)entity->move.pos.y / TILE_SIZE, level))
        entity->move.pos.x += new_x * speed;
    if (!is_wall((int)entity->move.pos.x / TILE_SIZE,
    (int)(entity->move.pos.y + new_y * speed * 10) / TILE_SIZE, level))
        entity->move.pos.y += new_y * speed;
}

void move_entity_list(entity_t **entities, level_t *level)
{
    if (!entities)
        return;
    for (int i = 0; entities[i]; i++) {
        move_entity(entities[i], level);
    }
}
