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

TEST_DIR = $(HOME)/Malloc_tests
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
INCLUDES = -I$(LFTDIR)/includes -Iincludes
SRC_NAME =	ft_md5.c \
			ft_ssl_process.c \
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
	$(CC) $(CPPFLAGS) -o $(NAME) $(O_FILES) -L$(LFTDIR) -lft

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
	@norminette includes SRC
