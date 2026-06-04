/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup char
 * @brief Tests if a character is an uppercase letter (A-Z).
 * @param c Character to test.
 * @return 1 if uppercase, 0 otherwise.
 * @note Complexity: O(1)
 * @note Part of UtilsLib by Victor Defauchy.
 */
int is_upperletter(char c)
{
    return c >= 'A' && c <= 'Z' ? TRUE : FALSE;
}
