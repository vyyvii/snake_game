/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup mem
 * @brief Concatenates and writes s1+s2 to stdout, then frees the concatenation.
 * @param txt1 First string.
 * @param txt2 Second string.
 * @return Nothing.
 * @note Complexity: O(|txt1| + |txt2|)
 * @note Ownership: Allocates temporarily; internal free after printing.
 * @note Part of UtilsLib by Victor Defauchy.
 */
void putcat(char *txt1, char *txt2)
{
    char *cat = my_strjoin(txt1, txt2);

    if (!cat)
        return;
    my_putstr(cat);
    free(cat);
}
