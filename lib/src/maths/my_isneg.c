/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup maths
 * @brief Returns 1 if n is negative, 0 otherwise.
 * @param n Integer.
 * @return 1 if n is negative, 0 otherwise.
 * @note Complexity: O(1)
 * @note Part of UtilsLib by Victor Defauchy.
 */
int my_isneg(int n)
{
    return n >= 0 ? 1 : 0;
}
