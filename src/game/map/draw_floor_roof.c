/*
** EPITECH PROJECT, 2023
** linked_list
** File description:
** bootstrap.h
*/

#include "wolf3d.h"

void draw_game_bg(win_t *win, game_t *game)
{
    sfVector2u size_w = {win->mode.width, win->mode.height};
    float mid = (size_w.y) / (2 + game->level.player->cam.pitch);
    sfColor floor_color = sfColor_fromRGBA(107, 95, 24, 80);

    sfRectangleShape_setPosition(game->floor, (sfVector2f){0, mid});
    sfRectangleShape_setSize(game->floor, (sfVector2f){size_w.x, size_w.y});
    sfRectangleShape_setFillColor(game->floor, floor_color);
    sfRenderWindow_drawRectangleShape(win->sfwin, game->floor, NULL);
}
