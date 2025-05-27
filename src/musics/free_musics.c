/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** free_musics
*/

#include "wolf3d.h"

void free_musics(sounds_t sounds)
{
    sfSound_destroy(sounds.music_game);
    sfSound_destroy(sounds.music_menu);
    sfSoundBuffer_destroy(sounds.mg_buffer);
    sfSoundBuffer_destroy(sounds.mm_buffer);
}
