/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup str
 * @brief Prints a string to stdout.
 * @param str Null-terminated string.
 * @note Complexity: O(n)
 * @note Part of UtilsLib by Victor Defauchy.
 */
void my_putstr(char const *str)
{
    if (!str)
        return;
    while (*str != NULL_BYTE) {
        my_putchar(*str);
        str++;
    }
}

/**
 * @ingroup str
 * @brief Prints a string to stderr.
 * @param str Null-terminated string.
 * @note Complexity: O(n)
 * @note Part of UtilsLib by Victor Defauchy.
 */
void my_putstr_error(char const *str)
{
    if (!str)
        return;
    while (*str != NULL_BYTE) {
        my_putchar_error(*str);
        str++;
    }
}
