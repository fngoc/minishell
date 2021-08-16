.PHONY: all clean bonus fclean re run

NAME = minishell

HEADER = minishell.h

LIBFT_DIR = libft/

LIBFT = $(LIBFT_DIR)libft.a

MAKEB = make bonus

MAKEC = make clean

CLEAN = clean

FCLEAN = fclean

SRC = main.c \
	\
	parser/parser.c \
	parser/quotation_mark_found.c \
	parser/quotation_mark_not_found.c \
	parser/after_reading_line.c \
	parser/signals.c \
	parser/parser_commands.c \
	parser/init.c \
	parser/history/make_file.c \
	parser/history/get_history.c \
	parser/history/set_line.c \
	parser/checks/checking_quotes.c \
	parser/checks/privacy_check.c \
	parser/checks/check_buffer.c \
	parser/checks/check_echo_flag_n.c \
	parser/checks/fd_check.c \
	parser/utils/is_arrow.c \
	parser/utils/ft_istab.c \
	parser/utils/ft_strjoin_free_free.c \
	parser/utils/ft_strjoin_fix.c \
	parser/utils/ft_strjoin_char_free.c \
	parser/utils/ft_strcmp.c \
	parser/utils/ft_putchar.c \
	parser/utils/free_map.c \
	parser/utils/error.c \
	parser/utils/delet_last_char.c \
	parser/utils/delet_first.c \
	parser/utils/parser_utils_one.c \
	parser/utils/parser_utils_two.c \
	parser/utils/skipping_more_spaces.c \
	parser/sends/send_question_mark.c \
	parser/sends/send_exit.c \
	parser/sends/send_exec.c \
	parser/sends/send_env.c \
	parser/sends/send_echo.c \
	parser/sends/send_command_execute.c \
	parser/redirect/what_is_redir.c \
	parser/redirect/parser_redir.c \
	parser/redirect/set_redir_map.c \
	parser/redirect/checking_folder.c \
	parser/echo/without_quotation_marks.c \
	parser/echo/single_quote.c \
	parser/echo/ft_echo.c \
	parser/echo/double_quote.c \
	parser/echo/parser_echo.c \
	parser/echo/write_cycle.c \
	parser/echo/double_echo_n_check_start.c \
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
	logic/utils/arr_size.c \
	logic/pipe_process.c \
	logic/utils/print_promt.c \
	logic/utils/set_error.c \
	logic/utils/cd_utils.c \
	logic/utils/execve_utils.c \
	logic/utils/get_pipe_fd.c \
	logic/execve_error.c \
	logic/utils/export_utils.c \

OBJ = $(SRC:.c=.o)

CC = gcc

FLAG = -Wall -Werror -Wextra

OPTIONOBJ = -o

DEL = rm -rf

GREEN ='\033[1;32m'

WHITE ='\033[0;37m'

YELLOW ='\033[1;33m'

CYAN ='\033[1;36m'

MAGENTA ='\033[1;35m'

all: $(NAME)

$(NAME): $(HEADER) $(SRC)
	@cd $(LIBFT_DIR) && $(MAKEB)
	@echo ${GREEN}"libft is assembled!"$(WHITE)
	@cd $(LIBFT_DIR) && mv ./libft.a ../
	@cd $(LIBFT_DIR) && $(MAKEC)
	@$(CC) $(FLAG) $(SRC) libft.a -ltermcap $(OPTIONOBJ) $(NAME)
	@echo $(GREEN)"You can run!"$(WHITE)	

%.o: %.c $(HEADER)
	$(CC) $(FLAG) $< $(OPTIONOBJ) $@

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
