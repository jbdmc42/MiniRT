NAME        = miniRT

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
LDFLAGS     = -lm -lXext -lX11 -lz

LIBFT_DIR   = include/libft
LIBFT_A     = $(LIBFT_DIR)/libft.a

MLX_DIR     = include/minilibx
MLX_A       = $(MLX_DIR)/libmlx.a

INCLUDES    = -I./include -I$(LIBFT_DIR) -I$(MLX_DIR)

SRCS        = src/main.c \
			src/input_validation/extension.c
			src/program_execution/initialization.c
			src/program_execution/window.c

OBJS        = $(SRCS:.c=.o)


all: $(LIBFT_A) $(MLX_A) $(NAME)
	@printf "\n\033[1;32m✓ MiniRT build successful!\033[0m\n\n"


$(LIBFT_A):
	@printf "\033[1;34m[1/3]\033[0m Building Libft...\n"
	@$(MAKE) -s -C $(LIBFT_DIR)
	@printf "\033[1;32m✓ Libft complete\033[0m\n\n"


$(MLX_A):
	@printf "\033[1;34m[2/3]\033[0m Building MiniLibX...\n"
	@$(MAKE) -s -C $(MLX_DIR)
	@printf "\033[1;32m✓ MiniLibX complete\033[0m\n\n"


$(NAME): $(OBJS)
	@printf "\033[1;34m[3/3]\033[0m Building MiniRT...\n"
	@$(CC) $(OBJS) $(LIBFT_A) $(MLX_A) $(LDFLAGS) -o $(NAME)
	@printf "\033[1;32m✓ MiniRT complete\033[0m\n\n"


%.o: %.c include/minirt.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
	@printf "\033[1;33mCleaning object files...\033[0m\n"
	@rm -f $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(MLX_DIR) clean
	@printf "\033[1;32m✓ Clean complete\033[0m\n"


fclean: clean
	@printf "\033[1;33mRemoving executable and libraries...\033[0m\n"
	@rm -f $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@printf "\033[1;32m✓ Full clean complete\033[0m\n"


re: fclean all


valgrind:
	@echo "{\n   leak readline\n   Memcheck\:Leak\n...\n   fun\:readline\n}\n{\n   leak add_history\n   Memcheck\:Leak\n...\n   fun\:add_history\n}" > readline.supp
	@valgrind --suppressions=readline.supp --leak-check=full -s ./$(NAME)


.PHONY: all clean fclean re valgrind