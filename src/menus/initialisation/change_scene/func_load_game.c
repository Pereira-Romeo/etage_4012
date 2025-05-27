/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** func_load_game
*/

#include "wolf3d.h"
#include <stdio.h>
#include <string.h>


int func_load_game(wolf3d_t *w3d)
{
    char filename[MAX_FILENAME_LEN];
    size_t len;

    printf("Entrez le nom du fichier de sauvegarde (ex: savelevel.sav) : ");
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        printf("Erreur de lecture\n");
        return 0;
    }
    len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n')
        filename[len - 1] = '\0';
    if (!handle_save_load(filename, &w3d->game->level, 1)) {
        printf("Erreur de chargement du fichier '%s'\n", filename);
        return 0;
    }
    w3d->scene = GAME;
    printf("Chargement réussi, lancement du jeu...\n");
    return 1;
}
