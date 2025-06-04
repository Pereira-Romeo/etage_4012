/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** main
*/

#include "wolf3d.h"
#include <errno.h>

int main_loop(wolf3d_t *w3d, int menu_val)
{
    int val = 0;
    sfEvent event;

    if (wolf_init_error(w3d, menu_val))
        val = 84;
    sfSound_play(w3d->sounds.music_menu);
    while (sfRenderWindow_isOpen(w3d->win->sfwin) && val != 84) {
        val = fps_limited_render(w3d);
        if (val == 84)
            break;
        if (sfRenderWindow_pollEvent(w3d->win->sfwin, &event))
            event_handler(w3d, &event);
    }
    free_wolf(w3d);
    return val;
}

int main(void)
{
    win_t window = {NULL, {1920, 1080, 32}, NULL, 0, 0};
    minimap_t mini_map = {0};
    column_t column = {0};
    gun_t gun = {0};
    game_t game = {0};
    wolf3d_t w3d = {0};

    if (init_musics(&w3d) == 84)
        return 84;
    w3d.win = init_window(&window);
    game.mini_map = init_minimap(&mini_map);
    game.column = init_column(&column);
    game.level_id = -1;
    game.gun = init_gun(&gun, &window);
    w3d.prev_scene = MAIN;
    w3d.scene = MAIN;
    w3d.game = &game;
    return main_loop(&w3d, init_struct_menu(&w3d));
}
