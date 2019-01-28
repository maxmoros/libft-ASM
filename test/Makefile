NAME = testrunner

CC = gcc
CFLAGS += -Wall -Wextra -Wno-unused-function -pedantic -I../inc -g
LDFLAGS += -L..
LDLIBS += -lfts

OBJ = $(NAME).o \
	  test_ft_bzero.o \
	  test_ft_strcat.o \
	  test_ft_isalpha.o \
	  test_ft_isdigit.o \
	  test_ft_isalnum.o \
	  test_ft_isascii.o \
	  test_ft_isprint.o \
	  test_ft_toupper.o \
	  test_ft_tolower.o \
	  test_ft_puts.o \
	  test_ft_strlen.o \
	  test_ft_memset.o \
	  test_ft_memcpy.o \
	  test_ft_strdup.o \
	  test_ft_cat.o \

all: $(NAME)

$(NAME): $(OBJ) ../libfts.a

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
