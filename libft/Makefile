# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/08/14 11:09:21 by amatthys     #+#   ##    ##    #+#        #
#    Updated: 2018/09/05 12:43:38 by jmonneri    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

include ./utils/colors.mk
.PHONY: all clean fclean re so signature
NAME = libft.a

CC = clang -g
CPPFLAGS = -Wall -Wextra -Werror -c

SRCDIR = SRC/
OBJDIR = OBJ/
INCLUDES = includes/
SRC_NAME =	ft_abs.c \
		ft_absdiff.c \
		ft_append_char.c \
		ft_atof.c \
		ft_get_txtfile.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_error.c \
		ft_fact.c \
		ft_free_grid.c \
		ft_free_ret.c \
		ft_free_strs.c \
		ft_get_fd_content.c \
		ft_getchar_pos.c \
		ft_indexof.c \
		ft_isalldigit.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isascii.c \
		ft_isgraph.c \
		ft_islower.c \
		ft_isprime.c \
		ft_isprint.c \
		ft_ispunct.c \
		ft_isspace.c \
		ft_isupper.c \
		ft_isxdigit.c \
		ft_iter.c \
		ft_itoa.c \
		ft_itoa_base.c \
		ft_lstadd.c \
		ft_lstappend.c \
		ft_lstat.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstdelval.c \
		ft_lstfind.c \
		ft_lstiter.c \
		ft_lstiterif.c \
		ft_lstlast.c \
		ft_lstlen.c \
		ft_lstmap.c \
		ft_lstmerge.c \
		ft_lstnew.c \
		ft_lstpushparams.c \
		ft_lstrev.c \
		ft_lstsize.c \
		ft_lstsort.c \
		ft_lsttostr.c \
		ft_memalloc.c \
		ft_memcatdup.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memclear.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memrev.c \
		ft_memset.c \
		ft_new_grid.c \
		ft_pow.c \
		ft_powf.c \
		ft_prepend_char.c \
		ft_prepend_wchar_t.c \
		ft_print_grid.c \
		ft_printf.c \
		ft_ptrarrlen.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_base.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_putwstr.c \
		ft_realloc.c \
		ft_replace_str.c \
		ft_replace_wstr.c \
		ft_strsplit.c \
		ft_sqrt.c \
		ft_split.c \
		ft_str_merge.c \
		ft_strcat.c \
		ft_strcatdup.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strndup.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strpop.c \
		ft_strrchr.c \
		ft_strrev.c \
		ft_strset.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtolst.c \
		ft_strtoupper.c \
		ft_strtowstr.c \
		ft_strtrim.c \
		ft_strtrimc.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_uitoa_base.c \
		ft_watoi.c \
		ft_wctomb.c \
		ft_wordscount.c \
		ft_wstrcat.c \
		ft_wstrcatdup.c \
		ft_wstrchr.c \
		ft_wstrcpy.c \
		ft_wstrdup.c \
		ft_wstrlen.c \
		ft_wstrncpy.c \
		ft_wstrndup.c \
		ft_wstrpop.c \
		ft_wstrtoupper.c \
		get_next_line.c \
		pf_append_patt.c \
		pf_bonus_b.c \
		pf_build_patt.c \
		pf_chars.c \
		pf_ispatt.c \
		pf_main_printf.c \
		pf_numbers.c \
		pf_str_merge_to_next_patt.c \
		pf_strings.c \
		pf_utils.c


C_FILES = $(addprefix $(SRCDIR), $(SRC_NAME))
O_FILES = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(C_FILES)) 
H_FILE = includes/libft.h
LIB_BUILD_FLAGS = 
PROJECT = libft
SNAME = libft.so
SYS = $(shell uname -s)

#ifeq ($(SYS), Linux)
CPPFLAGS += -fPIC -g
LIB_BUILD_FLAGS += -shared -o
SNAME = $(addsuffix .a, $(PROJECT))
NAME = $(addsuffix .so, $(PROJECT))
LIB_BUILDER = $(CC)
#else
#	LIB_BUILD_FLAGS += rcs
#	NAME = $(addsuffix .a, $(PROJECT))
#	SNAME = $(addsuffix .so, $(PROJECT))
#	LIB_BUILDER = ar
#endif

# **************************************************************************** #
#                                  RULES                                       #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJDIR) $(O_FILES)
	@$(LIB_BUILDER) $(LIB_BUILD_FLAGS) $(NAME) $(O_FILES)
	@make signature

$(OBJDIR):
	@mkdir $@

$(OBJDIR)%.o: $(SRCDIR)%.c $(H_FILE) | $(OBJDIR)
	@printf %b "0️⃣  $(PROJECT): Compiling $@ from $<..."
	@$(CC) $(CPPFLAGS) -I$(INCLUDES) -o $@ $<
	@printf "\r" && printf "                                                                                             \r"

clean:
	@printf "$(TRED)[X]$(NORMAL) $(PROJECT): Deleting objects and temporary files... "
	@rm -rf $(OBJDIR)
	@printf "$(TGREEN)[V]$(NORMAL)\n"

fclean: clean
	@printf "$(TRED)[X]$(NORMAL) $(NAME): Deleting $(NAME)... "
	@rm -f $(NAME) $(SNAME)
	@printf "$(TGREEN)[V]$(NORMAL)\n"

re: fclean all

signature:
	@echo ""
	@echo "   ██╗     ██╗██████╗ ███████╗████████╗TM"
	@echo "   ██║     ██║██╔══██╗██╔════╝╚══██╔══╝"
	@echo "   ██║     ██║██████╔╝█████╗     ██║"
	@echo "   ██║     ██║██╔══██╗██╔══╝     ██║"
	@echo "   ███████╗██║██████╔╝██║        ██║"
	@echo "   ╚══════╝╚═╝╚═════╝ ╚═╝        ╚═╝"
	@echo ""

test: all
	cat tests/ft_malloc_test.c | sed s/ft_malloc/malloc/g | sed s/ft_free/free/g > tests/ref.c
	clang -g tests/ft_malloc_test.c -I./includes/ -L. -lft
	clang -g -o ref tests/ref.c -I./includes/ -L. -lft
	valgrind --leak-check=full --show-leak-kinds=all ./a.out
	# see man time
	@echo "Ref:"
	tests/run.sh time -l ./ref
	@echo "\nKevazoul:"
	test/run.sh time -l ./a.out