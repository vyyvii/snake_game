/*
** EPITECH PROJECT, 2026
** cuddle
** File description:
** Recode pandas library
*/

#include "utilslib.h"

/**
 * @ingroup csv
 * @brief Copies the column names of a dataframe
 * into a new NULL-terminated array.
 * @param df Pointer to the dataframe.
 * @return Newly allocated array of duplicated column names, or NULL on failure.
 * @note Complexity: O(n * m) (n columns, m average string length).
 * @note Part of UtilsLib by Victor Defauchy.
 * @pre df must be valid and df->column_names must be initialized.
 */
char **copie_heads(dataframe_t *df)
{
    char **column_names = malloc(sizeof(char *) * (df->nb_columns + 1));

    if (!column_names)
        return NULL;
    for (int i = 0; i < df->nb_columns; i++) {
        column_names[i] = strdup(df->column_names[i]);
        if (!column_names) {
            free_partial_table((void ***)&column_names, i);
            return NULL;
        }
    }
    column_names[df->nb_columns] = NULL;
    return column_names;
}

/**
 * @ingroup csv
 * @brief Frees a NULL-terminated 3D array of strings (CSV-like structure).
 * @param data Triple pointer representing rows -> columns -> strings.
 * @return None.
 * @note Complexity: O(n * m) (n rows, m columns).
 * @note Part of UtilsLib by Victor Defauchy.
 * @pre data must be NULL or a valid NULL-terminated array.
 */
void free_csv(char ***data)
{
    if (!data)
        return;
    for (int i = 0; data[i]; i++) {
        for (int j = 0; data[i][j]; j++)
            free(data[i][j]);
        free(data[i]);
    }
    free(data);
}

/**
 * @ingroup csv
 * @brief Frees the first n rows of a 3D array of strings.
 * @param data Triple pointer representing rows -> columns -> strings.
 * @param n Number of rows to free.
 * @return None.
 * @note Complexity: O(n * m).
 * @note Part of UtilsLib by Victor Defauchy.
 * @pre data must be NULL or partially allocated up to n rows.
 */
void free_partial_csv(char ***data, int n)
{
    if (!data)
        return;
    for (int i = 0; i < n; i++) {
        for (int j = 0; data[i][j]; j++)
            free(data[i][j]);
        free(data[i]);
    }
    free(data);
}

void df_free(dataframe_t *dataframe)
{
    if (!dataframe)
        return;
    if (dataframe->separator)
        free(dataframe->separator);
    if (dataframe->column_types)
        free(dataframe->column_types);
    if (dataframe->column_names)
        free_table((void ***)&dataframe->column_names);
    if (dataframe->data)
        free_csv(dataframe->data);
    free(dataframe);
}
