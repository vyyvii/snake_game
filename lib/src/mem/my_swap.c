/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup mem
 * @brief Swaps the content of two memory blocks of given size.
 * @param a Block A pointer.
 * @param b Block B pointer.
 * @param size Size in bytes.
 * @return Nothing.
 * @note Complexity: O(size)
 * @note Part of UtilsLib by Victor Defauchy.
 * @pre a,b != NULL; valid and non-overlapping blocks.
 */
void my_swap(void *a, void *b, size_t size)
{
    char tmp[size];

    my_memcpy(tmp, a, size);
    my_memcpy(a, b, size);
    my_memcpy(b, tmp, size);
}
