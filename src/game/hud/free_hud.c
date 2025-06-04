/*
** EPITECH PROJECT, 2025
** wolf3D_re
** File description:
** draw_hud
*/

#include "wolf3d.h"

void free_particles(hud_t *hud)
{
    for (int i = 0; i < NB_PARTICLES; i++) {
        if (hud->hp_particles[i].sprite)
            sfSprite_destroy(hud->hp_particles[i].sprite);
        if (hud->hp_particles[i].ttl)
            sfClock_destroy(hud->hp_particles[i].ttl);
    }
}

void free_hud(hud_t *hud)
{
    if (!hud)
        return;
    if (hud->hp_texture)
        sfTexture_destroy(hud->hp_texture);
    if (hud->hand_texture)
        sfTexture_destroy(hud->hand_texture);
    if (hud->hand_sprite)
        sfSprite_destroy(hud->hand_sprite);
    free_particles(hud);
}
