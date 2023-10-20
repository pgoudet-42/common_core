NAME = 	miniRT
SRCS =	./affichage/is_form/is_form.c \
		./affichage/is_form/is_qqch.c \
		./affichage/is_form/take_info.c \
		./affichage/is_form/utils_form.c \
		./affichage/lumiere/lum1.c \
		./affichage/lumiere/lum2.c \
		./affichage/affichage.c \
		./affichage/collisions.c \
		./affichage/init_forms.c \
		./affichage/utils.c \
		./affichage/utils2.c \
		./affichage/utils3.c \
		./affichage/vecteur_normal.c \
		./color/color.c \
		./maths/maths.c \
		./maths/maths_bis.c \
		./maths/maths_ter.c \
		./maths/maths_quater.c \
		./maths/maths_cinquies.c \
		./maths/maths_sexti.c \
		./parsing/init_base.c \
		./parsing/init_type1.c \
		./parsing/init_type2.c \
		./parsing/pars_line.c \
		./parsing/trait_f_rt.c \
		./parsing/utils_pars.c \
		./parsing/utils_pars2.c \
		./parsing/utils_pars3.c \
		enregistrement_bmp.c \
		gestion_fenetre.c \
		main.c

OBJS		=		${SRCS:.c=.o}

%.o : %.c general.h
	gcc -c -Wall -Wextra -Werror $< -o $@

$(NAME) : $(OBJS)
	$(MAKE) -C ./libft
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJS) minilibx/libmlx.a libft/libft.a -framework Opengl -framework appkit

all :		$(NAME)

clean :
	rm -rf $(OBJS)
	$(MAKE) clean -C ./libft

fclean :	clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
	rm -rf capture.bmp

re :		fclean all

.PHONY :	all fclean clean re