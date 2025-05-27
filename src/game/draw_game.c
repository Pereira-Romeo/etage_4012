/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** draw_game
*/

#include "wolf3d.h"

int draw_game(win_t *win, game_t *game)
{
    draw_game_bg(win, game);
    if (func_raycast(win->sfwin, game) == 84)
        return 84;
    draw_minimap(win->sfwin, game);
    return 0;
}
