NAME     = fractol
CC       = cc
CFLAGS   = -Wall -Wextra -Werror -g -Iinclude -I$(MLX42_DIR)/include

MLX42_DIR = MLX42
MLX       = -L$(MLX42_DIR)/build -lmlx42 -ldl -lglfw -lGL -pthread -lm

LIBFTDIR  = libft
LIBFT     = $(LIBFTDIR)/libft.a

SRC = src/main.c src/utils.c src/mandelbrot.c src/julia.c src/draw_fractal.c \
      src/display.c src/display_info.c src/key_handlers.c src/fractol_init.c \
      src/mouse_handler.c src/color.c src/hooks.c src/key_helpers.c \
      src/render.c src/render_utils.c src/fractal_math.c \
	  src/init_fractals.c src/init_image.c \
	  src/init_utils.c src/cleanup.c \
	  src/color_utils.c src/pixel_utils.c \
	  src/zoom.c src/ft_display_helpers.c src/ft_atof.c \
	  src/ft_display_helpers_utils.c src/ft_display_helpers_float.c

OBJ = $(SRC:.c=.o)

all: $(MLX42_DIR)/build/libmlx42.a $(LIBFT) $(NAME)

$(MLX42_DIR)/build/libmlx42.a:
	@cmake -B $(MLX42_DIR)/build -S $(MLX42_DIR)
	@cmake --build $(MLX42_DIR)/build

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(MLX)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFTDIR) clean
	@rm -rf $(MLX42_DIR)/build

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

FRACTAL ?= MANDELBROT

run: $(NAME)
	./$(NAME) $(shell echo $(FRACTAL) | tr '[:upper:]' '[:lower:]')

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
		./$(NAME) $(shell echo $(FRACTAL) | tr '[:upper:]' '[:lower:]')

.PHONY: all clean fclean re
