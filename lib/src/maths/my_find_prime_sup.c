/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup maths
 * @brief Finds the smallest prime number greater than or equal to nb.
 * @param nb Start integer.
 * @return The first prime number >= nb.
 * @note Complexity: Per test near O(log log n); incremental search overall.
 * @note Part of UtilsLib by Victor Defauchy.
 */
int my_find_prime_sup(int nb)
{
    int i = 0;

    while (my_is_prime(nb + i) == 0)
        i++;
    return nb + i;
}
