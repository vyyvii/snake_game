/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

static void print_tab(int j, int col)
{
    if (j != col - 1)
        printf("\t");
}

/**
 * @ingroup display
 * @brief Print a matrix to standard output.
 * @param matrice The matrix to print.
 * @param line Number of rows.
 * @param col Number of columns.
 * @note Values are printed with two decimal places and separated by tabs.
 * @note Complexity: O(n*m)
 * @note Part of UtilsLib by Victor Defauchy.
 */
void print_matrix(double **matrice, int line, int col)
{
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < col; j++) {
            printf("%.2f", matrice[i][j]);
            print_tab(j, col);
        }
        printf("\n");
    }
}
