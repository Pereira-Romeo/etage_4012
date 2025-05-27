/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** init_musics
*/

#include "wolf3d.h"
#include <unistd.h>

int init_musics(wolf3d_t *w3d)
{
    w3d->sounds.mm_buffer =
        sfSoundBuffer_createFromFile("assets/music/loop_music_menu.ogg");
    w3d->sounds.music_menu = sfSound_create();
    if (!w3d->sounds.mm_buffer || !w3d->sounds.music_menu)
        return 84;
    sfSound_setBuffer(w3d->sounds.music_menu, w3d->sounds.mm_buffer);
    sfSound_setLoop(w3d->sounds.music_menu, sfTrue);
    sfSound_setVolume(w3d->sounds.music_menu, 50.0f);
    w3d->sounds.mg_buffer =
        sfSoundBuffer_createFromFile("assets/music/music.ogg");
    w3d->sounds.music_game = sfSound_create();
    if (!w3d->sounds.mg_buffer || !w3d->sounds.music_game)
        return 84;
    sfSound_setBuffer(w3d->sounds.music_game, w3d->sounds.mg_buffer);
    sfSound_setLoop(w3d->sounds.music_game, sfTrue);
    sfSound_setVolume(w3d->sounds.music_game, 50.0f);
    return 0;
}
