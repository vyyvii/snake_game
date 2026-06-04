/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup int_str
 * @brief Give the precision of a double number
 * @param number String to test
 * @return Return the precision of the number, -1 if an error occurs
 * @note Complexity: O(n)
 * @note Part of UtilsLib by Victor Defauchy.
 */
int get_precision(char *number)
{
    int i = 0;
    int precision = 0;

    if (!number || !is_digit(number[0]))
        return -TRUE;
    if (!contains_char(number, '.'))
        return SUCCESS;
    while (number[i] && number[i] != '.')
        i++;
    i++;
    if (!is_digit(number[i]))
        return -TRUE;
    while (number[i]) {
        if (is_digit(number[i]))
            precision++;
        else
            return -TRUE;
        i++;
    }
    return precision;
}
