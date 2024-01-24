NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror
CC = cc

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

FILE = ft_printf ft_printstr ft_printint ft_printuint ft_printhex ft_printptr \
		convert_int convert_hex convert_uint convert_ptr ft_printf_utils

OBJ = $(addprefix $(OBJ_DIR)/, $(FILE:%=%.o))

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	ar -rc $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
