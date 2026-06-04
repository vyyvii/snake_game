/*
** EPITECH PROJECT, 2026
** cuddle
** File description:
** Recode pandas library
*/

#include "utilslib.h"

static int data_type(char *data)
{
    int tmp_int = 0;
    double tmp_double = 0.0;

    if (my_strcmp_no_case(data, "true") == 0
        || my_strcmp_no_case(data, "false") == 0)
        return BOOL;
    if (verif_int(data, &tmp_int) == SUCCESS) {
        if (tmp_int < 0)
            return INT;
        return UINT;
    }
    if (verif_double(data, &tmp_double) == SUCCESS)
        return FLOAT;
    return STRING;
}

static int which_type(char *data, int current_type)
{
    int type = data_type(data);

    if ((current_type == INT && type == UINT)
        || (current_type == UINT && type == INT))
        return INT;
    return (current_type == UNDEFINED || current_type == type) ? type : STRING;
}

static int define_types(dataframe_t *df)
{
    for (int j = 0; j < df->nb_columns; j++) {
        for (int i = 0; i < df->nb_rows; i++)
            df->column_types[j] =
                which_type(df->data[i][j], df->column_types[j]);
    }
    df->column_types[df->nb_columns] = UNDEFINED;
    return SUCCESS;
}

static char ***line_runner(dataframe_t *df, char **file)
{
    char **tmp;
    char ***data = malloc(sizeof(char **) * (df->nb_rows + 1));
    int curr = 0;

    if (!data)
        return NULL;
    for (int i = 0; i < df->nb_rows; i++) {
        tmp = str_to_matrice(file[i + (df->no_head ? 0 : 1)], df->separator);
        if (!tmp) {
            free_partial_csv(data, curr);
            return NULL;
        }
        data[curr] = tmp;
        curr++;
    }
    data[curr] = NULL;
    return data;
}

static int extract_fail(int curr, char ***column_names)
{
    if (curr > 0 && !(*column_names)[curr - 1]) {
        free_partial_table((void ***)column_names, curr);
        return FAILURE;
    }
    return SUCCESS;
}

static char **extract_heads(dataframe_t *df, char *first_line)
{
    char **column_names = malloc(sizeof(char *) * (df->nb_columns + 1));
    int start = 0;
    int curr = 0;

    if (!column_names)
        return NULL;
    for (int i = 0; first_line[i]; i++) {
        if (!first_line[i + 1] || strncmp(&first_line[i],
                df->separator, strlen(df->separator)) == 0) {
            column_names[curr] = strslice(first_line, start,
                (!first_line[i + 1]) ? i + 1 : i);
            i += strlen(df->separator) - 1;
            start = i + 1;
            curr++;
        }
        if (extract_fail(curr, &column_names) == FAILURE)
            return NULL;
    }
    column_names[curr] = NULL;
    return column_names;
}

static void nb_col_lines(dataframe_t *df, char **file)
{
    int sep_len = strlen(df->separator);
    int j = 0;

    for (int i = (df->no_head ? 0 : 1); file[i]; i++)
        df->nb_rows++;
    while (file[0][j]) {
        if (strncmp(&file[0][j], df->separator, sep_len) == 0) {
            df->nb_columns++;
            j += sep_len;
        } else
            j++;
    }
    df->nb_columns++;
}

static int set_df(dataframe_t *df, char **file, const char *separator,
    int no_head)
{
    df->separator = (separator) ? strdup(separator) : strdup(",");
    if (!df->separator)
        return FAILURE;
    df->no_head = no_head;
    df->nb_rows = 0;
    df->nb_columns = 0;
    nb_col_lines(df, file);
    df->column_types = malloc(sizeof(column_type_t) * (df->nb_columns + 1));
    if (!df->column_types) {
        free(df->separator);
        return FAILURE;
    }
    for (int i = 0; i < df->nb_columns; i++)
        df->column_types[i] = UNDEFINED;
    df->column_names = extract_heads(df, file[0]);
    df->data = line_runner(df, file);
    if (!df->column_names || !df->data || define_types(df) == FAILURE)
        return FAILURE;
    return SUCCESS;
}

static char **open_csv(char *file_path)
{
    char *raw_file = open_file(file_path);
    char **matrice_file = NULL;

    if (!raw_file)
        return NULL;
    matrice_file = str_to_matrice(raw_file, "\n");
    free(raw_file);
    return (matrice_file) ? matrice_file : NULL;
}

/**
 * @ingroup csv
 * @brief Reads a CSV file and loads it into a dataframe structure.
 * @param filename Path to the CSV file.
 * @param separator Field separator (e.g. ","), defaults to "," if NULL.
 * @return Pointer to a newly allocated dataframe, or NULL on failure.
 * @note Complexity: O(n * m) (n rows, m columns).
 * @note Part of UtilsLib by Victor Defauchy.
 * @pre filename must be a valid path to a readable file.
 */
dataframe_t *df_read_csv(const char *filename, const char *separator,
    int no_head)
{
    char **file = open_csv((char *)filename);
    dataframe_t *df = (file) ? malloc(sizeof(dataframe_t)) : NULL;

    if (!file || !file[0] || !df) {
        if (file)
            free_table((void ***)&file);
        return NULL;
    }
    if (set_df(df, file, separator, no_head) == FAILURE) {
        free_table((void ***)&file);
        free(df);
        return NULL;
    }
    free_table((void ***)&file);
    return df;
}
