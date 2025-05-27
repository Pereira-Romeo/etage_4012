/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** main
*/

#include "wolf3d.h"
#include <errno.h>

int main_loop(wolf3d_t *w3d)
{
    int val = 0;
    sfEvent event;

    sfSound_play(w3d->sounds.music_menu);
    while (sfRenderWindow_isOpen(w3d->win->sfwin)) {
        val = fps_limited_render(w3d);
        if (val == 84)
            break;
        if (sfRenderWindow_pollEvent(w3d->win->sfwin, &event))
            event_handler(w3d, &event);
    }
    return val;
}

int main(void)
{
    win_t window = {NULL, {1920, 1080, 32}, NULL, 0, 0};
    minimap_t mini_map = {0};
    column_t column = {0};
    game_t game = {0};
    wolf3d_t w3d = {0};

    game.mini_map = init_minimap(&mini_map);
    game.column = init_column(&column);
    game.level_id = -1;
    w3d.win = init_window(&window);
    w3d.prev_scene = MAIN;
    w3d.scene = MAIN;
    errno = 0;
    if (init_musics(&w3d) == 84)
        return 84;
    w3d.game = &game;
    if (!wolf_init_error(&w3d, init_struct_menu(&w3d)))
        main_loop(&w3d);
    free_wolf(&w3d);
    return 0;
}
