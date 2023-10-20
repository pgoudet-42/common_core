NAME = ft_containers

NAME1 = ft_containers1

SRCS =	main2.cpp

SRCS1 = main.cpp

HEADER = srcs/map/map.hpp srcs/map/map_iterators.hpp srcs/map/reverse_map_iterator.hpp \
				 srcs/stack/stack.hpp srcs/templates/templates.hpp srcs/templates/type.hpp \
				 srcs/vector/random_iterators.hpp srcs/vector/reverse_iterators.hpp srcs/vector/vector.hpp

GCCF = clang++ -Wall -Wextra -Werror -std=c++98

OBJS = ${SRCS:.cpp=.o}

OBJS1 = ${SRCS1:.cpp=.o}

.PHONY :	all clean fclean re

%.o :		%.cpp $(HEADER)
			@mkdir -p $(dir $@)
			${GCCF} -c $< -o $@ -Iinclude

all :		${NAME}

$(NAME) :	${OBJS} $(HEADER)
			${GCCF} $(OBJS) -Iinclude -o $(NAME)

$(NAME1) :	${OBJS1}
			${GCCF} $(OBJS1) -Iinclude -o $(NAME1)

clean :
			rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME} ${NAME1} a.out

re :		fclean all