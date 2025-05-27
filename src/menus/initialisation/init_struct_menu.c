/*
** EPITECH PROJECT, 2025
** wold3d
** File description:
** menu_start
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

void create_buttons(menu_t *menu, int count)
{
    for (int i = 0; i < count; i++) {
        sfRectangleShape_setTexture(menu->buttons[i].rect,
            menu->buttons[i].texture, sfTrue);
        sfRectangleShape_setPosition(menu->buttons[i].rect,
            menu->buttons[i].pos);
        sfRectangleShape_setSize(menu->buttons[i].rect, menu->buttons[i].size);
    }
}

int init_menus(wolf3d_t *w3d)
{
    if (init_struct_main(&(w3d->menus[MAIN]), w3d->win) == 84 ||
        init_struct_load(&(w3d->menus[S_LOAD]), w3d->win) == 84 ||
        init_struct_options(&(w3d->menus[OPTIONS]), w3d->win) == 84 ||
        init_struct_stats(&(w3d->menus[STATS]), w3d->win) == 84 ||
        init_struct_help(&(w3d->menus[HELP]), w3d->win) == 84 ||
        init_struct_pause(&(w3d->menus[PAUSE]), w3d->win) == 84) {
        return 84;
    }
    return 0;
}

int create_all_buttons(wolf3d_t *w3d)
{
    create_buttons(&(w3d->menus[MAIN]), COUNT_BT_MAIN);
    create_buttons(&(w3d->menus[S_LOAD]), COUNT_BT_LOAD);
    create_buttons(&(w3d->menus[OPTIONS]), COUNT_BT_OPTIONS);
    create_buttons(&(w3d->menus[HELP]), COUNT_BT_HELP);
    create_buttons(&(w3d->menus[STATS]), COUNT_BT_STATS);
    create_buttons(&(w3d->menus[PAUSE]), COUNT_BT_PAUSE);
    return 0;
}

int init_struct_menu(wolf3d_t *w3d)
{
    for (int i = 0; i < NB_MENU; i++) {
        w3d->menus[i].buttons = calloc(bt_count[i], sizeof(button_t));
        if (w3d->menus[i].buttons == NULL)
            return 84;
    }
    if (init_menus(w3d) == 84)
        return 84;
    create_all_buttons(w3d);
    return 0;
}
