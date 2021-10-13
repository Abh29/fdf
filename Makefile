#first parts 
SRC :=	main.c  gnl/get_next_line.c gnl/get_next_line_utils.c \
		src/ft_readmap.c src/ft_tools.c src/ft_draw.c \
		src/ft_grid.c src/ft_transform.c src/ft_tools_2.c src/ft_control.c \
		src/ft_grid_2.c src/ft_draw_2.c

#bonnus 
BSRC :=	$(SRC)

CC = gcc

FLGS = -Wall -Werror -Wextra -Imlx  -g -lm
FRMWK_Linux = -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
FRMWK = -lmlx -framework OpenGL -framework AppKit
VALGFLGS = --vgdb=full --leak-check=full -s -q
FBSIZE =	-D BUFFER_SIZE=42
TARGS = test_maps/42.fdf

HEADER = fdf.h
LIBFT = libft/libft.a
MLBX = minilibx/libmlx.dylib

NAME = fdf


all :$(NAME)
	
$(NAME): $(SRC) $(HEADER) $(LIBFT)
	@echo "compiling ..."
	@$(CC) $(FLGS)  $(FBSIZE) $(SRC) $(LIBFT) -o $(NAME) -lm $(FRMWK)

bonus: $(BSRC) $(HEADER) $(LIBFT)
	@echo "compiling bonus ..."
	@rm -f $(NAME)
	@$(CC) $(FLGS) $(FBSIZE) $(BSRC) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C libft/
	@make bonus -C libft/

so:
	@echo "clreating .so file ..."
	@$(CC) -fPIC $(CFLAGS) -c $(SRC)
	@gcc -shared -o $(NAMESO) $(OBJ)


clean:
	@echo "cleaning all objects"
	@make clean -C libft/

fclean: clean
	@echo "cleaning every thing ..."
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all

test:
	@make -C libft/
	@$(CC) $(FRMWK) $(FBSIZE) $(BSRC) $(LIBFT)  -o tst -lm

debug: $(SRC) $(HEADER) $(LIBFT)
	@make debug -C libft/
	@echo "compiling with -g ..."
	@$(CC) -g $(FBSIZE) $(SRC) $(LIBFT) -o $(NAME) -lm

valgrind: $(NAME)
	@valgrind $(VALGFLGS) ./$(NAME) $(TARGS)


.PHONY: all clean fclean bonus so re test

#&.c : &.o libft.a 
