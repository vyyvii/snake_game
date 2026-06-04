/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup str
 * @brief Tests if the string contains only spaces.
 * @param str String.
 * @return 1 if spaces, tabs, nothing or tabs only, otherwise 0.
 * @note Complexity: O(n)
 * @note Part of UtilsLib by Victor Defauchy.
 */
int my_str_is_only_space(char *str)
{
    if (!str)
        return TRUE;
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ' && str[i] != '\t'
            && str[i] != NEW_LINE && str[i] != NULL_BYTE)
            return FALSE;
    return TRUE;
}
