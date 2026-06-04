/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup binary
 * @brief Write an integer in buffer
 * @param nb The int
 * @return The int in a buffer
 * @note Part of UtilsLib by Victor Defauchy.
 */
unsigned char *write_int(int nb)
{
    unsigned char *buffer = malloc(sizeof(unsigned char) * 4);

    if (!buffer)
        return NULL;
    buffer[0] = (nb >> (BYTE * 3)) & 0xFF;
    buffer[1] = (nb >> (BYTE * 2)) & 0xFF;
    buffer[2] = (nb >> BYTE) & 0xFF;
    buffer[3] = nb & 0xFF;
    return buffer;
}

/**
 * @ingroup binary
 * @brief Write a short in buffer
 * @param nb The short
 * @return The short in a buffer
 * @note Part of UtilsLib by Victor Defauchy.
 */
unsigned char *write_short(int nb)
{
    unsigned char *buffer = malloc(sizeof(unsigned char) * 2);

    if (!buffer)
        return NULL;
    buffer[0] = (nb >> BYTE) & 0xFF;
    buffer[1] = nb & 0xFF;
    return buffer;
}

/**
 * @ingroup binary
 * @brief Write on stdout, a hex value of size n
 * @param buffer The hex number
 * @param size The size of the buffer
 * @return Nothing
 * @note Part of UtilsLib by Victor Defauchy.
 */
void write_hex(unsigned char *buffer, int size)
{
    if (size == 0)
        return;
    for (int i = 0; i < size; i++)
        print_bytes(buffer[i], 1);
}

/**
 * @ingroup binary
 * @brief Write on stdout, a hex value of size 4 (int). Handle malloc of hex
 * @param buffer The hex number
 * @param size The size of the buffer
 * @return Nothing
 * @note Part of UtilsLib by Victor Defauchy.
 */
void print_hex_int(int nb)
{
    unsigned char *hex = NULL;

    hex = write_int(nb);
    if (!hex)
        return;
    write_hex(hex, INT_SIZE);
    free(hex);
}
