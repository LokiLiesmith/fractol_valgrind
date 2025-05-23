# Detect OS
UNAME_S := $(shell uname -s)

# Paths
MLX_DIR       := include/minilibx
LIBFT_PATH    := include/libft

# Repos
MLX_REPO := https://github.com/LokiLiesmith/minilibx.git
MLX_REPO_LINUX := https://github.com/42paris/minilibx-linux.git

ifeq ($(UNAME_S),Linux)
	MLX_REPO = $(MLX_REPO_LINUX)
endif

# Compiler + flags
CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -I include -I $(MLX_DIR)

# Libraries
LIBFT_LIB := $(LIBFT_PATH)/libft.a
MLX_LIB   := $(MLX_DIR)/libmlx.a

# Source & objects
SRC     := $(wildcard src/*.c)
OBJDIR  := obj
OBJ     := $(patsubst src/%.c,$(OBJDIR)/%.o,$(SRC))

NAME  := fractol

# Main target
all: $(LIBFT_LIB) $(MLX_LIB) $(NAME)

# Build libft
$(LIBFT_LIB):
	@$(MAKE) -s -C $(LIBFT_PATH)
#Build MiniLibX
$(MLX_LIB):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "MiniLibX directory missing, cloning…"; \
		git clone  --depth 1 $(MLX_REPO) $(MLX_DIR); \
		echo "Building MiniLibX"; \
		make -s -C $(MLX_DIR); \
	elif [ ! -f "$(MLX_LIB)" ]; then \
		echo "$(BGreen)libmlx.a missing, rebuilding MiniLibX...$(Color_Off)"; \
		make -s -C $(MLX_DIR);	\
	else \
		echo "$(BGreen)MiniLibX up to date$(Color_Off)"; \
	fi;

# Choose the flags
ifeq ($(UNAME_S),Linux)
  MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
else ifeq ($(UNAME_S),Darwin)
  MLX_FLAGS = -L$(MLX_DIR) -lmlx \
              -framework OpenGL \
              -framework AppKit \
              -lm
endif

# Link fractol
$(NAME): $(OBJ) $(LIBFT_LIB) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(OBJ) \
	      -L$(LIBFT_PATH) -lft \
	      $(MLX_FLAGS) \
	      -o $(NAME)

# Compile .c → .o
$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Ensure obj dir
$(OBJDIR):
	mkdir -p $(OBJDIR)

VG_FLAGS  := --leak-check=full \
             --show-leak-kinds=all \
             --track-origins=yes \
             --error-exitcode=1

valgrind: all
	@$(MAKE) CFLAGS="$(CFLAGS) -g" all

# Clean rules
clean:
	-$(MAKE) -C $(MLX_DIR) clean
	-$(MAKE) -C $(LIBFT_PATH) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)
	rm -rf $(MLX_DIR)

re: fclean all

# san: CFLAGS += -fsanitize=address -fno-omit-frame-pointer -g
san: CFLAGS += -fsanitize=address -g -static-libsan  -Wunused
san: fclean all

.PHONY: all clean fclean re