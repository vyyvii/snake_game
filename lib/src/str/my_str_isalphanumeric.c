/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup str
 * @brief Tests if the string contains only alphanumerics characters
 * A-Z/a-z/0-9/_.
 * @param str String.
 * @return 1 if alphanumeric only, otherwise 0.
 * @note Complexity: O(n)
 * @note Part of UtilsLib by Victor Defauchy.
 */
int my_str_isalphanumeric(char const *str)
{
    if (!str)
        return FALSE;
    while (*str) {
        if (my_str_isalpha(str) || *str == '_' || my_str_isnum(str))
            str++;
        else
            return FALSE;
    }
    return TRUE;
}
