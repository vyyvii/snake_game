/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup maths
 * @brief Sorts an integer array in ascending order (in-place).
 * @param array Pointer to the first element.
 * @param size Array size.
 * @return Nothing.
 * @note Complexity: Worst-case close to O(n ^ 2)
 * @note Part of UtilsLib by Victor Defauchy.
 * @pre array != NULL and size >= 0.
 */
void my_sort_int_array(int *array, int size)
{
    int switcher;

    for (int i = 1; i != size; i++) {
        while (array[i] < array[i - 1] && i > 0) {
            switcher = array[i];
            array[i] = array[i - 1];
            array[i - 1] = switcher;
            i--;
        }
    }
}
