/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup str
 * @brief Reverses a string in-place.
 * @param str Modifiable string.
 * @return Pointer to str.
 * @note Complexity: O(n)
 * @note Part of UtilsLib by Victor Defauchy.
 */
char *my_revstr(char *str)
{
    int count = 0;
    int i = 0;
    char switcher = NULL_BYTE;
    int digit_switch = 0;

    if (!str)
        return NULL;
    while (str[i] != NULL_BYTE) {
        count++;
        i++;
    }
    i = 0;
    while (i != count / 2) {
        digit_switch = count - i - 1;
        switcher = str[i];
        str[i] = str[digit_switch];
        str[digit_switch] = switcher;
        i++;
    }
    return str;
}
