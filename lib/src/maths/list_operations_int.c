/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

int list_sum_int(int *list, int size_list)
{
    int sum = 0;

    for (int i = 0; i < size_list; i++)
        sum += list[i];
    return sum;
}

double list_mean_int(int *list, int size_list)
{
    return (double)list_sum_int(list, size_list) / (double)size_list;
}

double standard_deviation_int(int *list, int size_list)
{
    double mean = list_mean_int(list, size_list);
    double sum = 0;
    double diff = 0;

    for (int i = 0; i < size_list; i++) {
        diff = list[i] - mean;
        sum += diff * diff;
    }
    return (int)my_sqrt(sum / size_list);
}
