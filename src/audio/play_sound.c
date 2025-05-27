/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** play_sound
*/

#include "wolf3d.h"

void play_sound(sfSound *sound, float vol)
{
    sfSound_setVolume(sound, vol);
    sfSound_setLoop(sound, sfFalse);
    sfSound_play(sound);
}
