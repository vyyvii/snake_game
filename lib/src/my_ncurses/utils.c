/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

void put_cursor(int x, int y)
{
    my_putstr("\033[");
    my_put_nbr(x);
    my_putstr(";");
    my_put_nbr(y);
    my_putstr("H");
}

void refresh_sreen(void)
{
    my_putstr("\033[2J");
}

void cursor_home(void)
{
    my_putstr("\033[H");
}

void reset_color(void)
{
    my_putstr("\033[0m");
}
