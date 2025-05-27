/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** event_handler
*/

#include "wolf3d.h"

void isclicked(menu_t *menu, sfVector2f mouse, int count, wolf3d_t *w3d)
{
    sfVector2f pos = {0, 0};
    sfVector2f size = {0, 0};

    for (int i = 0; i < count; i++) {
        pos = sfRectangleShape_getPosition(menu->buttons[i].rect);
        size = sfRectangleShape_getSize(menu->buttons[i].rect);
        if (menu->buttons[i].isclickable == 1 &&
            (mouse.x >= pos.x && mouse.x <= pos.x + size.x) &&
            (mouse.y >= pos.y && mouse.y <= pos.y + size.y)) {
                sfSound_play(menu->buttons[i].click_sound);
                menu->buttons[i].func_of(w3d);
            }
    }
}

void check_buttons(wolf3d_t *w3d, sfEvent *event)
{
    sfVector2f mouse;

    if (event->type == sfEvtMouseButtonPressed &&
        event->mouseButton.button == sfMouseLeft) {
        mouse = (sfVector2f){event->mouseButton.x, event->mouseButton.y};
        isclicked(&(w3d->menus[w3d->scene]), mouse, bt_count[w3d->scene], w3d);
    }
}

static
void key_event_handler(wolf3d_t *w3d, sfEvent *event, int activate)
{
    if (event->key.code == sfKeyEscape && activate) {
        w3d->prev_scene = GAME;
        w3d->scene = PAUSE;
        return;
    }
    player_key_events(w3d->game->level.player, event, activate);
}

static
void game_event_handler(wolf3d_t *w3d, sfEvent *event)
{
    int activate = (event->type == sfEvtKeyPressed) ? sfTrue : sfFalse;
    int key_evt = (activate || event->type == sfEvtKeyReleased) ?
    sfTrue : sfFalse;

    if (key_evt)
        key_event_handler(w3d, event, activate);
}

static
void menus_event_handler(wolf3d_t *w3d, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed &&
        event->mouseButton.button == sfMouseLeft)
        check_buttons(w3d, event);
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape
        && w3d->scene == PAUSE)
        w3d->scene = GAME;
}

void event_handler(wolf3d_t *w3d, sfEvent *event)
{
    if (event->type == sfEvtMouseMoved) {
        return;
    }
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(w3d->win->sfwin);
        return;
    }
    if (w3d->scene == GAME) {
        game_event_handler(w3d, event);
        return;
    }
    menus_event_handler(w3d, event);
}
