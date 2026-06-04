/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup int_str
 * @brief Validates that a string represents an integer (optionally signed)
 * and converts it.
 * @param number String to validate (may start with '-').
 * @param result Output: converted integer if valid.
 * @return 0 on success, 84 if the string is not a valid integer.
 * @note Complexity: O(n)
 * @note Part of UtilsLib by Victor Defauchy.
 * @warning Does not handle internal spaces; only ASCII digits are accepted.
 */
int verif_int(char *number, int *result)
{
    int len_number = my_strlen(number);
    int start = 0;

    if (len_number == 0 || (number[0] == '-' && len_number == 1))
        return FAILURE;
    if (number[0] == '-')
        start = 1;
    for (int i = start; i < len_number; i++) {
        if (!is_digit(number[i]))
            return FAILURE;
    }
    *result = my_getnbr(number);
    return SUCCESS;
}
