##
## EPITECH PROJECT, 2026
## Makefile UtilsLib
## File description:
## Makefile UtilsLib
##

# ─────────────────────────────────────────────────────────────
# NAME
# ─────────────────────────────────────────────────────────────
NAME 		= 	libUtilsLib.a

# ─────────────────────────────────────────────────────────────
# SOURCE FILES AND OBJECT FILES
# ─────────────────────────────────────────────────────────────
SRC_CHAR	= 	src/char/is_digit.c \
				src/char/is_letter.c \
				src/char/is_lowerletter.c \
				src/char/is_upperletter.c \
				src/char/is_sep.c \
				src/char/my_putchar.c
SRC_INT_STR =	src/int_str/get_precision.c \
				src/int_str/my_get_double_nbr.c \
				src/int_str/my_get_longlong_nbr.c \
				src/int_str/my_getnbr.c \
				src/int_str/my_put_nbr.c \
				src/int_str/verif_double.c \
				src/int_str/verif_int.c
SRC_ARRAYS	=	src/arrays/ac.c \
				src/arrays/alpha_sort.c \
				src/arrays/count_lines.c \
				src/arrays/my_show_word_array.c \
				src/arrays/str_to_array.c \
				src/arrays/str_to_matrice.c
SRC_MEM		=	src/mem/free_table.c \
				src/mem/my_memcpy.c \
				src/mem/my_memset.c \
				src/mem/my_strcpy.c \
				src/mem/my_strdup.c \
				src/mem/my_strncpy.c \
				src/mem/my_swap.c \
				src/mem/open_file.c \
				src/mem/strslice.c \
				src/mem/my_strjoin_three.c \
				src/mem/my_strjoin.c \
				src/mem/putcat.c
SRC_STR		=	src/str/count_contains_char.c \
				src/str/my_putstr.c \
				src/str/my_revstr.c \
				src/str/my_str_is_only_space.c \
				src/str/my_str_isalpha.c \
				src/str/my_str_isalphanumeric.c \
				src/str/my_str_islower.c \
				src/str/my_str_isnum.c \
				src/str/my_str_isprintable.c \
				src/str/my_str_isupper.c \
				src/str/my_strcapitalize.c \
				src/str/my_strcmp_no_case.c \
				src/str/my_strcmp.c \
				src/str/my_strlen.c \
				src/str/my_strncmp.c \
				src/str/my_strstr.c \
				src/str/my_strupcase.c \
				src/str/my_strlowcase.c \
				src/str/take_user_input.c
SRC_BOOL	=	src/bool/get_bool.c
SRC_BINARY	=   src/binary/print_bytes.c \
				src/binary/read_bin.c \
				src/binary/write_bin.c
SRC_NCURSES = 	src/my_ncurses/utils.c

OBJ_CHAR	:= 	$(patsubst %.c,%.o,$(SRC_CHAR))
OBJ_INT_STR	:= 	$(patsubst %.c,%.o,$(SRC_INT_STR))
OBJ_ARRAYS	:= 	$(patsubst %.c,%.o,$(SRC_ARRAYS))
OBJ_MEM	 	:= 	$(patsubst %.c,%.o,$(SRC_MEM))
OBJ_STR	 	:= 	$(patsubst %.c,%.o,$(SRC_STR))
OBJ_BOOL	:= 	$(patsubst %.c,%.o,$(SRC_BOOL))
OBJ_BINARY 	:= 	$(patsubst %.c,%.o,$(SRC_BINARY))
OBJ_NCURSES	:= 	$(patsubst %.c,%.o,$(SRC_NCURSES))
OBJ 		= 	$(OBJ_CHAR) $(OBJ_INT_STR) $(OBJ_ARRAYS) $(OBJ_MEM) $(OBJ_STR) $(OBJ_BOOL) $(OBJ_BINARY) $(OBJ_NCURSES)

# ────────────────────────────────────────────────────────────
# COMPILER
# ─────────────────────────────────────────────────────────────
CC 				= 	epiclang

# ─────────────────────────────────────────────────────────────
# COMPILATION FLAGS
# ─────────────────────────────────────────────────────────────
CFLAGS_COMMON  	= 	-Wall -Wextra -Iinclude
CFLAGS_DEBUG   	= 	-g3 -O0
CFLAGS_RELEASE 	= 	-O2
CFLAGS 			= 	$(CFLAGS_COMMON) $(CFLAGS_RELEASE)

# ─────────────────────────────────────────────────────────────
# TOOLS
# ─────────────────────────────────────────────────────────────
REMOVE 		 	= 	rm -rf
RM_FILES 	 	= 	"*.gcno" "*.gcda" "*.html" "*.css" \
			   		"*.gcov" "*.log" "*.out" "*.o" "*.swp"

# ─────────────────────────────────────────────────────────────
# BUILDING RULES
# ─────────────────────────────────────────────────────────────
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# 							      BINARY BUILDING
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# 							      DEBUG BUILDING
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
debug: CFLAGS = $(CFLAGS_COMMON) $(CFLAGS_DEBUG)
debug: re

# ─────────────────────────────────────────────────────────────
# CLEANING RULES
# ─────────────────────────────────────────────────────────────
clean:
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME)
	for f in $(RM_FILES); do find . -name "$$f" -delete; done

re: fclean all

# ─────────────────────────────────────────────────────────────
# PHONY TARGETS
# ─────────────────────────────────────────────────────────────
.PHONY: all clean fclean re debug
