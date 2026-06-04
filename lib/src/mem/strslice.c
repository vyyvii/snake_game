/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup mem
 * @brief Extracts a substring [from, to) into a new allocation.
 * @param str Source.
 * @param from Start index (inclusive, clamped to 0).
 * @param to End index (exclusive, clamped to |str|).
 * @return New string, or NULL if from>=to or allocation fails.
 * @note Complexity: O(to - from)
 * @note Ownership: The caller must `free` the result.
 * @note Part of UtilsLib by Victor Defauchy.
 */
char *strslice(char *str, int from, int to)
{
    char *out = NULL;
    int len_str = my_strlen(str);
    int j = 0;

    from = (from < 0) ? 0 : from;
    to = (to > len_str) ? len_str : to;
    if (from >= to || !str)
        return NULL;
    out = malloc((to - from) + 1);
    if (!out)
        return NULL;
    for (int i = from; i < to; i++) {
        out[j] = str[i];
        j++;
    }
    out[j] = NULL_BYTE;
    return out;
}
