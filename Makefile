NAME =	fractol

SRC_DIR = srcs

SRCS =	main.c 			\
		init.c 			\
		hooks.c 		\
		mandelbrot.c 	\
		julia.c			\
		ship.c			\
		color.c

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ = $(SRCS:.c=.o)

CFLAGS = gcc -Wall -Werror -Wextra
LIBFLAGS = -L libft -lft
MLXFLAGS = -L mlx -lmlx -framework AppKit -framework OpenGL
INCLUDES = -I includes -I libft -I mlx

all : $(NAME)

$(NAME):
		@printf "\x1b[34mCompiling..\x1b[0m\n"
		@make -C libft
		@make -C mlx
		@$(CFLAGS) $(INCLUDES) -c $(SRC)
		@$(CFLAGS) $(OBJ) $(LIBFLAGS) $(MLXFLAGS) $(INCLUDES) -o $(NAME)
		@printf "\x1b[32mFractol compiled ✅ \x1b[0m\n"

clean:
		@rm -f $(OBJ)
		@make -C libft fclean
		@make -C mlx clean
		@printf "\x1b[31mclean done 🗑 \x1b[0m\n"

fclean : clean
		@rm -f $(NAME)
		@printf "\x1b[31mfclean done 🚽 \x1b[0m\n"

re : fclean all

.PHONY:		all fclean clean re