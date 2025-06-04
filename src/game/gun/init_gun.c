/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_gun
*/

#include "wolf3d.h"

void clock_gun(gun_t *gun)
{
    sfTime time = sfClock_getElapsedTime(gun->clock_gun);
    sfTime frame_time = sfMilliseconds(100);

    if (sfTime_asMilliseconds(time) >= sfTime_asMilliseconds(frame_time)) {
        gun->rect.left += 123;
        if (gun->rect.left == 492) {
            gun->rect.left = 0;
            gun->isanimated = 0;
        }
        sfSprite_setTextureRect(gun->sprite, gun->rect);
        sfClock_restart(gun->clock_gun);
    }
}

gun_t *init_gun(gun_t *gun, win_t *win)
{
    gun->texture =
        sfTexture_createFromFile("assets/images/gun_spritesheet.png", NULL);
    gun->sprite = sfSprite_create();
    gun->rect = (sfIntRect){0, 0, 123, 123};
    if (!gun->texture || !gun->sprite)
        return NULL;
    sfSprite_setTexture(gun->sprite, gun->texture, sfTrue);
    sfSprite_setTextureRect(gun->sprite, gun->rect);
    sfSprite_setScale(gun->sprite, (sfVector2f){3.5, 3.5});
    gun->pos =
        (sfVector2f){win->mode.width / 2 - (215.25), win->mode.height - 500};
    sfSprite_setPosition(gun->sprite, gun->pos);
    gun->clock_gun = sfClock_create();
    if (!gun->clock_gun)
        return NULL;
    gun->isanimated = 0;
    return gun;
}

void draw_gun(wolf3d_t *w3d)
{
    sfRenderWindow_drawSprite(w3d->win->sfwin, w3d->game->gun->sprite, NULL);
    if (w3d->game->gun->isanimated == 1)
        clock_gun(w3d->game->gun);
}
