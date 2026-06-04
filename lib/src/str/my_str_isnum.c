/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup str
 * @brief Tests if the string contains only digits.
 * @param str String.
 * @return 1 if numeric only, otherwise 0.
 * @note Complexity: O(n)
 * @note Part of UtilsLib by Victor Defauchy.
 */
int my_str_isnum(char const *str)
{
    int is_minus = 0;

    if (!str)
        return FALSE;
    while (*str) {
        if (is_digit(*str)) {
            str++;
            continue;
        }
        if (*str == '-' && !is_minus) {
            str++;
            is_minus = 1;
            continue;
        }
        return FALSE;
    }
    return TRUE;
}
