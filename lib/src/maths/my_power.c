/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup maths
 * @brief Recursive power in double: computes nb ^ p.
 * @param nb Double base.
 * @param p Exponent (0 returns 1, negative returns 0).
 * @return Result of nb ^ p if valid, otherwise 0 for invalid cases.
 * @note Complexity: O(p)
 * @note Part of UtilsLib by Victor Defauchy.
 * @warning Undefined behavior for large values due to internal limits.
 */
double my_power_double(double nb, int p)
{
    if (p == 0)
        return OK;
    else if (p < 0)
        return PASS;
    return my_power_double(nb, p - 1) * nb;
}
