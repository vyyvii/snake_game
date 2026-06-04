/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup char
 * @brief Tests if a character is a lowercase letter (a-z).
 * @param c Character to test.
 * @return 1 if lowercase, 0 otherwise.
 * @note Complexity: O(1)
 * @note Part of UtilsLib by Victor Defauchy.
 */
int is_lowerletter(char c)
{
    return c >= 'a' && c <= 'z' ? TRUE : FALSE;
}
