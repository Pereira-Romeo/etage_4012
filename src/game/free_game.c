/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** free_game_struct
*/

#include "wolf3d.h"

void free_game_background(game_t *game)
{
    if (game->floor) {
        sfRectangleShape_destroy(game->floor);
        game->floor = NULL;
    }
    if (game->floor_texture) {
        sfTexture_destroy(game->floor_texture);
        game->floor_texture = NULL;
    }
}

void free_game(game_t *game)
{
    if (!game)
        return;
    free_game_background(game);
    free_level(&(game->level));
    free_minimap(game->mini_map);
    free_column(game->column);
    free_hud(&(game->hud));
    free_gun(game->gun);
    game->level_id = -1;
}
