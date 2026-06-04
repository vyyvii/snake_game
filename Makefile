##
## snake Makefile
##

# ─────────────────────────────────────────────────────────────
# NAME
# ─────────────────────────────────────────────────────────────
NAME 			= snake

# ─────────────────────────────────────────────────────────────
# SOURCE FILES AND OBJECT FILES
# ─────────────────────────────────────────────────────────────
SRC 			= 	src/snake.c
SRC_MAIN		= 	src/main.c

OBJ 			:= 	$(patsubst %.c,%.o,$(SRC))
OBJ_MAIN		:=	$(patsubst %.c,%.o,$(SRC_MAIN))

# ────────────────────────────────────────────────────────────
# COMPILER
# ─────────────────────────────────────────────────────────────
CC				= 	clang

# ─────────────────────────────────────────────────────────────
# COMPILATION FLAGS
# ─────────────────────────────────────────────────────────────
CFLAGS_COMMON  	= -Wall -Wextra -Iinclude
CFLAGS_DEBUG   	= -g3 -O0
CFLAGS_RELEASE 	= -O2
CFLAGS 			= $(CFLAGS_COMMON) $(CFLAGS_RELEASE)

# ─────────────────────────────────────────────────────────────
# LIBS
# ─────────────────────────────────────────────────────────────
LDFLAGS 		= -L./ -lUtilsLib

# ─────────────────────────────────────────────────────────────
# TOOLS
# ─────────────────────────────────────────────────────────────
REMOVE 			= rm -rf
RM_FILES 		= "*.gcno" "*.gcda" "*.html" "*.css" \
			 	  "*.gcov" "*.log" "*.out" "*.o" "*.swp"

# ─────────────────────────────────────────────────────────────
# BUILDING RULES
# ─────────────────────────────────────────────────────────────
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# 							      BINARY BUILDING
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
all: compile_lib $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# 							      DEBUG BUILDING
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
debug: CFLAGS = $(CFLAGS_COMMON) $(CFLAGS_DEBUG)
debug: re

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# 							      LIB COMPILATION
# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
compile_lib:
	cd lib && make CFLAGS="$(CFLAGS)" && cp libUtilsLib.a ../ && cd ../

# ─────────────────────────────────────────────────────────────
# CLEANING RULES
# ─────────────────────────────────────────────────────────────
clean:
	$(REMOVE) $(OBJ) $(OBJ_MAIN) $(OBJ_TEST)

fclean: clean
	$(REMOVE) $(NAME) unit_tests functional_tests libUtilsLib.a
	for f in $(RM_FILES); do find . -name "$$f" -delete; done
	cd lib && make fclean && cd ../

re: fclean all

# ─────────────────────────────────────────────────────────────
# PHONY TARGETS
# ─────────────────────────────────────────────────────────────
.PHONY: all clean fclean re unit_tests functional_tests tests_run compile_lib debug
