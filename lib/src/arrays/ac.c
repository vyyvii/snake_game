/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup matrice
 * @brief Counts the number of arguments in a NULL-terminated array.
 * @param args NULL-terminated array of strings.
 * @return Number of elements before NULL.
 * @note Complexity: O(n)
 * @note Part of UtilsLib by Victor Defauchy.
 */
int nb_args(char **args)
{
    int nb_args = 0;

    if (!args)
        return FALSE;
    while (args[nb_args])
        nb_args++;
    return nb_args;
}
