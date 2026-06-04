/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup str
 * @brief Tests if the string contains only lowercase letters.
 * @param str String.
 * @return 1 if lowercase only, otherwise 0.
 * @note Complexity: O(n)
 * @note Part of UtilsLib by Victor Defauchy.
 */
int my_str_islower(char const *str)
{
    if (!str)
        return FALSE;
    while (*str) {
        if (is_lowerletter(*str))
            str++;
        else
            return FALSE;
    }
    return TRUE;
}
