/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup int_str
 * @brief Prints an integer to stdout without newline.
 * @param nb Integer to print.
 * @return 0.
 * @note Complexity: O(log10 n)
 * @note Uses recursion to print digits.
 * @note Part of UtilsLib by Victor Defauchy.
 */
int my_put_nbr(int nb)
{
    long value = (long)nb;

    if (value < 0) {
        my_putchar('-');
        value = -value;
    }
    if (value >= 10)
        my_put_nbr((int)(value / 10));
    my_putchar((char)((value % 10) + '0'));
    return SUCCESS;
}

/**
 * @ingroup int_str
 * @brief Prints an integer to stderr without newline.
 * @param nb Integer to print.
 * @return 0.
 * @note Complexity: O(log10 n)
 * @note Uses recursion to print digits.
 * @note Part of UtilsLib by Victor Defauchy.
 */
int my_put_nbr_err(int nb)
{
    long value = (long)nb;

    if (value < 0) {
        my_putchar('-');
        value = -value;
    }
    if (value >= 10)
        my_put_nbr_err((int)(value / 10));
    my_putchar_error((char)((value % 10) + '0'));
    return SUCCESS;
}
