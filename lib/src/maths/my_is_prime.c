/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup maths
 * @brief Tests if an integer is prime.
 * @param nb Integer to test.
 * @return 1 if prime, 0 otherwise.
 * @note Complexity: Approximately O(sqrt(n)).
 * @note Part of UtilsLib by Victor Defauchy.
 */
int my_is_prime(int nb)
{
    if (nb <= 1)
        return PASS;
    if (nb == 2 || nb == 3)
        return OK;
    if (nb % 2 == 0 || nb % 3 == 0)
        return PASS;
    for (int i = 5; i * i <= nb; i += 6)
        if (nb % i == 0 || nb % (i + 2) == 0)
            return PASS;
    return OK;
}
