/*
** snake Game / Victor Dfc
*/

#include "snake.h"

static int **init_board(void)
{
    int **board = malloc(sizeof(int *) * (ROW));

    if (!board)
        return NULL;
    for (int i = 0; i < ROW; i++) {
        board[i] = malloc(sizeof(int) * (COLUMNS));
        if (!board[i]) {
            free_partial_table((void ***)board, i);
            return NULL;
        }
        for (int j = 0; j < COLUMNS; j++) {
            if (i == ROW - 3)
                board[i][j] = 1;
            else
                board[i][j] = 0;
        }
    }
    return board;
}

static char *board_cell_print(int cell)
{
    if (cell == 0)
        return " ";
    return "X";
}

static void box_drawing(int *board[])
{
    for (int i = 0; i < ROW; i++) {
        my_putstr((i == 0) ? "╔" : ((i == ROW - 1) ? "╚" : "║"));
        for (int j = 0; j < COLUMNS; j++)
            my_putstr((i == 0 || i == ROW - 1) ? "═" :
                board_cell_print(board[i - 1][j]));
        my_putstr((i == 0) ? "╗" : ((i == ROW - 1) ? "╝" : "║"));
        my_putstr("\n");
    }
}

static void board_drawing(int *board[])
{
    for (int i = 0; i < 5; i++) {
        cursor_home();
        refresh_sreen();
        box_drawing(board);
    }
    put_cursor(ROW + 1, 0);
}

int snake(int ac, char **av)
{
    int **board = (ac != 1) ? NULL : init_board();

    (void)av;
    if (!board)
        return FAILURE;
    my_putstr("\033[?25l");
    board_drawing(board);
    my_putstr("\033[?25h");
    for (int i = 0; i < ROW; i++)
        free(board[i]);
    free(board);
    return SUCCESS;
}