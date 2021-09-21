#first parts 
SRC :=	ft_memset.c		ft_bzero.c		ft_memcpy.c		\
		ft_memccpy.c	ft_memmove.c	ft_memchr.c 	\
		ft_memcmp.c		ft_strlen.c 	ft_strlcpy.c 	\
		ft_strlcat.c 	ft_strchr.c 	ft_strrchr.c 	\
		ft_strnstr.c 	ft_strncmp.c 	ft_atoi.c 		\
		ft_isalpha.c 	ft_isdigit.c 	ft_isalnum.c 	\
		ft_isascii.c 	ft_isprint.c 	ft_toupper.c 	\
		ft_tolower.c 	ft_calloc.c 	ft_strdup.c 	\
		ft_substr.c 	ft_strjoin.c 	ft_strtrim.c 	\
		ft_split.c		ft_itoa.c 		ft_strmapi.c 	\
		ft_putchar_fd.c ft_putstr_fd.c 	ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c 	ft_lstadd_front.c 	ft_lstsize.c 	\
		ft_lstlast.c 	ft_lstadd_back.c 	ft_lstdelone.c 	\
		ft_lstclear.c	ft_lstiter.c		ft_lstmap.c

#bonnus 
BSRC := ft_lstnew.c 	ft_lstadd_front.c 	ft_lstsize.c 	\
		ft_lstlast.c 	ft_lstadd_back.c 	ft_lstdelone.c 	\
		ft_lstclear.c	ft_lstiter.c		ft_lstmap.c		\
		ft_putptr_fd_bonus.c			ft_hex_digit_bonus.c \
		ft_putnbr_fd_size_bonus.c		ft_putnbr_base_fd_size_bonus.c\
		ft_putptr_fd_size_bonus.c		ft_putnbr_unsigned_fd_size_bonus.c\
		ft_putstr_fd_size_bonus.c 		ft_putlnbr_fd_size_bonus.c \
		ft_putlnbr_fd_bonus.c 			ft_putdbl_fd_size_bonus.c \
		ft_putdbl_fd_bonus.c 			ft_putchar_fd_size_bonus.c\
		ft_putnbr_base_fd_bonus.c		ft_putnbr_unsigned_fd_bonus.c \
		ft_atol.c


OBJ := ${SRC:%.c=%.o}

BOBJ := $(BSRC:%.c=%.o)

CC = gcc

FLGS = -Wall -Werror -Wextra

HEADER = libft.h

NAME = libft.a
NAMESO = libft.so


%.o : %.c
	@echo "compiling ..."
	$(CC) $(FLGS) -c $<

all :$(NAME)
	
$(NAME): $(OBJ)
	@echo "linking ..."
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

bonus: $(BOBJ)
	@echo "linking with bonus ..."
	@ar rc $(NAME) $(BOBJ)
	@ranlib $(NAME)

so:
	@echo "clreating .so file ..."
	@$(CC) -fPIC $(CFLAGS) -c $(SRC)
	@gcc -shared -o $(NAMESO) $(OBJ)


clean:
	@echo "cleaning all objects"
	@rm -f $(OBJ)
	@rm -f $(BOBJ)

fclean: clean
	@echo "cleaning every thing ..."
	@rm -f $(NAME)
	@rm -f $(NAMESO)

debug: $(SRC) $(BSRC) fclean
	@echo "compiling with -g ..."
	@$(CC) $(FLGS) -c -g $(SRC)
	@$(CC) $(FLGS) -c -g $(BSRC)
	@echo "linking ..."
	@ar rc $(NAME) *.o
	@ranlib $(NAME)

re: fclean all

.PHONY: all clean fclean bonus so re

#&.c : &.o libft.a 