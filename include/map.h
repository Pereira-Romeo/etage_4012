/*
** EPITECH PROJECT, 2023
** linked_list
** File description:
** bootstrap.h
*/


#ifndef MAP_H
    #define MAP_H
    #include "wolf3d.h"
    #define MINIMAP_RADIUS 100
    #define VIEW_RADIUS 4
    #define MINI_TILE (2 * (MINIMAP_RADIUS - 20) / (2 * VIEW_RADIUS + 1))
    #define MINIMAP_CENTER_X (MINIMAP_RADIUS + 5)
    #define MINIMAP_CENTER_Y (0 + MINIMAP_RADIUS + 20)
    #define NUM_MINIMAP_RAYS 1920

    #define WINDOW_WIDTH 1920
    #define WINDOW_HEIGHT 1080

    #define DEFAULT_LIGHT_RAD 800
    #define DEFAULT_LIGHT_MAX_DIST 900

    #define PI 3.1415926535
    #define FOV (PI / 3.0)
    #define NUM_RAYS 1920
    #define TILE_SIZE 64

    #define MINIMAP_SCALE 0.2
    #define MINIMAP_TILE_SIZE (TILE_SIZE * MINIMAP_SCALE)

    #define NB_WALL_TEXTURES 6

typedef struct minimap_s {
    sfCircleShape *circle;
    sfRectangleShape *tile;
    sfVector2f size_tile;
} minimap_t;

typedef struct var_find_hit_s {
    float intercept;
    float step;
    float next_x;
    float next_y;
    size_t map_x;
    size_t map_y;
    int is_vertical;
} var_find_hit_t;

typedef struct column_s {
    int i;
    int type_wall;
    float distance;
    float wall_height;
    float texture_offset;
    float cam_center;
    float col_width;
    sfVector2f dir_player;
    sfVector2f plane;
    sfVector2f ray_dir;
    sfRectangleShape *rect;
    sfVertexArray *render_3d;
    sfVertexArray *render_3d_wall;
} column_t;

typedef struct raycast_hit_s {
    float distance;
    float hit_x;
    float hit_y;
    int is_vertical;
    int type_wall;
    sfVector2i ray_up_left;
} raycast_hit_t;

typedef struct level_s level_t;
typedef struct entity_s entity_t;
typedef struct game_s game_t;

/** Free a map
 * @param map map to free
 * @param mapy map size y
 * @note if map is NULL doesn't try to free
 */
void free_map(int **map, int mapy);

/**
* check if the case is a wall
* @param x coordinate x that you want to check
* @param y coordinate y that you want to check
* @return 0 if is a wall
*/
int is_wall(size_t x, size_t y, level_t *level);

/** draw the floor and ceiling
 * @param win struct win_t
 * @param game struct game_t
 */
void draw_game_bg(win_t *win, game_t *game);

/**
 * raycast and draw the wall in 3d
 * @param window the window of the game
 * @param g struct game
 * @return 84 if is a error else 0
 */
int func_raycast(sfRenderWindow *window, game_t *g);

/**
 * gives the smallest ray between the vertical and horizontal ray
 * @param player the player
 * @param ray_angle angle of ray
 * @return struct raycast_hit_t
 */
raycast_hit_t get_small_ray(level_t *level, float ray_angle);

/**
* draw reduce map
* @param window the window of the game
* @param player the player
*/
//void draw_minimap(sfRenderWindow *window, entity_t *player, int **map);
void draw_minimap(sfRenderWindow *window, game_t *game);

void draw_player(sfRenderWindow *window, entity_t *player);
void draw_tile(sfRenderWindow *window, sfVector2f origin,
    int iswall, minimap_t *m_map);
void draw_enemy_minimap(sfRenderWindow *window,
    entity_t *enemy, sfVector2f player_pos);
//void draw_background(sfRenderWindow *window, minimap_t *m_map);
void draw_rays(sfRenderWindow *window,
    sfVector2f player_pos, sfVector2f hit);
void free_minimap(minimap_t *mini_map);
minimap_t *init_minimap(minimap_t *mini_map);

void free_column(column_t *column);
column_t *init_column(column_t *column);
void draw_ceiling(game_t *g, float wall_top);
sfColor apply_flashlight(int x, int lineHeight, float dist);
sfColor apply_light(float dist, float max_light);





//---------------------------- TILE IS ----------------------------//
/** check if a tile is a closed door from its index
 * @param level level_t struct
 * @param x index x of the tile
 * @param y index y of the tile
 * @returns sfTrue (1) if is a closed door
 * OR sfClose (0) is anything else
 */
sfBool is_door(level_t *level, int x, int y);

/** check if a tile is a closed door from its position
 * @param level level_t struct
 * @param pos position to check
 * @returns sfTrue (1) if is a closed door
 * OR sfClose (0) is anything else
 */
sfBool pos_is_door(level_t *level, sfVector2f pos);

//--------------------------- SET TILES ---------------------------//

/** set the value of a tile from its indexes
 * @param level levet_t struct
 * @param x index x of the tile
 * @param y index y of the tile
 * @param val value to use
 * @note if indexes are out of range, does nothing
 */
void set_tile(level_t *level, int x, int y, int val);

/** set the value of a tile from its position
 * @param level levet_t struct
 * @param pos position to change
 * @param val value to use
 * @note if position is out of range, does nothing
 */
void set_tile_pos(level_t *level, sfVector2f pos, int val);

#endif /* MAP_H */
