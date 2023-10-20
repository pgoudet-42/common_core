LIBFT		=		./libft/libft.a
NAME		=		libftprintf.a
SRCS		=		adresse.c char.c ft_printf.c string.c utils.c utils_bis.c utils_quater.c \
utils_ter.c int.c utils_quinquies.c utils_sexies.c u.c x.c prct.c error.c
		
OBJS		=		${SRCS:.c=.o}
CC			=		gcc
FLAGS		=		-c -Wall -Wextra -Werror
%.o : %.c ft_printf.h
	${CC} ${FLAGS} $< -o $@
$(NAME) : 	$(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(SRCS)
	ar -rcs $(NAME) $(OBJS)
all :		$(NAME)
clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)
fclean :	clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
re :		fclean all
.PHONY :	all fclean clean re