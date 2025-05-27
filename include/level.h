/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** levels
*/

#ifndef LEVELS_H
    #define LEVELS_H
    #include <SFML/Graphics.h>
    #include "map.h"
    #include "entity.h"

//---------------------------- DEFINES ----------------------------//

    //save path
    #define SAVE_PATH "saves/"
    //length of the save path name
    #define SP_LEN 6
    //the save file name cannot be bigger than this
    #define MAX_SAVE_NAME_LEN 256 - 1 - SP_LEN

/** level struct
 * @param map int **
 * @param mapx x size of the map
 * @param mapy y size of the map
 * @param player entity_t for the player
 * @param ennemies list of entity_t for the ennemies
 */
typedef struct level_s {
    int **map;
    size_t mapx;
    size_t mapy;
    entity_t *player;
    entity_t **ennemies;
} level_t;

//----------------------------- SAVES -----------------------------//

/** save a level into a file "name"
 * @param name complete path to the save file
 * @param level level struct to save
 * @returns 0
 * OR 1 on error
 */
int save_level(const char *name, level_t *level);

/** load a level from a file "name"
 * @param name complete path to the save file
 * @param level level struct to fill
 * @returns sfTrue (1)
 * OR sfFalse (0) on error
 * @note level should be emptied with free_level() first,
 * load_level() does not do it and simply overrides everything
 */
int load_level(const char *name, level_t *level);

/** handles the saving or loading process
 * @param name name of the save file, max length is 249 char
 * @param level level struct to save or free and load into
 * @param load True if loading a level, anythin else to save a level
 * @returns sfTrue (1)
 * OR sfFalse (0) on error
 */
int handle_save_load(const char *name, level_t *level, int load);

//------------------------------ FREE -----------------------------//

/** free a level struct
 * @param level level struct to empty
 * @note level is not freed as it is supposed as non-dynamically allocated.
 * everything will be set to NULL inside level.
 */
void free_level(level_t *level);

/** print everything inside level
 * @param level level to print
 */
void print_level(level_t *level);

#endif /* LEVELS_H */
