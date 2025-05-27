/*
** EPITECH PROJECT, 2025
** wold3d
** File description:
** gui
*/

#ifndef GUI_H_
    #define GUI_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    //number of buttons in main menu
    #define COUNT_BT_MAIN 6
    //number of buttons in options menu
    #define COUNT_BT_OPTIONS 7
    //number of buttons in stats menu
    #define COUNT_BT_STATS 1
    //number of buttons in pause menu
    #define COUNT_BT_PAUSE 5
    //number of buttons in help menu
    #define COUNT_BT_HELP 1
    //number of buttons in load menu
    #define COUNT_BT_LOAD 1
    //number of buttons in pause menu
    #define COUNT_BT_PAUSE 5

enum buttons_main {
    START,
    LOAD,
    SETTINGS,
    LB,
    GUIDE,
    EXIT
};

enum buttons_pause {
    RESUME,
    SAVE,
    P_SETTINGS,
    P_GUIDE,
    P_EXIT
};

enum buttons_options {
    AZERTY,
    QWERTY,
    MUSIC_MAX,
    MUSIC_MIN,
    SFX_MAX,
    SFX_MIN,
    RETURN_OPTIONS
};

enum buttons_load {
    RETURN_LOAD
};
enum buttons_help {
    RETURN_HELP
};

enum buttons_stats {
    RETURN_STATS
};

enum scenes {
    MAIN,
    PAUSE,
    S_LOAD,
    OPTIONS,
    STATS,
    HELP,
    GAME
};

#endif /* !GUI_H_ */
