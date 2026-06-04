/*
** EPITECH PROJECT, 2026
** cuddle
** File description:
** Recode pandas library
*/

#include "utilslib.h"

static void print_separator(dataframe_t *df, int x, int fd)
{
    if (x < df->nb_columns - 1)
        write(fd, df->separator, strlen(df->separator));
}

/**
 * @ingroup csv
 * @brief Writes a dataframe into a CSV file.
 * @param dataframe Pointer to the dataframe to write.
 * @param filename Path to the output file.
 * @return SUCCESS on success, FAILURE on error.
 * @note Complexity: O(n * m).
 * @note Part of UtilsLib by Victor Defauchy.
 * @pre dataframe must be valid and fully initialized.
 */
int df_write_csv(dataframe_t *dataframe, const char *filename)
{
    int fd = (dataframe && filename)
        ? open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644) : -1;

    if (fd == -1)
        return FAILURE;
    for (int i = 0; dataframe->column_names[i]; i++) {
        write(fd, dataframe->column_names[i],
            strlen(dataframe->column_names[i]));
        print_separator(dataframe, i, fd);
    }
    write(fd, "\n", 1);
    for (int i = 0; dataframe->data[i]; i++) {
        for (int j = 0; dataframe->data[i][j]; j++) {
            write(fd, dataframe->data[i][j], strlen(dataframe->data[i][j]));
            print_separator(dataframe, j, fd);
        }
        write(fd, "\n", 1);
    }
    close(fd);
    return SUCCESS;
}
