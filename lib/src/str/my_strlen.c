/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup str
 * @brief Returns the length of a string (excluding NULL_BYTE).
 * @param str String.
 * @return Number of characters.
 * @note Complexity: O(n)
 * @note Part of UtilsLib by Victor Defauchy.
 * @pre str != NULL.
 */
int my_strlen(char const *str)
{
    int len = 0;

    if (!str)
        return len;
    while (*str != NULL_BYTE) {
        len++;
        str++;
    }
    return len;
}
