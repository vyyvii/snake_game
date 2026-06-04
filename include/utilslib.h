/*
** EPITECH PROJECT, 2026
** HEADER UtilsLib
** File description:
** Header file for UtilsLib
*/

/**
 * @file utilslib.h
 * @brief This file is the header file of UtilsLib.
 *
 * @details
 * This library provides utilities for:
 * - character classification (letter, digit, case),
 * - matrices operations & maths functions (add, mean, matrices),
 * - csv tools (read, write (csv)),
 * - integer manipulation (arithmetic, primality, sorting),
 * - conversion between strings and numbers,
 * - string operations (tests, copies, joins, search),
 * - management of string arrays (arrays),
 * - low-level memory primitives (copy, swap, file reading).
 * - replicate of ncurses with ansi escape sequences
 *
 * Functions that allocate memory return a pointer that must be freed
 * by the caller via `free`. Some functions use system calls and standard
 * library functions that may be forbidden depending on the rules
 * (e.g., open/read/close, getline/strcspn). See @warning in each description.
 *
 * @note Time complexity is indicated when relevant.
 * @author Victor Defauchy
 * @date 07.04.2026
 */

#ifndef UTILSLIB
    #define UTILSLIB
    #define SUCCESS 0
    #define FALSE 0
    #define FALSE_FLT 0.0
    #define TRUE 1
    #define FAILURE 84
    #define CHUNK 128
    #define NEW_LINE '\n'
    #define NULL_BYTE '\0'
    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <string.h>
    #include <limits.h>
    #include <math.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stdbool.h>
    #include <stdbool.h>

/**
 * @defgroup bool Booleans
 * @brief Utility functions related to booleans classification.
 */
/**
 * @defgroup char Characters
 * @brief Utility functions related to character classification.
 */
/**
 * @defgroup maths Mathematics
 * @brief Utility functions related to mathematics.
 */
/**
 * @defgroup int_str Strings ↔ Numbers
 * @brief Conversions and printing of numbers in text form and vice versa.
 */
/**
 * @defgroup str Strings
 * @brief Operations on C strings (null-terminated).
 */
/**
 * @defgroup matrice String matrices
 * @brief Tools for arrays of strings (char**).
 */
/**
 * @defgroup mem Memory and I/O
 * @brief Low-level memory tools and file reading.
 */
/**
 * @defgroup csv CSV tools
 * @brief Read & write functions for CSV files.
 */
/**
 * @defgroup binary Binary tools
 * @brief Tools usefull for reading raw binary in C
 */
/**
 * @defgroup my_ncurses Terminal UI management
 * @brief Replicate of ncurses with ansi escape sequences
 */

/* ============================================================
** BOOL
** ============================================================ */

bool get_bool(char *type);
char *give_bool(bool type);

/* ============================================================
** CHAR
** ============================================================ */

int is_digit(char c);
int is_letter(char c);
int is_lowerletter(char c);
int is_upperletter(char c);
int is_sep(char c);
void my_putchar(char c);
void my_putchar_error(char c);

/* ============================================================
** MATHS
** ============================================================ */

typedef struct abcsizeij_s {
    double **A;
    double **B;
    double **C;
    int i;
    int j;
    int sizeB;
} abcsizeij_t;

double my_power(int nb, int p);
int my_find_prime_sup(int nb);
int my_is_prime(int nb);
int my_isneg(int n);
void my_sort_int_array(int *array, int size);
double my_sqrt(double nb);
int my_perfect_sqrt(int nb);
void print_matrix(double **matrice, int line, int col);
double **multiplies_two_matrices(double **A, double **B, int sizeA, int sizeB);
double **add_two_matrices(double **A, double **B, int sizeA, int sizeB);
double **soustract_two_matrices(double **A, double **B, int sizeA, int sizeB);
double **divise_matrice_by_double(double **A, int sizeA, double divise_by);
double **construct_matrice(double *A, int sizeA);
double **identity_matrice(int len);
double **dup_matrice(double **A, int size);
double my_factorial(int nb);
int list_min_int(int *list, int size_list);
int list_max_int(int *list, int size_list);
double list_min_float(double *list, int size_list);
double list_max_float(double *list, int size_list);
int list_sum_int(int *list, int size_list);
double list_mean_int(int *list, int size_list);
double standard_deviation_int(int *list, int size_list);
double list_sum_float(double *list, int size_list);
double list_mean_float(double *list, int size_list);
double standard_deviation_float(double *list, int size_list);

/* ============================================================
** INT_STR
** ============================================================ */

int my_getnbr(char const *str);
double my_get_double_nbr(char const *str);
long long my_get_longlong_nbr(char const *str);
int my_put_nbr(int nb);
int my_put_nbr_err(int nb);
int verif_int(char *number, int *result);
int verif_double(char *number, double *result);
int get_precision(char *number);

/* ============================================================
** STR
** ============================================================ */

int contains_char(char *str, char c);
int count_char(char *str, char c);
int index_char(char *str, char c);

void my_putstr(char const *str);
void my_putstr_error(char const *str);
int my_strlen(char const *str);

char *my_revstr(char *str);
char *my_strcapitalize(char *str);
char *my_strlowcase(char *str);
char *my_strupcase(char *str);

int my_str_is_only_space(char *str);
int my_str_isalpha(char const *str);
int my_str_isalphanumeric(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);

int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strcmp_no_case(char *a, char *b);

char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, size_t size);
char *my_strdup(char const *str);

char *my_strjoin(char const *s1, char const *s2);
char *my_strjoin_three(char const *s1, char const *s2, char const *s3);

char *my_strstr(char *str, char const *to_find);
char *strslice(char *str, int from, int to);

void putcat(char *txt1, char *txt2);
char *take_user_input(void);
char **str_to_array(char *str);

/* ============================================================
** MATRICE
** ============================================================ */

char **uniq_words(char *str);
void alpha_sort(char **array, int is_reverse);

char **str_to_matrice(char *str, char *delims);
char **str_to_word_array(char *str);
char **str_to_word_array_space(char *str);

int nb_args(char **args);
int my_show_word_array(char const **tab);
int count_lines(char *str);

/* ============================================================
** MEM
** ============================================================ */

void my_swap(void *a, void *b, size_t size);
void *my_memcpy(void *dest, const void *src, size_t n);
void *my_memset(void *ptr, int value, size_t num);

char *open_file(char *file);

void free_table(void ***table);
void free_partial_table(void ***table, int n);

/* ============================================================
** CSV
** ============================================================ */

typedef enum {
    BOOL,
    INT,
    UINT,
    FLOAT,
    STRING,
    UNDEFINED
} column_type_t;

typedef struct {
    int nb_rows;
    int nb_columns;
    int no_head;
    char **column_names;
    column_type_t *column_types;
    char ***data;
    char *separator;
} dataframe_t;

dataframe_t *df_read_csv(const char *filename, const char *separator,
    int no_head);
int df_write_csv(dataframe_t *dataframe, const char *filename);
char **copie_heads(dataframe_t *df);
void free_csv(char ***data);
void free_partial_csv(char ***data, int n);
void df_free(dataframe_t *dataframe);

/* ============================================================
** BINARY
** ============================================================ */

    #define INT_SIZE 4
    #define BYTE 8

char to_hex(unsigned char b);
void print_bytes(unsigned char b, int upcase);
char *to_bytes(unsigned char b);
int read_int(unsigned char *buffer, int i);
short read_short(unsigned char *buffer, int i);
unsigned char read_byte(unsigned char *buffer, int i);
unsigned char *write_int(int nb);
unsigned char *write_short(int nb);
void write_hex(unsigned char *buffer, int size);
void print_hex_int(int nb);

/* ============================================================
** MY_NCURSES
** ============================================================ */

void put_cursor(int x, int y);
void refresh_sreen(void);
void cursor_home(void);
void reset_color(void);

#endif /* !UTILSLIB */
