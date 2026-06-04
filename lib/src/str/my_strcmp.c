/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup str
 * @brief Compares two strings (lexicographic).
 * @param s1 String 1.
 * @param s2 String 2.
 * @return 0 if equal, 1 if s1>s2, -1 otherwise.
 * @note Complexity: O(min(n, m))
 * @note Part of UtilsLib by Victor Defauchy.
 */
int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (!s1 || !s2)
        return (!s1 && !s2) ? TRUE : FALSE;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    if (s1[i] == s2[i])
        return FALSE;
    return (s1[i] > s2[i]) ? TRUE : -TRUE;
}
