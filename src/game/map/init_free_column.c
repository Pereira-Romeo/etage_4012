/*
** EPITECH PROJECT, 2025
** wolf3D
** File description:
** .
*/

#include "wolf3d.h"

int init_column_error(column_t *column)
{
    if (!(column->rect) || !(column->render_3d) || !(column->render_3d_wall)) {
        if (!(column->rect))
            write(STDERR_FILENO, "Init column: rect failure\n", 26);
        if (!(column->render_3d))
            write(STDERR_FILENO, "Init column: render_3d failure\n", 31);
        if (!(column->render_3d))
            write(STDERR_FILENO, "Init column: render_3d_wall failure\n", 36);
        free_column(column);
        return sfTrue;
    }
    return sfFalse;
}

column_t *init_column(column_t *column)
{
    column->rect = sfRectangleShape_create();
    column->render_3d_wall = sfVertexArray_create();
    column->render_3d = sfVertexArray_create();
    if (init_column_error(column))
        return NULL;
    sfVertexArray_setPrimitiveType(column->render_3d, sfQuads);
    sfVertexArray_setPrimitiveType(column->render_3d_wall, sfQuads);
    return column;
}

void free_column(column_t *column)
{
    if (!column)
        return;
    if (column->rect) {
        sfRectangleShape_destroy(column->rect);
        column->rect = NULL;
    }
    if (column->render_3d) {
        sfVertexArray_destroy(column->render_3d);
        column->render_3d = NULL;
    }
    if (column->render_3d_wall) {
        sfVertexArray_destroy(column->render_3d_wall);
        column->render_3d_wall = NULL;
    }
}
