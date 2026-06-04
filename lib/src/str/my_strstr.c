/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup str
 * @brief Searches the first occurrence of to_find in str (like strstr).
 * @param str Search string.
 * @param to_find Pattern.
 * @return Pointer to the beginning of the occurrence, or NULL if not found.
 * @note Complexity: O(n*m) in the worst case.
 * @note Part of UtilsLib by Victor Defauchy.
 */
char *my_strstr(char *str, char const *to_find)
{
    int needle_len = my_strlen(to_find);

    if (!needle_len || !str || !to_find)
        return str;
    while (*str && my_strncmp(str, to_find, needle_len))
        str++;
    if (*str)
        return str;
    return NULL;
}
