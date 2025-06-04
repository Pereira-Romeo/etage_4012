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
    //path to hand spritesheet
    #define HAND_HUD_TEXTURE NULL //"assets/images/hand.smth"
    //hand sprite's width in the spritesheet
    #define HAND_X_SIZE 10 //change later
    //hand sprite's height in the spritesheet
    #define HAND_Y_SIZE 10 //change later
    //path to hp indicator spritesheet
    #define HP_HUD_TEXTURE "assets/images/blood.png"
    //hp sprite's width in the spritesheet
    #define HP_X_SIZE 428
    //hp sprite's height in the spritesheet
    #define HP_Y_SIZE 472
    //number of sprite in HP_HUD spritesheet (and number of stages)
    //first sprite should always be fully transparent
    #define NB_HP_STAGES 5
    //number of particles for the hp animation
    #define NB_PARTICLES 20
    //particle time to live in milliseconds
    #define PARTICLE_TTL 1500

/** particle struct
 * @param sprite sprite of the particle
 * @param pos_vec position vector to change pos of the particle
 * @param scale_vec scaling vector to change size of particle
 * @param ttl time to live of the particle,
 * gets reset upon reaching PARTICLE_TTL
 */
typedef struct particle_s {
    sfSprite *sprite;
    sfVector2f pos_vec;
    sfVector2f scale_vec;
    sfClock *ttl;
    sfColor opacity;
} particle_t;

/** reset a particle
 * @param win win_t
 * @param particle the particle to reset
 * @param stage health stage of entity
 */
void reset_hp_particle(win_t *win, particle_t *particle, int stage);

typedef struct gun_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    sfClock *clock_gun;
    int isanimated;
} gun_t;

/** struct hud
 * @param smth_texture texture of the item
 * @param smth_sprite sprite of the item
 * @param hand_move_down True if current motion is downwards, false if upward
 */
typedef struct hud_s {
    sfTexture *hp_texture;
    particle_t hp_particles[NB_PARTICLES];
    sfTexture *hand_texture;
    sfSprite *hand_sprite;
    int hand_move_down;
} hud_t;

/** initialize a hud struct
 * @param win win_t
 * @param hud hud_t to init
 * @returns sfTrue (1)
 * OR 84 on error
 */
int init_hud(win_t *win, hud_t *hud);

void draw_hud(win_t *win, hud_t *hud, entity_t *player);

void run_hud(win_t *win, hud_t *hud, entity_t *player);

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
    gun_t *gun;
    int level_id;
    int animation_tick;
    sfTexture **wall_textures;
    sfRectangleShape *floor;
    sfTexture *floor_texture;
    sfImage *copy_texture[NB_WALL_TEXTURES];
    sfVector2u texture_size[NB_WALL_TEXTURES];
    hud_t hud;
} game_t;

//----------------------------- Inits -----------------------------//

/** Initialize everything that is needed to play the game
 * @param game game_t struct to initialize
 * @param level_name name of the level to load, can be NULL to load next
 * @returns 0
 * OR 84 on error
 */
int setup_game(win_t *win, game_t *game, char *level_name);

//----------------------------- Frees -----------------------------//

/** Free a game_t struct
 * @param game game_t struct to free
 * @note game is not freed as it is supposed as non-dynamically allocated.
 * everything will be set to NULL or default values inside.
 */
void free_game(game_t *game);

/** Free a hud_t struct
 * @param hud hud_t struct to free
 */
void free_hud(hud_t *hud);

/** Free a gun_t struct
 * @param gun gun_t struct to free
 */
void free_gun(gun_t *gun);
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
