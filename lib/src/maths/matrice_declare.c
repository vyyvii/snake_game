/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

/**
 * @ingroup maths
 * @brief Construct new matrice from an existing one.
 * @param A The array to duplicate.
 * @param size The size of the matrice.
 * @return A newly allocated square matrix filled row by row,
 * or NULL if allocation fails.
 * @note The size of the matrix is determined using sqrt(sizeA).
 * @note Complexity: O(n^2)
 * @note Part of UtilsLib by Victor Defauchy.
 */
double **dup_matrice(double **A, int size)
{
    double **matrice = malloc(sizeof(double *) * size);

    if (!matrice)
        return NULL;
    for (int i = 0; i < size; i++) {
        matrice[i] = malloc(sizeof(double) * size);
        if (!matrice[i]) {
            free_partial_table((void ***)&matrice, i);
            return NULL;
        }
        for (int j = 0; j < size; j++)
            matrice[i][j] = A[i][j];
    }
    return matrice;
}

/**
 * @ingroup maths
 * @brief Construct a square matrix from a linear array of coefficients.
 * @param A The array containing the coefficients.
 * @param sizeA The number of coefficients in the array.
 * @return A newly allocated square matrix filled row by row,
 * or NULL if allocation fails.
 * @note The size of the matrix is determined using sqrt(sizeA).
 * @note Complexity: O(n^2)
 * @note Part of UtilsLib by Victor Defauchy.
 */
double **construct_matrice(double *A, int sizeA)
{
    int size = (int)my_sqrt((double)sizeA);
    double **matrice = malloc(sizeof(double *) * size);
    int k = 0;

    if (!matrice)
        return NULL;
    for (int i = 0; i < size; i++) {
        matrice[i] = malloc(sizeof(double) * size);
        if (!matrice[i]) {
            free_partial_table((void ***)&matrice, i);
            return NULL;
        }
        for (int j = 0; j < size; j++) {
            matrice[i][j] = (k < sizeA) ? A[k] : 0.0;
            k++;
        }
    }
    return matrice;
}

/**
 * @ingroup maths
 * @brief Create an identity matrix.
 * @param size The dimension of the square matrix.
 * @return A size x size identity matrix, or NULL if allocation fails.
 * @note The identity matrix contains 1.0 on the diagonal and 0.0 elsewhere.
 * @note Complexity: O(n^2)
 * @note Part of UtilsLib by Victor Defauchy.
 */
double **identity_matrice(int size)
{
    double **matrice = malloc(sizeof(double *) * size);

    if (!matrice)
        return NULL;
    for (int i = 0; i < size; i++) {
        matrice[i] = malloc(sizeof(double) * size);
        if (!matrice[i]) {
            free_partial_table((void ***)&matrice, i);
            return NULL;
        }
        for (int j = 0; j < size; j++)
            matrice[i][j] = (i == j) ? 1.0 : 0.0;
    }
    return matrice;
}
