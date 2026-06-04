/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup char
 * @brief Writes a character to stdout.
 * @param c Character to write.
 * @return Nothing.
 * @note Complexity: O(1)
 * @note Uses write(2).
 * @note Part of UtilsLib by Victor Defauchy.
 */
void my_putchar(char c)
{
    write(STDOUT_FILENO, &c, 1);
}

/**
 * @ingroup char
 * @brief Writes a character to stderr.
 * @param c Character to write.
 * @return Nothing.
 * @note Complexity: O(1)
 * @note Uses write(2).
 * @note Part of UtilsLib by Victor Defauchy.
 */
void my_putchar_error(char c)
{
    write(STDERR_FILENO, &c, 1);
}
