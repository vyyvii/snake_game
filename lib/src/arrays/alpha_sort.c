/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup matrice
 * @brief Sort an array of strings in place.
 * @param array The array of strings (NULL terminated).
 * @param is_reverse If the sort must be done in alphabetical
 * order (1) or not (-1).
 * @return Nothing.
 * @note Complexity: O(n²)
 * @note Part of UtilsLib by Victor Defauchy.
 */
void alpha_sort(char **array, int is_reverse)
{
    char *tmp = NULL;

    for (int i = 1; array[i]; i++) {
        while (i > 0 && my_strcmp(array[i], array[i - 1]) == -is_reverse) {
            tmp = array[i];
            array[i] = array[i - 1];
            array[i - 1] = tmp;
            i--;
        }
    }
}
