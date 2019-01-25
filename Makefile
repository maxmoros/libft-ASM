NAME = libfts.a
CFLAGS = -f 
LFLAGS = ar rc
CC = nasm

ODIR = .objects
SDIR = srcs

SRC =	\
		ft_bzero.s

OBJS = $(patsubst %.s, $(ODIR)/%.o, $(SRC))

PREFIX =

ifeq ($(shell uname -s), Darwin)
		CFLAGS += macho64
		PREFIX = --prefix _ -dOSX=1
else
		echo "Built for OSX system. Closing Makefile..."
endif

all: $(NAME)

$(NAME): $(ODIR) $(OBJS)
		$(LFLAGS) $(NAME) $(OBJS)

$(ODIR)/%.o: $(addprefix $(SDIR)/, %.s)
		$(CC) $(CFLAGS) -o $@ $(PREFIX) $^
	
$(ODIR):
		mkdir -p $(ODIR)

fclean: clean
		rm -rf $(ODIR)
		rm -rf $(NAME)

clean:
		rm -rf $(OBJS) test

re: fclean all

