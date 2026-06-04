/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup str
 * @brief Compares the first n characters of two strings.
 * @param s1 String 1.
 * @param s2 String 2.
 * @param n Number of characters to compare.
 * @return 0 if equal on n, 1 if s1>s2, -1 otherwise.
 * @note Complexity: O(n)
 * @note Part of UtilsLib by Victor Defauchy.
 */
int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (!s1 || !s2)
        return (!s1 && !s2) ? 1 : 0;
    while (i < n && (s1[i] != NULL_BYTE || s2[i] != NULL_BYTE)) {
        if (s1[i] != s2[i])
            return (s1[i] > s2[i]) ? 1 : -1;
        i++;
    }
    return FALSE;
}
