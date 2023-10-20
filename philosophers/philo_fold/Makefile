PHILO_BONUS = philo_bonus

SRCS = philo_bonus.c functions.c functions2.c utils.c check.c utils2.c utils3.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3

RM = rm -f

%.o : %.c philo_bonus.h
	${CC} ${FLAGS} -c $< -o $@

all: ${PHILO_BONUS}

${PHILO_BONUS}: ${OBJS} philo_bonus.h
			${CC} -o ${PHILO_BONUS} ${CFLAGS} ${OBJS}

clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${PHILO_BONUS}

re:	fclean

.PHONY :	all fclean clean re