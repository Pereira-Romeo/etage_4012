/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** run_game
*/

#include "wolf3d.h"

//after moving player:
//call next_entity_act() on every ennemy to tell them whats the next move
//to find the player
//move_entity_list(game->level.ennemies);
void run_game(win_t *win, game_t *game)
{
    (void) win;
    manage_interaction(game->level.player, &(game->level));
    move_entity(game->level.player, &(game->level));
    run_hud(win, &(game->hud), game->level.player);
}
