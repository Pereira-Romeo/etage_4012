/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** print_level
*/

#include "wolf3d.h"

void print_map(int **map, int mapx, int mapy)
{
    if (!map) {
        printf("NULL map\n");
        return;
    }
    printf("map size: %dx%d\nmap:\n", mapx, mapy);
    for (int y = 0; y < mapy; y++) {
        if (!map[y]) {
            printf("NULL line %d\n", y);
            return;
        }
        for (int x = 0; x < mapx; x++) {
            printf("%2d ", map[y][x]);
        }
        printf("\n");
    }
    printf("\n");
}

void print_entity(entity_t *entity)
{
    ent_move_t mov;
    ent_cam_t cam;

    if (!entity) {
        printf("NULL entity\n");
        return;
    }
    mov = entity->move;
    cam = entity->cam;
    printf("entity of type: %d\n", entity->type);
    printf("\tpos: {%f, %f}:{%d, %d}\n", mov.pos.x, mov.pos.y,
    (int)mov.pos.x / TILE_SIZE, (int)mov.pos.y / TILE_SIZE);
    printf("\tmovements: {%d, %d, %d, %d, %d}, speed: %f\n",
    mov.forward, mov.backward, mov.left, mov.right, mov.run, mov.speed);
    printf("\tcam move: %d, sensitivity: %f\n", cam.a_yaw, cam.sensitivity);
    printf("\thp: %f, dmg: %f, flashlight: %d, interact: %d\n",
    entity->hp, entity->dmg, entity->flashlight, entity->interact);
}

void print_entity_list(entity_t **entities)
{
    if (!entities) {
        printf("NULL entity list\n");
        return;
    }
    for (int i = 0; entities[i]; i++) {
        print_entity(entities[i]);
        printf("\n");
    }
}

void print_level(level_t *level)
{
    printf("\nmap:\n");
    print_map(level->map, level->mapx, level->mapy);
    printf("\nplayer:\n");
    print_entity(level->player);
    printf("\nennemies:\n");
    print_entity_list(level->ennemies);
}
