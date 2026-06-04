/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

double list_sum_float(double *list, int size_list)
{
    double sum = 0.0;

    for (int i = 0; i < size_list; i++)
        sum += list[i];
    return sum;
}

double list_mean_float(double *list, int size_list)
{
    return (double)list_sum_float(list, size_list) / (double)size_list;
}

double standard_deviation_float(double *list, int size_list)
{
    double mean = list_mean_float(list, size_list);
    double sum = 0;
    double diff = 0;

    for (int i = 0; i < size_list; i++) {
        diff = list[i] - mean;
        sum += diff * diff;
    }
    return (int)my_sqrt(sum / size_list);
}
