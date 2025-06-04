/*
** EPITECH PROJECT, 2025
** wolf3D_re
** File description:
** animate_hud
*/

#include "wolf3d.h"
#include <stdlib.h>
#include <time.h>

//there should always be as many stage as the NB_HP_STAGES
//and the last one is -1 so it is inferior to 0
const
float hp_stages[NB_HP_STAGES] = {
    20, 15, 10, 5, -1
};

int randint(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void update_particle(win_t *win, particle_t *particle, int stage)
{
    sfVector2f pos = sfSprite_getPosition(particle->sprite);

    pos.x += particle->pos_vec.x;
    pos.y += particle->pos_vec.y;
    sfSprite_setPosition(particle->sprite, pos);
    particle->opacity.a -= 5;
    sfSprite_setColor(particle->sprite, particle->opacity);
    if (my_gettime(particle->ttl) >= PARTICLE_TTL - randint(0, 300))
        reset_hp_particle(win, particle, stage);
}

void update_hp_hud(win_t *win, hud_t *hud, float hp)
{
    int stage = 0;

    for (; hp_stages[stage] > hp; stage++);
    if (stage == 0)
        return;
    srand(time(NULL) * rand() * (stage + 1));
    for (int i = 0; i < NB_PARTICLES; i++) {
        update_particle(win, &(hud->hp_particles[i]), stage);
    }
}

static
void update_hand_pos(win_t *win, hud_t *hud)
{
    sfVector2f pos = sfSprite_getPosition(hud->hand_sprite);

    if (pos.y <= win->mode.height - HAND_Y_SIZE ||
    pos.y >= win->mode.height - 20)
        hud->hand_move_down = !(hud->hand_move_down);
    if (hud->hand_move_down) {
        pos.y += 1;
    } else {
        pos.y -= 1;
    }
    sfSprite_setPosition(hud->hand_sprite, pos);
}

//moves hand up and down
void update_hand_hud(win_t *win, hud_t *hud, entity_t *player)
{
    if (player->move.forward || player->move.left ||
    player->move.right || player->move.backward)
        update_hand_pos(win, hud);
}

void run_hud(win_t *win, hud_t *hud, entity_t *player)
{
    if (HP_HUD_TEXTURE)
        update_hp_hud(win, hud, player->hp);
    if (HAND_HUD_TEXTURE)
        update_hand_hud(win, hud, player);
}
