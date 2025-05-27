/*
** EPITECH PROJECT, 2025
** wolf3d
** File description:
** guide
*/

#include <stdio.h>
#include <stdlib.h>
#include "wolf3d.h"

int init_sound_click(menu_t *menu, int bt)
{
    menu->buttons[bt].click_buffer =
        sfSoundBuffer_createFromFile("assets/music/click_sound.wav");
    if (!menu->buttons[bt].click_buffer)
        return 84;
    menu->buttons[bt].click_sound = sfSound_create();
    sfSound_setBuffer(menu->buttons[bt].click_sound,
        menu->buttons[bt].click_buffer);
    sfSound_setVolume(menu->buttons[bt].click_sound, 50.0f);
    return 0;
}

int init_bt_guide(menu_t *main, win_t *win)
{
    float x_ratio = 1755.0f / 1920.0f;
    float y_ratio = 424.0f / 1080.0f;
    int w = win->mode.width;
    int h = win->mode.height;

    main->buttons[GUIDE].pos = (sfVector2f){w * x_ratio, h * y_ratio};
    main->buttons[GUIDE].size = (sfVector2f){113, 50};
    main->buttons[GUIDE].texture =
        sfTexture_createFromFile("assets/images/guide_text.png", NULL);
    main->buttons[GUIDE].rect = sfRectangleShape_create();
    if (!main->buttons[GUIDE].rect || !main->buttons[GUIDE].texture ||
        init_hover_left(main, GUIDE) == 84 ||
        init_sound_click(main, GUIDE) == 84)
        return 84;
    main->buttons[GUIDE].isclickable = 1;
    main->buttons[GUIDE].func_of = change_scene_guide;
    return 0;
}
