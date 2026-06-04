/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup matrice
 * @brief Counts the number of lines based on NEW_LINE.
 * @param str Source string.
 * @return Number of lines (= number of NEW_LINE + 1).
 * @note Complexity: O(n)
 * @note Part of UtilsLib by Victor Defauchy.
 */
int count_lines(char *str)
{
    int lines = 1;
    size_t len = (size_t)my_strlen(str);

    if (!len)
        return FALSE;
    for (size_t i = 0; i < len; i++)
        if (str[i] == NEW_LINE)
            lines++;
    return lines;
}
