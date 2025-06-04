/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** Render_handling
*/

#include "wolf3d.h"

void select_texture(button_t *bt, sfVector2i mouse, win_t *win)
{
    sfVector2f pos = {0, 0};
    sfVector2f size = {0, 0};
    sfBool isinside;

    pos = sfRectangleShape_getPosition(bt->rect);
    size = sfRectangleShape_getSize(bt->rect);
    isinside = (mouse.x >= pos.x && mouse.x <= pos.x + size.x &&
        mouse.y >= pos.y && mouse.y <= pos.y + size.y);
    if (isinside && bt->hover != NULL)
        sfRenderWindow_drawText(win->sfwin, bt->hover, NULL);
}

int display_scene(menu_t *menu, win_t *win, int count)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win->sfwin);

    sfRenderWindow_drawSprite(win->sfwin, menu->bg_sprite, NULL);
    for (int i = 0; i < count; i++) {
        select_texture(&(menu->buttons[i]), mouse, win);
        sfRenderWindow_drawRectangleShape(win->sfwin, menu->buttons[i].rect,
        NULL);
    }
    return 0;
}

int draw_scene(wolf3d_t *w3d)
{
    if (w3d->scene == GAME) {
        run_game(w3d->win, w3d->game);
        if (draw_game(w3d->win, w3d->game) == 84)
            return 84;
        draw_gun(w3d);
        w3d->game->animation_tick++;
    } else {
        display_scene(&(w3d->menus[w3d->scene]),
        w3d->win, bt_count[w3d->scene]);
    }
    return 0;
}

int fps_limited_render(wolf3d_t *w3d)
{
    win_t *window = w3d->win;
    int val = 0;

    window->cur_time = my_gettime(window->fps_clock);
    if (window->cur_time >= DRAW_INTERVAL - window->avg_drawing_time) {
        sfRenderWindow_clear(window->sfwin, sfBlack);
        sfClock_restart(window->fps_clock);
        val = draw_scene(w3d);
        if (val != 0)
            return val;
        window->avg_drawing_time = (window->avg_drawing_time * 0.7 +
        my_gettime(window->fps_clock) * 1.3) / 2.0;
        sfRenderWindow_display(window->sfwin);
    }
    return 0;
}
