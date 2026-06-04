/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

int list_min_int(int *list, int size_list)
{
    int min = list[0];

    for (int i = 0; i < size_list; i++)
        if (list[i] < min)
            min = list[i];
    return min;
}

int list_max_int(int *list, int size_list)
{
    int max = list[0];

    for (int i = 0; i < size_list; i++)
        if (list[i] > max)
            max = list[i];
    return max;
}

double list_min_float(double *list, int size_list)
{
    int min = list[0];

    for (int i = 0; i < size_list; i++)
        if (list[i] < min)
            min = list[i];
    return min;
}

double list_max_float(double *list, int size_list)
{
    int max = list[0];

    for (int i = 0; i < size_list; i++)
        if (list[i] > max)
            max = list[i];
    return max;
}
