/*
** EPITECH PROJECT, 2025
** wolf3D_re
** File description:
** draw_hud
*/

#include "wolf3d.h"

void draw_hud(win_t *win, hud_t *hud, entity_t *player)
{
    if (HAND_HUD_TEXTURE)
        sfRenderWindow_drawSprite(win->sfwin, hud->hand_sprite, NULL);
    if (HP_HUD_TEXTURE) {
        for (int i = 0; i < NB_PARTICLES && player->hp < 20; i++)
            sfRenderWindow_drawSprite(win->sfwin,
            hud->hp_particles[i].sprite, NULL);
    }
}
