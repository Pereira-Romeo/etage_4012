/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** load_level
*/

#include "wolf3d.h"
#include <stdlib.h>

static
int load_map_values(FILE *sfile, level_t *level)
{
    size_t size[2] = {level->mapx, level->mapy};

    for (size_t i = 0; i < level->mapy; i++) {
        level->map[i] = calloc(size[0], sizeof(int));
        if (!(level->map[i])) {
            perror("Load map");
            return sfFalse;
        }
        if (fread(level->map[i], sizeof(int), size[0], sfile) != size[0]) {
            perror("Load map");
            return sfFalse;
        }
    }
    return sfTrue;
}

static
int load_map(FILE *sfile, level_t *level)
{
    size_t size[2] = {0, 0};

    if (fread(size, sizeof(size_t), 2, sfile) != 2) {
        perror("Load map");
        return sfFalse;
    }
    level->mapx = size[0];
    level->mapy = size[1];
    level->map = calloc(size[1], sizeof(int *));
    if (!(level->map)) {
        perror("Load map");
        return sfFalse;
    }
    return load_map_values(sfile, level);
}

static
int load_entity_values(float list[5], entity_t *entity)
{
    entity->hp = list[0];
    entity->dmg = list[1];
    entity->cam.yaw = list[2];
    entity->move.pos.x = list[3];
    entity->move.pos.y = list[4];
    return sfTrue;
}

static
int load_entity(FILE *sfile, entity_t **entity)
{
    float list[5] = {0, 0, 0, 0, 0};
    int type = 0;

    if (fread(&type, sizeof(entity_type_t), 1, sfile) != 1) {
        perror("Load entity");
        return sfFalse;
    }
    *entity = init_entity(type);
    if (!(*entity))
        return sfFalse;
    if (fread(list, sizeof(float), 5, sfile) != 5) {
        perror("Load entity");
        return sfFalse;
    }
    return load_entity_values(list, *entity);
}

static
int load_entity_list(FILE *sfile, entity_t ***entities)
{
    int nb_entities = 0;

    if (fread(&nb_entities, sizeof(int), 1, sfile) != 1) {
        perror("Load entity list");
        return sfFalse;
    }
    *entities = calloc(nb_entities + 1, sizeof(entity_t *));
    if (!(*entities)) {
        perror("Load entity list");
        return sfFalse;
    }
    for (int i = 0; i < nb_entities; i++) {
        if (!load_entity(sfile, &((*entities)[i])))
            return sfFalse;
    }
    return sfTrue;
}

int load_level(const char *name, level_t *level)
{
    FILE *sfile = fopen(name, "rb");

    if (!sfile) {
        perror("load_level");
        return sfFalse;
    }
    if (!load_map(sfile, level))
        return sfFalse;
    if (!load_entity(sfile, &(level->player)))
        return sfFalse;
    if (!load_entity_list(sfile, &(level->ennemies)))
        return sfFalse;
    fclose(sfile);
    return sfTrue;
}
