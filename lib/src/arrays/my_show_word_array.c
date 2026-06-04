/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup matrice
 * @brief Prints an array of words, one per line, ending with NEW_LINE.
 * @param tab NULL-terminated array.
 * @return 0.
 * @note Complexity: O(total characters)
 * @note Part of UtilsLib by Victor Defauchy.
 */
int my_show_word_array(char const **tab)
{
    int i = 0;

    if (!tab)
        return FAILURE;
    while (tab[i]) {
        my_putstr(tab[i]);
        my_putchar(NEW_LINE);
        i++;
    }
    return SUCCESS;
}
