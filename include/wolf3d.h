/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** wolf3d
*/

#ifndef WOLF3D_H
    #define WOLF3D_H
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <math.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include "window.h"
    #include "enum.h"
    #include "game.h"
    #include "audio.h"

//---------------------------- DEFINES ----------------------------//

    //number of menus
    #define NB_MENU 6
    //path to menu background
    #define MENU_BG "assets/images/backrooms_bg.jpg"

    #define MAX_FILENAME_LEN 256

/** random int generator limited to desired range
 * @param min minimum number (included in the range)
 * @param max maximum number (included in the range)
 */
int randint(int min, int max);

/** struct option
 * @param buttons list of buttons
 * @param music music to play in this menu
 * @param volume_music volume of the music
 * @param volume_sfx volume of sound effects
 */
typedef struct options_s {
    struct button_s *buttons;
    sfMusic *music;
    int volume_music;
    int volume_sfx;
} options_t;

/** struct menu
 * @param buttons list of buttons
 * @param options options menu ?
 * @param stats stats menu ?
 * @param bg_texture texture for the background
 * @param bg_sprite sprite for the background
 * @param sound sound for clicking the buttons ?
 * @param status idk ?
 */
typedef struct menu_s {
    struct button_s *buttons;
    sfTexture *bg_texture;
    sfSprite *bg_sprite;
    int status;
} menu_t;

/** struct sounds
 * @param mm_buffer idk ?
 * @param music_menu idk ?
 * @param mg_buffer idk ?
 * @param music_game idk ?
 */
typedef struct sounds_s {
    sfSoundBuffer *mm_buffer;
    sfSound *music_menu;
    sfSoundBuffer *mg_buffer;
    sfSound *music_game;
} sounds_t;

//wtf ?
// typedef struct settings_s {
//     sounds_t *sounds;
//     int keys[5];
// } settings_t;

/** struct wolf3d
 * @param win window_t struct
 * @param menus list of menus (dark magic)
 * @param game game_t struct
 * @param sounds sounds_t struct
 * @param prev_scene previous scene index ?
 * @param scene index of currently active scene
 */
typedef struct wolf3d_s {
    win_t *win;
    menu_t menus[NB_MENU];
    game_t *game;
    sounds_t sounds;
    options_t *options;
    int prev_scene;
    int scene;
} wolf3d_t;

/** free a wolf3d_t struct
 * @param w3d wolf3d_t struct to free
 */
void free_wolf(wolf3d_t *w3d);

// ------------------- BUTTON -----------

/** struct buttons
 * @param rect button hitbox ?
 * @param texture button texture
 * @param pos button position
 * @param size size of the button
 * @param isclickable why do you need that ?
 * @param func_of associated func when clicking the button
 */
typedef struct button_s {
    sfRectangleShape *rect;
    sfTexture *texture;
    sfText *hover;
    sfVector2f pos;
    sfVector2f size;
    int isclickable;
    int ishovered;
    int (*func_of)(wolf3d_t *w3d);
    sfSound *click_sound;
    sfSoundBuffer *click_buffer;
} button_t;

//list of the button count for each menu
extern const int bt_count[];


/** free a wolf3d_t struct
 * @param w3d wolf3d struct
 * @returns sfFalse (0) if no error found
 * sfTrue (1) if an error was found
 */
int wolf_init_error(wolf3d_t *w3d, int menu_init);

//----------------------------- Events ----------------------------//

/** event handler
 * @param game game struct
 * @param event event to handle
 */
void event_handler(wolf3d_t *w3d, sfEvent *event);

/** manage player inputs
 * @param player entity_t
 * @param event sfEvent
 * @param activate sfTrue if key is pressed, sfFalse if Released
 */
void player_key_events(entity_t *player, sfEvent *event, int activate);


//renders the needed scene
int draw_scene(wolf3d_t *w3d);


/** renders needed scene only if necessary
 * @param game game_t
 * @returns 0
 * OR 84 on error
 */
int fps_limited_render(wolf3d_t *w3d);

// ---------------- MENUS --------------------------------------
int init_struct_menu(wolf3d_t *w3d);
int return_scene_main(wolf3d_t *w3d);
int exit_window(wolf3d_t *w3d);
int change_scene_load(wolf3d_t *w3d);
int change_scene_guide(wolf3d_t *w3d);
int change_scene_stats(wolf3d_t *w3d);
int change_scene_options(wolf3d_t *w3d);
int change_scene_game(wolf3d_t *w3d);
int change_scene_pause(wolf3d_t *w3d);
int return_func(wolf3d_t *w3d);

// init menus
int init_struct_options(menu_t *options, win_t *win);
int init_struct_main(menu_t *main, win_t *win);
int init_struct_stats(menu_t *stats, win_t *win);
int init_struct_load(menu_t *load, win_t *win);
int init_bt_return_help(menu_t *help, win_t *win);
int init_struct_pause(menu_t *pause, win_t *win);
int init_struct_help(menu_t *help, win_t *win);

// MAIN MENU
int init_bt_guide(menu_t *main, win_t *win);
int init_bt_lb(menu_t *main, win_t *win);
int init_bt_load(menu_t *main, win_t *win);
int init_bt_quit(menu_t *main, win_t *win);
int init_bt_settings(menu_t *main, win_t *win);
int init_bt_start(menu_t *main, win_t *win);

// PAUSE MENU
int init_bt_save(menu_t *pause, win_t *win);
int init_bt_resume(menu_t *pause, win_t *win);
int init_bt_p_settings(menu_t *pause, win_t *win);
int init_bt_p_guide(menu_t *pause, win_t *win);
int init_bt_p_exit(menu_t *pause, win_t *win);

// OPTIONS MENU
// keyboard
int init_keybord_bt(menu_t *options, win_t *win);
int init_azerty(menu_t *options, win_t *win);
int init_qwerty(menu_t *options, win_t *win);

// music
int init_music(menu_t *options, win_t *win);

// sfx
int init_sfx(menu_t *options, win_t *win);

// LOAD MENU
int init_bt_return_load(menu_t *load, win_t *win);

// HELP MENU
int init_bt_return_help(menu_t *help, win_t *win);
int init_bt_info(menu_t *help, win_t *win);

// STATS MENU
int init_bt_return_stats(menu_t *stats, win_t *win);

// MUSICS
int init_musics(wolf3d_t *w3d);
int augmente_volume_menu(wolf3d_t *w3d);
int diminue_volume_menu(wolf3d_t *w3d);
int augmente_volume_game(wolf3d_t *w3d);
int diminue_volume_game(wolf3d_t *w3d);

// free
void free_menus(wolf3d_t *w3d);

/** display an error in a new window
 * @param win win_t struct
 * @param err error text to display, cannot be NULL
 * @param val value to return, if value is 84, close the game.
 * @returns val
 * @note if something goes wrong in this function,
 * the window of the wolf will be closed to initiate shutdown of the game.
 * @note new lines have to be set manually, roughly 40 characters can fit
 * per line and the window can have 10 lines
 */
int display_error(win_t *win, char *err, int val);


int init_hover_left(menu_t *menu, int bt);
int init_hover_right(menu_t *main, int bt);
int init_sound_click(menu_t *menu, int bt);
int augmente_volume_sfx(wolf3d_t *w3d);
int diminue_volume_sfx(wolf3d_t *w3d);
int save_game_func(wolf3d_t *w3d);
int func_load_game(wolf3d_t *w3d);
void free_musics(sounds_t sounds);
gun_t *init_gun(gun_t *gun, win_t *win);
void clock_gun(gun_t *gun);
void draw_gun(wolf3d_t *w3d);
#endif /* WOLF3D_H */
