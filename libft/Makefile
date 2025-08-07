NAME = libft.a

COMPILER = cc

COMPILERFLAGS = -Wall -Wextra -Werror

SRCS =	ft_atoi.c	\
		ft_bzero.c	\
		ft_calloc.c	\
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_itoa.c	\
		ft_memchr.c	\
		ft_memcmp.c	\
		ft_memcpy.c	\
		ft_memmove.c	\
		ft_memset.c	\
		ft_putchar_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_putstr_fd.c 	\
		ft_split.c	\
		ft_strchr.c	\
		ft_strdup.c	\
		ft_striteri.c\
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c	\
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c	\
		ft_tolower.c \
		ft_toupper.c \
		ft_gnl.c \
		ft_gnl_linelen.c


#converts .c files into .o object files
OBJS = $(SRCS:.c=.o)

#builds $(NAME)
all: $(NAME)


#Library creation rule: builds static library from object files
#ar create archivce, r replace/insert files into archive
# c create archive if !exists, s add index for faster linking
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

#Object file compilation rule
#% wildcard, $< automatic variable for source file (??)
%.o: %.c
	$(COMPILER) $(COMPILERFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

#rebuilds by running fclean, then all
re: fclean all

#phony declaration: specifies that targets are not files
#this avoids conflicts, if target names are also filenames
.PHONY: all clean fclean re
