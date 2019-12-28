# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: kevazoul <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/08/14 11:09:21 by kevazoul     #+#   ##    ##    #+#        #
#    Updated: 2018/09/05 12:43:38 by kevazoul    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re so signature

TIME = /usr/bin/time -l # time -v on Ubuntu, time -l on OSX

ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

CC = clang -g
CPPFLAGS = -Wall -Wextra -Werror

SRCDIR = SRC/
OBJDIR = OBJ/
LFTDIR = libft
LFT = libft.a
LIBS = -L$(LFTDIR) -lft -lssl -lcrypto
INCLUDES = -I$(LFTDIR)/includes -Iincludes
SRC_NAME =	md5_main.c \
			md5_rounds.c \
			md5_transforms.c \
			ssl_process.c \
			ssl_params.c \
			ssl_originals.c \
			items_list_management.c \
			sha256_main.c \
			utils.c \
			main.c

C_FILES = $(addprefix $(SRCDIR), $(SRC_NAME))
O_FILES = $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(C_FILES)) 
H_FILE = includes/ft_ssl.h
NAME = ft_ssl

# **************************************************************************** #
#                                  RULES                                       #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LFTDIR)/$(LFT) $(OBJDIR) $(O_FILES) $(H_FILE) | signature
	$(CC) $(CPPFLAGS) -o $(NAME) $(O_FILES) $(LIBS)

$(OBJDIR):
	@mkdir $@

$(OBJDIR)%.o: $(SRCDIR)%.c $(H_FILE) | $(OBJDIR)
	@printf %b "0️⃣  $(NAME): Compiling $@ from $<..."
	$(CC) $(CPPFLAGS) -c $(INCLUDES) -o $@ $<
	@printf "\r" && printf "                                                                                             \r"

$(LFTDIR)/$(LFT):
	@make -C $(LFTDIR)

clean:
	@printf "[X] $(NAME): Deleting objects and temporary files... "
	@rm -rf $(OBJDIR)
	@printf "[V]\n"

fclean: clean
	@printf "[X] $(NAME): Deleting $(NAME)... "
	@rm -f $(NAME)
	@make -C $(LFTDIR) fclean
	@printf "[V]\n"

re: fclean all

signature:
	@echo "     .--------."
	@echo "    / .------. \\"
	@echo "   / /        \\ \\"
	@echo "   | |        | |"
	@echo "  _| |________| |_"
	@echo ".' |_|        |_| '."
	@echo "'._____ ____ _____.'"
	@echo "|     .'____'.     |"
	@echo "'.__.'.'    '.'.__.'"
	@echo "'.__  |ft_ssl|  __.'"
	@echo "|   '.'.____.'.'   |"
	@echo "'.____'.____.'____.'"
	@echo "'.________________.' by kevazoul"
	@echo ""

norminette:
	@norminette includes SRC libft/SRC libft/includes

test_md5: md5_1_file md5_2_files md5_stdin_pipe md5_str md5_str_file

test_sha256: sha256_1_file sha256_2_files sha256_stdin_pipe sha256_str sha256_str_file

test: test_md5 test_sha256

md5_1_file: all
	@echo -n "md5 1 file:\n"
	@openssl md5 ./Makefile
	@./ft_ssl md5 ./Makefile
	@echo

md5_2_files: all
	@echo -n "2 files:\n"
	@openssl md5 ./Makefile ./ft_ssl
	@./ft_ssl md5 ./Makefile ./ft_ssl
	@echo

md5_stdin_pipe:
	@echo -n "stdin pipe:\n"
	@echo -n hello | openssl md5
	@echo -n hello | ./ft_ssl md5
	@echo

md5_str:
	@echo -n "\nstring as parameter:\n"
	@echo -n "hello2" | openssl md5
	@./ft_ssl md5 -s "hello2"
	@echo

md5_str_file:
	@echo -n "\nstring and file:\n"
	@echo -n hello | openssl md5
	@openssl md5 ./Makefile
	@./ft_ssl md5 -s hello ./Makefile
	@echo

sha256_1_file: all
	@echo -n "md5 1 file:\n"
	@openssl sha256 ./Makefile
	@./ft_ssl sha256 ./Makefile
	@echo

sha256_2_files: all
	@echo -n "2 files:\n"
	@openssl sha256 ./Makefile ./ft_ssl
	@./ft_ssl sha256 ./Makefile ./ft_ssl
	@echo

sha256_stdin_pipe:
	@echo -n "stdin pipe:\n"
	@echo -n hello | openssl sha256
	@echo -n hello | ./ft_ssl sha256
	@echo

sha256_str:
	@echo -n "\nstring as parameter:\n"
	@echo -n hello | openssl sha256
	@./ft_ssl sha256 -s hello
	@echo

sha256_str_file:
	@echo -n "\nstring and file:\n"
	@echo -n hello | openssl sha256
	@openssl sha256 ./Makefile
	@./ft_ssl sha256 -s hello ./Makefile
	@echo

test_empty:
	@echo -n "\nusage:\n"
	@./ft_ssl md5
