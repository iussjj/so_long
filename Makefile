NAME	= so_long

CFLAGS	= -Wextra -Wall -Werror

LIBMLX	= ./lib/MLX42
LIBFT	= ./lib/libft

HEADERS	= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
LIBS	= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -pthread -lm

SRCS	=	./src/main.c \
			./src/initialize_data.c \
			./src/validate_map.c \
			./src/graphics.c \
			./src/user_input.c \
			./src/clean_exit.c \

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(LIBMLX)/build/libmlx42.a:
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	@$(MAKE) -C $(LIBMLX)/build

$(LIBFT)/libft.a:
	@$(MAKE) -C $(LIBFT)

$(NAME): $(OBJS) $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re