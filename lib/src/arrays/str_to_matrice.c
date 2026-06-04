/*
** EPITECH PROJECT, 2026
** UtilisLib
** File description:
** The useful lib of VictorDfc
*/

#include "utilslib.h"

static int next_word(char *str, char *delims, int i)
{
    int sep_len = my_strlen(delims);

    while (str[i] && my_strncmp(&str[i], delims, sep_len) == 0)
        i += sep_len;
    return i;
}

static int word_length(char *str, char *delims, int i)
{
    int len = 0;
    int sep_len = my_strlen(delims);

    while (str[i + len] && my_strncmp(&str[i + len], delims, sep_len) != 0)
        len++;
    return len;
}

static char *duplicate_word(char *str, int start, int len)
{
    char *res = malloc(len + 1);

    if (!res)
        return NULL;
    my_strncpy(res, str + start, len);
    res[len] = NULL_BYTE;
    return res;
}

static int count_words(char *str, char *delims)
{
    int count = 0;
    int i = 0;

    while (str[i]) {
        i = next_word(str, delims, i);
        if (str[i] == NULL_BYTE)
            break;
        count++;
        i += word_length(str, delims, i);
    }
    return count;
}

static int fill_words(char *str, char *delims, char **array)
{
    int i = 0;
    int j = 0;
    int len = 0;

    while (str[i]) {
        i = next_word(str, delims, i);
        if (str[i] == NULL_BYTE)
            break;
        len = word_length(str, delims, i);
        array[j] = duplicate_word(str, i, len);
        if (!array[j])
            return -TRUE;
        j++;
        i += len;
    }
    array[j] = NULL;
    return FALSE;
}

/**
 * @ingroup matrice
 * @brief Converts a multi-line string into a matrice (char**).
 * @param str String
 * @param delims The delimiter.
 * @return Array of allocated lines with terminal NULL, or NULL if fail.
 * @note Ownership: The caller must `free` each line and the array.
 * @note Part of UtilsLib by Victor Defauchy.
 */
char **str_to_matrice(char *str, char *delims)
{
    int word_count = 0;
    char **array = NULL;

    if (!str || !delims)
        return NULL;
    word_count = count_words(str, delims);
    array = malloc(sizeof(char *) * (word_count + 1));
    if (!array)
        return NULL;
    if (fill_words(str, delims, array) == -1) {
        for (int i = 0; array[i]; i++)
            free(array[i]);
        free(array);
        return NULL;
    }
    return array;
}
