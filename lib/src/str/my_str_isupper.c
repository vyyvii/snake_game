/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup str
 * @brief Tests if the string contains only uppercase letters.
 * @param str String.
 * @return 1 if uppercase only, otherwise 0.
 * @note Complexity: O(n)
 * @note Part of UtilsLib by Victor Defauchy.
 */
int my_str_isupper(char const *str)
{
    if (!str)
        return FALSE;
    while (*str) {
        if (is_upperletter(*str))
            str++;
        else
            return FALSE;
    }
    return TRUE;
}
