# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: geargenc <geargenc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/24 17:11:19 by geargenc          #+#    #+#              #
#    Updated: 2018/03/29 18:18:38 by geargenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT			:

NAME			=	fractol

CC				= 	gcc

CFLAGS			=	-Wall -Wextra -Werror -I includes/ -I libft/includes/

OFLAGS			=	-flto -O3 -march=native

XFLAGS			=	-lmlx -framework OpenGL -framework Appkit

FILES			=	colorset1.c\
					colorset2.c\
					colorset3.c\
					fractaleset1.c\
					fractaleset2.c\
					ft_bar.c\
					ft_clrpick_event.c\
					ft_color_fract.c\
					ft_colorpicker.c\
					ft_complex.c\
					ft_config.c\
					ft_cursor.c\
					ft_draw.c\
					ft_error.c\
					ft_event.c\
					ft_img.c\
					ft_imgtools.c\
					ft_iter.c\
					ft_power.c\
					ft_shift.c\
					ft_sqr.c\
					ft_utilities.c\
					ft_zoom.c\
					functiontabs.c\
					main.c

SRC_DIR			=	src/

SRC				=	$(addprefix $(SRC_DIR), $(FILES))

OBJ_DIR			=	obj/

OBJ				=	$(addprefix $(OBJ_DIR), $(FILES:.c=.o))

DEP_DIR			=	dep/

DEP				=	$(addprefix $(DEP_DIR), $(FILES:.c=.d))

all				:	$(NAME)

$(DEP_DIR)%.d	:	$(SRC_DIR)%.c
	@mkdir -p $(DEP_DIR)
	@$(CC) $(CFLAGS) -MM $< -MT $(OBJ_DIR)$*.o -MF $@
	@printf "\r\E[K\033[1;33mCreated : $@\033[0m"

-include $(DEP)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c Makefile
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@
	@printf "\r\E[K\033[1;33mCreated : $@\033[0m"

$(NAME)			:	$(OBJ)
	@printf "\r\E[K\033[1;36mMaking libft...\033[0m\n"
	@make -C libft/
	@printf "\033[1;36m--------------------\033[0m\n"
	@$(CC) $(CFLAGS) $(OFLAGS) $(XFLAGS) $(OBJ) -o $@ libft/libft.a
	@printf "\033[1;32mCreated : $@\033[0m\n"

clean			:
	@rm -rf obj
	@printf "\033[1;31mRemoved : $(OBJ_DIR)\033[0m\n"
	@rm -rf dep
	@printf "\033[1;31mRemoved : $(DEP_DIR)\033[0m\n"

fclean			:	clean
	@printf "\033[1;36mMaking fclean libft...\033[0m\n"
	@make -C libft/ fclean
	@printf "\033[1;36m--------------------\033[0m\n"
	@rm -f $(NAME)
	@printf "\033[1;31mRemoved : $(NAME)\033[0m\n"

re				:
	@$(MAKE) $(MFLAGS) fclean
	@$(MAKE) $(MFLAGS) all

.PHONY			:	all clean fclean re
