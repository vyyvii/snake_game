/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

static int detect_point_minus(char *number, int *i, int *is_point)
{
    if (number[*i] == '.' && !(*is_point) && *i != 0
        && is_digit(number[*i - 1]) && is_digit(number[*i + 1])) {
        (*i)++;
        *is_point = 1;
        return TRUE;
    }
    return FALSE;
}

/**
 * @ingroup int_str
 * @brief Validates that a string represents an double (optionally signed)
 * and converts it.
 * @param number String to validate (may start with '-').
 * @param result Output: converted double if valid.
 * @return 0 on success, 84 if the string is not a valid double.
 * @note Complexity: O(n)
 * @note Part of UtilsLib by Victor Defauchy.
 * @warning Does not handle internal spaces; only ASCII digits are accepted.
 */
int verif_double(char *number, double *result)
{
    int is_point = 0;
    int i = 0;
    int len_nb = my_strlen(number);

    if (len_nb == 0)
        return FAILURE;
    if (number[0] == '-' && len_nb > 1)
        i = 1;
    while (number[i]) {
        if (is_digit(number[i])) {
            i++;
            continue;
        }
        if (detect_point_minus(number, &i, &is_point))
            continue;
        return FAILURE;
    }
    *result = my_get_double_nbr(number);
    return SUCCESS;
}
