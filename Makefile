OBJS 	= $(SRCS:.c=.o)

NAME	= push_swap
LIBFT	= libft
INC		= includes

RM 		= rm -f
CC		= clang
CFLAGS	= -Wall -Wextra -Werror -g -I. -I$(LIBFT)/includes

all: $(NAME)

$(NAME): $(LIBFT).a $(OBJS)
	$(CC) $(CFLAGS) -L. -lft main.c -o $(NAME)

$(LIBFT).a:
	$(MAKE) -C $(LIBFT)
	mv $(LIBFT)/$(LIBFT).a .

clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)
	$(RM) $(LIBFT).a
	$(RM) -r $(NAME).dSYM

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME)
