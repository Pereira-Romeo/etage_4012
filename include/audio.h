/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** audio
*/

#ifndef MY_AUDIO_H
    #define MY_AUDIO_H
    #include <SFML/Audio.h>

/** play a sound once
 * @param sound sound to play
 * @param vol volume to play the sound at
 */
void play_sound(sfSound *sound, float vol);

#endif /* AUDIO_H */
