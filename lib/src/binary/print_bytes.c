/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup binary
 * @brief Converts 4 bits into a hex value.
 * @param b The 4 bits
 * @return The hex value of the 4 bits.
 * @note Part of UtilsLib by Victor Defauchy.
 */
char to_hex(unsigned char b)
{
    return (b < 10) ? '0' + b : 'a' + (b - 10);
}

/**
 * @ingroup binary
 * @brief Converts a byte (8 bits) into hex value.
 * @param b The byte
 * @return THe converted bytes in a string
 * @note Part of UtilsLib by Victor Defauchy.
 */
char *to_bytes(unsigned char b)
{
    char *hex = malloc(sizeof(char) * 3);

    if (!hex)
        return NULL;
    hex[0] = to_hex((b >> (BYTE / 2)) & 0xF);
    hex[1] = to_hex(b & 0xF);
    hex[2] = NULL_BYTE;
    return hex;
}

/**
 * @ingroup binary
 * @brief Converts a byte (8 bits) into hex value.
 * @param b The byte
 * @param upcase If the hex value is in upcase (FF or ff)
 * @return Nothing
 * @note Part of UtilsLib by Victor Defauchy.
 */
void print_bytes(unsigned char b, int upcase)
{
    char hex[3];

    hex[0] = to_hex((b >> (BYTE / 2)) & 0xF);
    hex[1] = to_hex(b & 0xF);
    hex[2] = NULL_BYTE;
    if (upcase)
        my_putstr(my_strupcase(hex));
    else
        my_putstr(hex);
}
