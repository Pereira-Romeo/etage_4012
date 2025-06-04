/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** init_game
*/

#include "wolf3d.h"
#include <stdlib.h>
#include <errno.h>

//list of path to get the wall's textures
const
char *wall_textures[] = {
    "assets/images/door.png",
    "assets/images/floor.png",
    "assets/images/wall.png",
    "assets/images/ceiling.png",
    "assets/images/epitech.png",
    "assets/images/finish.png",
    NULL
};

//list of names of default levels
const
char *lvl_names[] = {
    "Tek",
    NULL
};

/** setup assets for the roof or floor depending on wich you asked for
 * if shape already exists, skip this step
 * if texture already exists, skip this step
 */
static
int setup_bg(sfRectangleShape **shape, sfTexture **texture, char *path)
{
    if (!(*shape)) {
        *shape = sfRectangleShape_create();
        if (!(*shape)) {
            write(STDERR_FILENO, "setup background failure.\n", 26);
            return 84;
        }
    }
    if (!(*texture) && path) {
        *texture = sfTexture_createFromFile(path, NULL);
        if (!(*texture)) {
            write(STDERR_FILENO, "setup background failure.\n", 26);
            return 84;
        }
        sfRectangleShape_setTexture(*shape, *texture, sfTrue);
    }
    return sfTrue;
}

/** setup assets for the walls
 * if wall's texture list already exists,
 * leave the function and return success.
 */
static
int setup_walls_assets(game_t *game)
{
    if (game->wall_textures)
        return sfTrue;
    game->wall_textures = calloc(NB_WALL_TEXTURES + 1, sizeof(sfTexture *));
    if (!(game->wall_textures)) {
        perror("setup wall assets.\n");
        return 84;
    }
    for (int i = 0; wall_textures[i] && i < NB_WALL_TEXTURES; i++) {
        game->wall_textures[i] = sfTexture_createFromFile(
            wall_textures[i], NULL);
        if (!(game->wall_textures[i])) {
            perror("setup wall assets.\n");
            return 84;
        }
        game->copy_texture[i] = sfTexture_copyToImage(game->wall_textures[i]);
        if (!(game->copy_texture[i]))
            return 84;
        game->texture_size[i] = sfTexture_getSize(game->wall_textures[i]);
    }
    return sfTrue;
}

static
int setup_level_assets(win_t *win, game_t *game)
{
    if (setup_bg(&(game->floor), &(game->floor_texture), FLOOR_TEXTURE) == 84)
        return 84;
    if (setup_walls_assets(game) == 84)
        return 84;
    if (init_hud(win, &(game->hud)) == 84)
        return 84;
    return sfTrue;
}

/** setup a level, if level_name has been given try to load custom level.
 * if custom level doesn't exists, load level 1.
 * if level name is null, load next level.
 */
static
int setup_level(game_t *game, char *level_name)
{
    errno = 0;
    if (level_name) {
        if (handle_save_load(level_name, &(game->level), sfTrue))
            return sfTrue;
        if (errno != ENOENT)
            return 84;
    }
    if (game->level_id == -1)
        game->level_id = 0;
    if (!handle_save_load(lvl_names[game->level_id], &(game->level), sfTrue))
        return 84;
    if (lvl_names[game->level_id + 1])
        game->level_id++;
    return sfTrue;
}

//should play elevator sound and display loading screen
int setup_game(win_t *win, game_t *game, char *level_name)
{
    if (setup_level_assets(win, game) == 84)
        return 84;
    if (setup_level(game, level_name) != sfTrue)
        return 84;
    game->animation_tick = 0;
    return 0;
}
