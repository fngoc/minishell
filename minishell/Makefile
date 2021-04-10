.PHONY: all clean bonus fclean re run

NAME = minishell

HEADERS = logic/logic.h \
		parser/parser.h

LIBFT_DIR = libft/

LIBFT = $(LIBFT_DIR)libft.a

MAKEB = make bonus

CLEAN = clean

FCLEAN = fclean

SRC = main.c \
	\
	parser/parser.c \
	parser/utils/check_command.c \
	parser/utils/error.c \
	parser/utils/ft_putchar.c \
	parser/utils/init.c \
	parser/utils/make_file.c \
	parser/utils/ft_strcmp.c \
	parser/utils/set_line.c \
	parser/utils/delet_last_char.c \
	parser/utils/is_arrow.c \
	parser/utils/ft_istab.c \
	parser/utils/free_map.c \
	parser/utils/ft_strjoin_char_free.c \
	parser/utils/get_history.c \
	parser/utils/check_buffer.c \
	parser/utils/send_command_execute.c \
	parser/utils/privacy_check.c \
	parser/utils/checking_quotes.c \
	\
	logic/execve_command.c \
	logic/utils/free_lst.c \
	logic/utils/list_copy.c \
	logic/export_var.c \
	logic/unset_var.c \
	logic/env.c \
	logic/export.c \
	logic/cd.c \
	logic/pwd.c \
	logic/init_env_copy.c \
	logic/find_env_var.c \
	logic/ft_echo.c \
	logic/errors/error.c \
	logic/utils/arr_size.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAG = -Wall -Werror -Wextra -g

OPTIONOBJ = -o

DEL = rm -rf

GREEN ='\033[1;32m'

WHITE ='\033[0;37m'

YELLOW ='\033[1;33m'

CYAN ='\033[1;36m'

MAGENTA ='\033[1;35m'

all: $(NAME)

$(NAME): $(LIBFT) 
	@cd $(LIBFT_DIR) && mv ./libft.a ../
	@$(CC) $(FLAG) $(SRC) libft.a -ltermcap $(OPTIONOBJ) $(NAME)
	@echo $(GREEN)"You can run!"$(WHITE)

$(LIBFT):
	@cd $(LIBFT_DIR) && $(MAKEB)
	@echo ${GREEN}"libft is assembled!"$(WHITE)

%.o: %.c
	@$(CC) $(FLAG) $< $(OPTIONOBJ) $@

clean:
	@$(DEL) $(OBJ)
	@cd $(LIBFT_DIR) && $(MAKEB) $(CLEAN)
	@echo $(GREEN)"All 'o' files deleted."$(WHITE)

fclean: clean
	@$(DEL) $(OBJ)
	@$(DEL) libft.a
	@$(DEL) $(NAME)
	@cd $(LIBFT_DIR) && $(MAKEB) $(FCLEAN)
	@$(DEL) minishell_history
	@echo $(GREEN)"Everything was cleaned up along with the library."$(WHITE)

run: $(NAME)
	@./minishell

re: fclean all
