SRCS =	push_swap_fold/sort.c \
		push_swap_fold/utils_sort.c \
		push_swap_fold/utils_sort2.c \
		push_swap_fold/sort_5el.c \
		push_swap_fold/utils_ps.c \
		checker_fold/check.c \
		checker_fold/check2.c \
		checker_fold/get_next_line.c \
		utils/add.c \
		utils/utils3.c \
		utils/utils.c \
		utils/utils2.c \
		functions/def_functions.c \
		functions/def_functions2.c \
		functions/def_functions3.c \
		functions/def_functions4.c \

CHECKER_FILE = checker_fold/checker.c
PUSH_SWAP_FILE = push_swap_fold/push_swap.c

CHECKER = checker
PUSH_SWAP = push_swap

OBJS = ${SRCS:.c=.o}

OBJS2 = ${CHECKER_FILE:.c=.o}

OBJS3 = ${PUSH_SWAP_FILE:.c=.o}

CC = gcc

INCLUDES = includes/

CFLAGS = -Wall -Wextra -Werror

%.o : %.c libft.h
	${CC} ${CFLAGS} -c $< -o $@

${PUSH_SWAP}: ${OBJS} ${OBJS3} libft/libft.h
	${CC} -o ${PUSH_SWAP} ${CFLAGS} ${OBJS3} ${OBJS} libft/libft.a

${CHECKER}: ${OBJS} ${OBJS2} libft/libft.h
	${CC} -o ${CHECKER} ${CFLAGS} ${OBJS2} ${OBJS} libft/libft.a

all: ${PUSH_SWAP}

clean:
	${RM} ${OBJS} ${OBJS2} ${OBJS3}
fclean: clean
	${RM} ${PUSH_SWAP} ${CHECKER}

re:	fclean all