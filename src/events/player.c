/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** player_events
*/

#include "wolf3d.h"

sfBool invert_bool(sfBool bool)
{
    if (bool)
        return sfFalse;
    return sfTrue;
}

void player_move_events(entity_t *player, sfEvent *event, int activate)
{
    if (event->key.code == sfKeyZ)
        player->move.forward = activate;
    if (event->key.code == sfKeyD)
        player->move.right = activate;
    if (event->key.code == sfKeyQ)
        player->move.left = activate * -1;
    if (event->key.code == sfKeyS)
        player->move.backward = activate * -1;
    if (event->key.code == sfKeyLShift)
        player->move.run = activate;
}

//remove returns so we can do funny combinations btw keys
void player_cam_events(entity_t *player, sfEvent *event, int activate)
{
    if (event->key.code == sfKeyRight)
        player->cam.a_yaw = activate;
    if (event->key.code == sfKeyLeft)
        player->cam.a_yaw = activate * -1;
    if (event->key.code == sfKeyUp)
        player->cam.a_pitch = activate * -1;
    if (event->key.code == sfKeyDown)
        player->cam.a_pitch = activate;
}

//change to w3d->settings->forward_key for key code recognition supporting
//custom inputs
void player_key_events(entity_t *player, sfEvent *event, int activate)
{
    player_move_events(player, event, activate);
    player_cam_events(player, event, activate);
    if (event->key.code == sfKeyE)
        player->interact = activate;
    if (event->key.code == sfKeyF)
        player->flashlight = (activate) ?
        invert_bool(player->flashlight) : player->flashlight;
    if (event->key.code == sfKeyK && activate)
        lower_entity_hp(player, 5);
    if (event->key.code == sfKeyN && activate)
        sleep(10);
    if (event->key.code == sfKeyK && activate)
        lower_entity_hp(player, 5);
}
