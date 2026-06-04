/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup str
 * @brief Reads one line from stdin with user input.
 * @return The string of the user.
 * @warning Uses getline(3).
 * @note Part of UtilsLib by Victor Defauchy.
 */
char *take_user_input(void)
{
    size_t size = 0;
    ssize_t len = 0;
    char *input = NULL;

    len = getline(&input, &size, stdin);
    if (len == -1) {
        if (input)
            free(input);
        return NULL;
    } else if (len > 0 && input[len - 1] == NEW_LINE)
        input[len - 1] = NULL_BYTE;
    return input;
}
