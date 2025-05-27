/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** window
*/

#ifndef WINDOW_H
    #define WINDOW_H
    #include <SFML/Graphics.h>
    #include <SFML/System.h>

//---------------------------- DEFINES ----------------------------//

    //window's name while in game
    #define WIN_NAME1 "Reich and Roll"
    //window's name while in main menu
    #define WIN_NAME2 "etage quarante-douze - Main Menu"
    //window's name while in pause menu
    #define WIN_NAME3 "Reich and Roll - Paused"
    //window's name while in options menu
    #define WIN_NAME4 "Reich and Roll - Options"
    //window's name while in stats menu
    #define WIN_NAME5 "Reich and Roll - Player Stats"

    //fps limit
    #define WIN_FPS 60
    //drawing interval to reach fps limit
    #define DRAW_INTERVAL 1000 / WIN_FPS

/** struct win_t
 * @param sfwin sfRenderWindow
 * @param mode sfVideoMode of sfwin
 * @param fps_clock sfClock to manage fps
 * @param avg_drawing_time average time it takes for the program to
 * animate and draw everything before displaying
 * @param cur_time current amount of time spent since last fps_clock restart
 */
typedef struct win_s {
    sfRenderWindow *sfwin;
    sfVideoMode mode;
    sfClock *fps_clock;
    double avg_drawing_time;
    sfInt64 cur_time;
} win_t;

//----------------------------- Inits -----------------------------//

/** Initialize a win_t struct
 * @param win win_t struct to initialize
 * @returns pointer to win
 * OR NULL on error
 */
win_t *init_window(win_t *win);

//----------------------------- Frees -----------------------------//

/** free win_t struct
 * @param window win_t to free
 */
void free_window(win_t *window);

//----------------------------- Events ----------------------------//

/** handle sfRenderWindow resize event
 * @param win win_t struct to adapt
 * @param event detected event
 */
void window_resize_event(win_t *win, sfEvent *event);

/** handles resizing the window to new options
 * @param win win_t struct
 * @param mode newly selected mode
 * @param fullscreen boolean, sfTrue to make window fullscreen
 * @returns 0
 * OR 84 on error
 * @note if fullscreen is set, then mode's sizes are ignored
 */
int resize_window(win_t *win, sfVideoMode mode, sfBool fullscreen);

//----------------------------- Funcs -----------------------------//

//get time in milliseconds from a clock
//@param clock clock to get time from
//@returns elapsed time since last restart (or start) of the clock
sfInt64 my_gettime(sfClock *clock);
#endif /* WINDOW_H */
