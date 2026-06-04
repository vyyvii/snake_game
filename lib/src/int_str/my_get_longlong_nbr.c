/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

static int go_in_number(long long *result, const char *str, int i, int sign)
{
    while (is_digit(str[i])) {
        *result = *result * 10 + (str[i] - '0');
        i++;
        if (sign == 1 && *result > INT_MAX)
            return FALSE;
        if (sign == -1 && *result > (long)INT_MAX + 1)
            return FALSE;
    }
    return TRUE;
}

/**
 * @ingroup int_str
 * @brief Converts a string to a long long.
 * @param str Source string (optionally signed decimal integer).
 * @return Converted long long value.
 * @note Complexity: O(n)
 * @note Ignores any character after the valid numeric part.
 * @note Part of UtilsLib by Victor Defauchy.
 */
long long my_get_longlong_nbr(char const *str)
{
    int i = 0;
    int sign = 1;
    long long result = 0;

    if (!str)
        return FALSE;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    if (!is_digit(str[i]))
        return FALSE;
    if (!go_in_number(&result, str, i, sign))
        return FALSE;
    return (long long)(result * sign);
}
