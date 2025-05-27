/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** entity, used for ennemies and player
*/

#ifndef ENTITY_H
    #define ENTITY_H
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <stddef.h>

//---------------------------- DEFINES ----------------------------//

    //number of available types for an entity
    #define NB_TYPES 2
    //Path to the player's sprite
    #define ENT_PLAYER_TEXTURE NULL
    //PATH to entity of type 1
    #define ENT_TYPE1_TEXTURE NULL
    //max Pitch (when looking down)
    #define MAX_PITCH 1
    //minimum pitch (when looking up)
    #define MIN_PITCH -0.5
    //Max interaction range
    #define INTERACTION_RANGE TILE_SIZE


typedef enum entity_type_s {
    PLAYER,
    ENNEMY
} entity_type_t;

/** item_t struct for the inventory
 * @param possessed true if entity possesses this item
 * @param in_use true if player is currently using it
 * @param ammo amount of ammunition left
 * @param texture item's texture (right hand)
 * @param sprite item's sprite (right hand)
 * @param hud_texture item's hud texture (ammo)
 * @param hud_sprite item's hud sprite (ammo)
 */
typedef struct item_s {
    sfBool possessed;
    sfBool in_use;
    int ammo;
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *hud_texture;
    sfSprite *hud_sprite;
} item_t;

/** entity camera type
 * @param a_yaw 1 if rotating right, -1 to rotate left, 0 to not change
 * @param a_pitch 1 if rotatiing up, -1 to rotate down, 0 to not change
 * @param sensitivity camera's sensitivity
 * @param yaw sideways orientation
 * @param pitch vertical orientation
 */
typedef struct entity_cam_s {
    int a_yaw;
    int a_pitch;
    float sensitivity;
    float yaw;
    float pitch;
} ent_cam_t;

/** entity movement type
 * @param forward TRUE if moving forward
 * @param backward TRUE if moving backward
 * @param left TRUE if moving left
 * @param right TRUE if moving right
 * @param run TRUE is running
 * @param speed movement speed
 * @param pos position of the entity
 */
typedef struct entity_movement_s {
    int forward;
    int backward;
    int left;
    int right;
    int run;
    float speed;
    sfVector2f pos;
} ent_move_t;

/** entity_t
 * @param type type of the entity: player, ennemy, npc
 * @param move ent_move_t struct
 * @param cam ent_cam_t struct
 * @param hp health points
 * @param dmg damage dealt when attacking
 * @param flashlight sfTrue if active, sfFalse otherwise
 * @param interact sfTrue if interacting, sfFalse otherwise
 * @param body2d entity in the mini map
 * @param texture entity's texture (left hand)
 * @param sprite entity's sprite (left hand)
 */
typedef struct entity_s {
    entity_type_t type;
    ent_move_t move;
    ent_cam_t cam;
    float hp;
    float dmg;
    int flashlight;
    int interact;
    int item_in_hand;
    sfCircleShape *body2d;
    sfTexture *texture;
    sfSprite *sprite;
} entity_t;

/** entity builder struct
 * structure used to list functions to build different types of entities
 * @param type type of entity to build
 * @param build_entity function to build an entity of the corresponding type
 */
typedef struct ent_builder_s {
    int type;
    int (*build_entity)(entity_t *);
} ent_builder_t;

//----------------------------- Inits -----------------------------//

/** initialize an entity depending on its type
 * @param type type of the entity to initialize
 * @returns entity_t pointer
 * OR NULL on error
 */
entity_t *init_entity(int type);

int init_player(entity_t *player);
int init_ennemy(entity_t *ennemy);

//----------------------------- Frees -----------------------------//

/** free an entity struct
 * @param entity the entity to free
 */
void free_entity(entity_t *entity);

/** free an entity list
 * @param entities list of entities to free
 * @note list must be NULL terminated
 */
void free_entity_list(entity_t **entities);

//-------------------------- Interactions -------------------------//

/** adapt an entity's position and rotation from its move struct
 * @param entity entity to move
 * @param level level_t to use
 */
void move_entity(entity_t *entity, level_t *level);

/** call move_entity() on each entity of a list
 * @param entities list of entity_t structs to move
 * @param level level_t to use
 */
void move_entity_list(entity_t **entities, level_t *level);

/** check if entity's interact value is sfTrue and tries to interact
 * @param entity entity_t to use
 * @param level leve_t
 */
void manage_interaction(entity_t *entity, level_t *level);

//------------------------------ Draw -----------------------------//

/** draw an entity in the minimap
 * doesn't work with new minimap
 * @param window sfRenderWindow to draw in
 * @param entity entity_t struct to draw in the minimap
 */
void draw_entity_mini(sfRenderWindow *window, entity_t *entity);

/** call draw_entity_mini() on each entity of a list
 * doesn't work with new minimap
 * @param window sfRenderWindow to draw in
 * @param entities list entity_t struct to draw
 */
void draw_entity_list_mini(sfRenderWindow *window, entity_t **entities);

#endif /* ENTITY_H */
