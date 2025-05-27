/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** fps_clock
*/

#include "window.h"

sfInt64 my_gettime(sfClock *clock)
{
    return sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
}
