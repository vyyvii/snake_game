/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

static int valid_word(int i, char **array, char *str, int *cell)
{
    int start = i;
    int end = i;

    while (str[end] && !is_sep(str[end]))
        end++;
    if (str[end] == NULL_BYTE || is_sep(str[end])) {
        array[*cell] = strslice(str, start, end);
        if (!array[*cell])
            free_partial_table((void ***)&array, *cell);
        (*cell)++;
    }
    i = end;
    return i;
}

/**
 * @ingroup matrice
 * @brief Transform a string to an array, whith space or tab as delimiter.
 * @param str String
 * @return A NULL-terminated array, or NULL if allocation fails.
 * @note Complexity: O(|str|)
 * @note Ownership: The caller must `free` each word and the array.
 * @note Part of UtilsLib by Victor Defauchy.
 */
char **str_to_array(char *str)
{
    char **array = (str) ? malloc(sizeof(char *) * (my_strlen(str) + 1)) : NULL;
    int cell = 0;
    int i = 0;

    if (!str || !array || my_str_is_only_space(str)) {
        free(array);
        return NULL;
    }
    while (str[i]) {
        if (!is_sep(str[i]) && (i == 0 || is_sep(str[i - 1])))
            i = valid_word(i, array, str, &cell);
        else
            i++;
    }
    array[cell] = NULL;
    return array;
}
