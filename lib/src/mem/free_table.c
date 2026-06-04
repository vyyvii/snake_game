/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup mem
 * @brief Frees an array of pointers and each entry up to NULL.
 * @param table Array to free (NULL-terminated).
 * @return Nothing.
 * @note Complexity: O(n)
 * @note Part of UtilsLib by Victor Defauchy.
 */
void free_table(void ***table)
{
    if (!table || !*table)
        return;
    for (size_t i = 0; (*table)[i]; i++) {
        free((*table)[i]);
        (*table)[i] = NULL;
    }
    free(*table);
    *table = NULL;
}

/**
 * @ingroup mem
 * @brief Frees an array of pointers and each entry up to n.
 * @param table Array to free (NULL-terminated).
 * @return Nothing.
 * @note Complexity: O(n)
 * @note Part of UtilsLib by Victor Defauchy.
 */
void free_partial_table(void ***table, int n)
{
    if (!table || !*table)
        return;
    for (int i = 0; i < n; i++) {
        free((*table)[i]);
        (*table)[i] = NULL;
    }
    free(*table);
    *table = NULL;
}
