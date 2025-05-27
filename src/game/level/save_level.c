/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** save_map
*/

#include "wolf3d.h"
#include <string.h>
#include <fcntl.h>

/** save a map and its size to a file
 * @param sfile save file
 * @param level level where to find the map
 * @returns sfTrue (1)
 * OR sfFalse (0) on error
 */
static
int save_map(FILE *sfile, level_t *level)
{
    size_t size[2] = {level->mapx, level->mapy};

    if (fwrite(size, sizeof(size_t), 2, sfile) != 2) {
        perror("Save map");
        return sfFalse;
    }
    for (size_t i = 0; i < level->mapy; i++) {
        if (fwrite(level->map[i], sizeof(int), size[0], sfile) != size[0]) {
            perror("Save map");
            return sfFalse;
        }
    }
    return sfTrue;
}

/** save a player to a file
 * @param sfile save file
 * @param player entity struct to save
 * @returns sfTrue (1)
 * OR sfFalse (0) on error
 * @note saving a player only writes the type, hp, dmg, rotation, pos
 * and inventory in the order listed
 * @note player doesn't have an inventory yet so we ain't savin it
 */
static
int save_entity(FILE *sfile, entity_t *entity)
{
    float list[5] = {entity->hp, entity->dmg, entity->cam.yaw,
    entity->move.pos.x, entity->move.pos.y};

    if (fwrite(&(entity->type), sizeof(entity_type_t), 1, sfile) != 1) {
        perror("Save entity");
        return sfFalse;
    }
    if (fwrite(list, sizeof(float), 5, sfile) != 5) {
        perror("Save entity");
        return sfFalse;
    }
    return sfTrue;
}

/** save a list of entities to a file
 * @param sfile save file
 * @param list list of entities
 * @returns sfTrue (1)
 * OR sfFalse (0) on error
 * @note take a look at save_entity()
 */
static
int save_entity_list(FILE *sfile, entity_t **list)
{
    int nb_ennemies = 0;

    while (list[nb_ennemies])
        nb_ennemies++;
    if (fwrite(&nb_ennemies, sizeof(int), 1, sfile) != 1) {
        perror("Save entity list");
        return sfFalse;
    }
    for (int i = 0; list[i]; i++) {
        if (!save_entity(sfile, list[i]))
            return 1;
    }
    return sfTrue;
}

int save_level(const char *name, level_t *level)
{
    FILE *sfile = fopen(name, "wb");

    if (!sfile) {
        perror("L89;Save level");
        return sfFalse;
    }
    if (!save_map(sfile, level))
        return sfFalse;
    if (!save_entity(sfile, level->player))
        return sfFalse;
    if (!save_entity_list(sfile, level->ennemies))
        return sfFalse;
    fclose(sfile);
    return sfTrue;
}

int handle_save_load(const char *name, level_t *level, int load)
{
    char buffer[256];

    if (strlen(name) > MAX_SAVE_NAME_LEN) {
        write(STDERR_FILENO, "Save name too long.\n", 20);
        return sfFalse;
    }
    strcpy(buffer, SAVE_PATH);
    strcat(buffer, name);
    if (load) {
        free_level(level);
        if (!load_level(buffer, level))
            return sfFalse;
    } else {
        if (!save_level(buffer, level))
            return sfFalse;
    }
    return sfTrue;
}
