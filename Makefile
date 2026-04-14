NAME		= libasm

LIB			= libasm.a

SRCS		=	ft_strlen.s	\
				ft_strcpy.s	\
				ft_write.s	\
				ft_strcmp.s	\
				ft_read.s

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

NASM		= nasm
NASM_FLAGS	= -f elf64

OBJ = $(SRCS:.s=.o)

%.o : %.s
	$(NASM) $(NASM_FLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(LIB) $(OBJ)

link:
	$(CC) $(CFLAGS) main.c $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)
	rm -f ./a.out

re: fclean all
