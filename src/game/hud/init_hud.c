/*
** EPITECH PROJECT, 2025
** wolf3D_re
** File description:
** init_hud
*/

#include "wolf3d.h"
#include <time.h>

static
int init_hand_hud(win_t *win, hud_t *hud)
{
    sfVector2f pos = {win->mode.width / 2, win->mode.height - HAND_Y_SIZE};
    sfIntRect rect = {0, 0, HAND_X_SIZE, HAND_Y_SIZE};

    hud->hand_texture = sfTexture_createFromFile(HAND_HUD_TEXTURE, NULL);
    if (!(hud->hand_texture))
        return sfFalse;
    hud->hand_sprite = sfSprite_create();
    if (!(hud->hand_sprite))
        return sfFalse;
    sfSprite_setScale(hud->hand_sprite,
        (sfVector2f){HAND_X_SIZE, HAND_Y_SIZE});
    sfSprite_setPosition(hud->hand_sprite, pos);
    sfSprite_setTexture(hud->hand_sprite, hud->hand_texture, sfFalse);
    sfSprite_setTextureRect(hud->hand_sprite, rect);
    return sfTrue;
}

void reset_hp_particle(win_t *win, particle_t *particle, int stage)
{
    sfIntRect rect = sfSprite_getTextureRect(particle->sprite);
    sfVector2f pos = {(randint(0, 1)) ? win->mode.width - 500 : 0,
        win->mode.height - 400};

    particle->opacity = sfColor_fromRGBA(0xFF, 0xFF, 0xFF, 0xFF);
    particle->pos_vec.x = randint(0, 1 + stage) * ((randint(0, 1) ? -1 : 1));
    particle->pos_vec.y = randint(0, 1 + stage) * ((randint(0, 1) ? -1 : 1));
    sfClock_restart(particle->ttl);
    srand(time(NULL) * rand() * (stage + 1));
    rect.left = HP_X_SIZE * randint(0, 3);
    rect.top = HP_Y_SIZE * randint(0, 3);
    sfSprite_setPosition(particle->sprite, pos);
    sfSprite_setScale(particle->sprite, (sfVector2f){1, 1});
    sfSprite_setTextureRect(particle->sprite, rect);
}

static
int init_hp_particle(win_t *win, particle_t *particle, hud_t *hud)
{
    sfIntRect rect = {0, 0, HP_X_SIZE, HP_Y_SIZE};

    particle->sprite = sfSprite_create();
    if (!(particle->sprite))
        return sfFalse;
    sfSprite_setTexture(particle->sprite, hud->hp_texture,
        sfFalse);
    sfSprite_setTextureRect(particle->sprite, rect);
    particle->ttl = sfClock_create();
    if (!(particle->ttl))
        return sfFalse;
    reset_hp_particle(win, particle, 0);
    return sfTrue;
}

static
int init_hp_hud(win_t *win, hud_t *hud)
{
    srand(time(NULL));
    hud->hp_texture = sfTexture_createFromFile(HP_HUD_TEXTURE, NULL);
    if (!(hud->hp_texture))
        return sfFalse;
    for (int i = 0; i < NB_PARTICLES; i++) {
        if (!init_hp_particle(win, &(hud->hp_particles[i]), hud))
            return sfFalse;
    }
    return sfTrue;
}

int init_hud(win_t *win, hud_t *hud)
{
    if (HAND_HUD_TEXTURE && !(hud->hand_texture)) {
        if (!init_hand_hud(win, hud))
            return 84;
    }
    if (HP_HUD_TEXTURE && !(hud->hp_texture)) {
        if (!init_hp_hud(win, hud))
            return 84;
    }
    return sfTrue;
}
