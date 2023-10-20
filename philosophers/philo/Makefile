PHILO = philo
PHILO_BONUS = philo_bonus

SRCS = philo.c functions.c functions2.c utils.c check.c utils2.c utils3.c function3.c take_fork.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3

RM = rm -f

%.o : %.c philo.h
	${CC} ${FLAGS} -c $< -o $@

all: ${PHILO}

${PHILO}: ${OBJS} philo.h
			${CC} -o ${PHILO} ${CFLAGS} ${OBJS}


clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${PHILO}

re:	fclean

.PHONY :	all fclean clean re