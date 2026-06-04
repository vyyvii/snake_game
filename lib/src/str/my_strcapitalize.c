/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup str
 * @brief Capitalizes the first letter of each word, makes others lowercase.
 * @param str Modifiable string.
 * @return Pointer to str.
 * @note Complexity: O(n)
 * @note Words are delimited by non-alphanumeric characters.
 * @note Part of UtilsLib by Victor Defauchy.
 */
char *my_strcapitalize(char *str)
{
    int i = 0;

    if (!str)
        return NULL;
    while (str[i] != NULL_BYTE) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        if (str[i] >= 'a' && str[i] <= 'z'
            && (i == 0 || is_letter(str[i - 1]) == 1))
            str[i] -= - 32;
        i++;
    }
    return str;
}
