#first parts 
SRC :=	main.c  gnl/get_next_line.c gnl/get_next_line_utils.c \
		src/ft_readmap.c src/ft_tools.c src/ft_print.c src/ft_draw.c \
		src/ft_pointmap.c src/ft_transform.c

#bonnus 
BSRC :=	$(SRC)

CC = gcc

FLGS = -Wall -Werror -Wextra  -g -lm
FRMWK = -Lmlx -lmlx -framework OpenGL -framework AppKit
VALGFLGS = --vgdb=full --leak-check=full -s -q
FBSIZE =	-D BUFFER_SIZE=42
TARGS = test_maps/julia.fdf

HEADER = fdf.h
LIBFT = libft/libft.a
MLBX = minilibx/libmlx.dylib

NAME = fdf


all :$(NAME)
	
$(NAME): $(SRC) $(HEADER) $(LIBFT)
	@echo "compiling ..."
	@$(CC) $(FLGS) $(FRMWK) $(FBSIZE) $(SRC) $(LIBFT) -o $(NAME)

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

valgrind: debug
	@valgrind $(VALGFLGS) ./$(NAME) $(TARGS)


.PHONY: all clean fclean bonus so re test

#&.c : &.o libft.a 