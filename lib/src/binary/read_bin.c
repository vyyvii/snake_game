/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup binary
 * @brief Read a integer in buffer at the index i
 * @param buffer The buffer
 * @param i Index of the buffer
 * @return The value of the int
 * @note Part of UtilsLib by Victor Defauchy.
 */
int read_int(unsigned char *buffer, int i)
{
    return (buffer[i] << (BYTE * 3)) | (buffer[i + 1] << (BYTE * 2))
        | (buffer[i + 2] << BYTE) | (buffer[i + 3]);
}

/**
 * @ingroup binary
 * @brief Read a short in buffer at the index i
 * @param buffer The buffer
 * @param i Index of the buffer
 * @return The value of the short
 * @note Part of UtilsLib by Victor Defauchy.
 */
short read_short(unsigned char *buffer, int i)
{
    return (buffer[i] << BYTE) | (buffer[i + 1]);
}

/**
 * @ingroup binary
 * @brief Read a integer in buffer at the index i
 * @param buffer The buffer
 * @param i Index of the buffer
 * @return The byte
 * @note Quite helpless
 * @note Part of UtilsLib by Victor Defauchy.
 */
unsigned char read_byte(unsigned char *buffer, int i)
{
    return buffer[i];
}
