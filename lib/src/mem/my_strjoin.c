/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup mem
 * @brief Concatenates two strings into a newly allocated string.
 * @param s1 First string.
 * @param s2 Second string.
 * @return New string s1+s2, or NULL if allocation fails.
 * @note Complexity: O(|s1| + |s2|)
 * @note Ownership: The caller must `free` the result.
 * @note Part of UtilsLib by Victor Defauchy.
 */
char *my_strjoin(char const *s1, char const *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    char *res = malloc(len1 + len2 + 1);
    int i = 0;

    if (!res)
        return NULL;
    for (i = 0; i < len1; i++)
        res[i] = s1[i];
    for (i = 0; i < len2; i++)
        res[len1 + i] = s2[i];
    res[len1 + len2] = NULL_BYTE;
    return res;
}
