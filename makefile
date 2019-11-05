NAME=libftasm.a
BUILDIR=./build
SRCDIR=./src/
ARCH=macho64
SRCS=	ft_islower.s ft_isupper.s ft_isalpha.s \
		ft_isdigit.s ft_isalnum.s ft_isascii.s \
		ft_isprint.s ft_toupper.s ft_tolower.s \
		ft_memset.s ft_bzero.s ft_strlen.s

OBJS=$(SRCS:%.s=$(BUILDIR)/%.o)

all: $(NAME)

$(BUILDIR):
	mkdir -p $(BUILDIR)

list:
	@echo $(OBJS)

$(BUILDIR)/%.o: $(SRCDIR)%.s
	nasm -f $(ARCH) $< -o $@

$(NAME): $(BUILDIR) $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) -r $(BUILDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: $(NAME)
	clang -Wall -Werror -Wextra main.c -o test -L. -lftasm -I.
