/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup char
 * @brief Tests if a character is a digit ('0'..'9').
 * @param c Character to test.
 * @return 1 if digit, 0 otherwise.
 * @note Complexity: O(1)
 * @note Part of UtilsLib by Victor Defauchy.
 */
int is_digit(char c)
{
    return c >= '0' && c <= '9' ? TRUE : FALSE;
}
