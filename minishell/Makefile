SRCS=	parsing/checkDeclar.c \
		parsing/copyquotearg.c \
		parsing/first_conv.c \
		parsing/ft_splitP.c \
		parsing/gest_quote.c \
		parsing/gest_sep.c \
		parsing/last_chance.c \
		parsing/parsing3.c \
		parsing/to_struct.c \
		parsing/trad.c \
		parsing/utils_pars.c \
		parsing/utils_pars2.c \
		parsing/utils_pars3.c \
		parsing/utils_pars4.c \
		parsing/utils_pars5.c \
		parsing/utils_pars6.c \
		parsing/utils_pars7.c \
		running/ms_builtins_0.c \
		running/ms_builtins_1.c \
		running/ms_builtins_2.c \
		running/ms_builtins_3.c \
		running/ms_builtins_4.c \
		running/ms_builtins_5.c \
		running/ms_run.c \
		running/run_utils_0.c \
		running/run_utils_1.c \
		running/run_utils_2.c \
		running/run_utils_3.c \
		running/run_utils_4.c \
		libft2/ft_str_begin.c \
		libft2/ft_strend.c \
		libft2/get_next_line_utils.c \
		libft2/get_next_line.c \
		main2.c

OBJS= ${SRCS:.c=.o}

NAME= minishell

%.o : %.c minishell.h parsing/util.h running/ms_run.h running/ms_builtins.h libft2/get_next_line.h
	gcc -c -Wall -Wextra -Werror $< -o $@

$(NAME): $(OBJS)
		$(MAKE) -C ./libft
		gcc -Wall -Wextra -Werror -o $(NAME) $(OBJS) libft/libft.a

all: $(NAME)

clean :
	rm -rf $(OBJS)
	$(MAKE) clean -C ./libft

fclean :	clean
	rm -rf $(NAME)

re: fclean all

.PHONY:	all fclean clean re