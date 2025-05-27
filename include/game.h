/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** game
*/

#ifndef GAME_H
    #define GAME_H
    #include "level.h"

//---------------------------- DEFINES ----------------------------//

    //Path to the roof's texture
    #define ROOF_TEXTURE NULL //"assets/images/roof.smth"
    //Path to the floor's texture
    #define FLOOR_TEXTURE NULL //"assets/images/floor.smth"
    //number of wall textures
    #define NB_WALL_TEXTURES 6

//make a free game that ask if you wanna destroy the textures
//so we don't destroy and reload the textures if we just switching levels

/** struct game
 * @param level currently loaded level
 * @param level_id id of currently loaded level
 * @param animation_tick used to manage animations
 * @param roof rectangle for the ceiling
 * @param floor rectangle for the floor
 * @param wall_textures list of textures for the walls
 * @param roof_floor_textures list of textures for roof and floor
 */
typedef struct game_s {
    minimap_t *mini_map;
    column_t *column;
    level_t level;
    int level_id;
    int animation_tick;
    sfTexture **wall_textures;
    sfRectangleShape *floor;
    sfTexture *floor_texture;
    sfImage *copy_texture[NB_WALL_TEXTURES];
    sfVector2u texture_size[NB_WALL_TEXTURES];
} game_t;

//----------------------------- Inits -----------------------------//

/** Initialize everything that is needed to play the game
 * @param game game_t struct to initialize
 * @param level_name name of the level to load, can be NULL to load next
 * @returns 0
 * OR 84 on error
 */
int setup_game(game_t *game, char *level_name);

//----------------------------- Frees -----------------------------//

/** Free a game_t struct
 * @param game game_t struct to free
 * @note game is not freed as it is supposed as non-dynamically allocated.
 * everything will be set to NULL or default values inside.
 */
void free_game(game_t *game);


//------------------------------ GAME -----------------------------//

/** run the game, does not draw anything
 * @param win win_t struct
 * @param game game_t to run
 */
void run_game(win_t *win, game_t *game);

/** draw the game in its current state, does not run anything
 * @param win win_t struct
 * @param game game_t to draw
 * @returns 0
 * OR 84 on error
 */
int draw_game(win_t *win, game_t *game);

#endif /* GAME_H */
