NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror
CC = cc

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
LIB_DIR = libft

FILE = ft_printf ft_printstr ft_printint ft_printuint ft_printhex ft_printptr \
		convert_int convert_hex convert_uint convert_ptr

OBJ = $(addprefix $(OBJ_DIR)/, $(FILE:%=%.o))

LIBFT = $(LIB_DIR)/libft.a

.PHONY: all clean fclean re

all: $(OBJ_DIR) $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $@
	ar -rc $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(LIBFT): 
	@make -C $(LIB_DIR) all

$(OBJ_DIR):
	@mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIB_DIR) clean

fclean: clean
	rm -rf $(NAME)
	@make -C $(LIB_DIR) fclean

re: fclean all
