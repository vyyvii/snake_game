/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup str
 * @brief Converts all letters to uppercase in-place.
 * @param str Modifiable string.
 * @return Pointer to str.
 * @note Complexity: O(n)
 * @note Part of UtilsLib by Victor Defauchy.
 */
char *my_strupcase(char *str)
{
    int i = 0;

    if (!str)
        return NULL;
    while (str[i] != NULL_BYTE) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
    return str;
}
