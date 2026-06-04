/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup char
 * @brief Tests if a character is a common separator (space or tab).
 * @param c Character to test.
 * @return 1 if separator, 0 otherwise.
 * @note Complexity: O(1)
 * @note Part of UtilsLib by Victor Defauchy.
 */
int is_sep(char c)
{
    return (c == ' ' || c == '\t') ? TRUE : FALSE;
}
