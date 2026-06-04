/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup char
 * @brief Tests if a character is a letter (A-Z, a-z).
 * @param c Character to test.
 * @return 1 if letter, 0 otherwise.
 * @note Complexity: O(1)
 * @note Part of UtilsLib by Victor Defauchy.
 */
int is_letter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ? TRUE : FALSE;
}
