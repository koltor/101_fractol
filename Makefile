# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/03/14 16:56:52 by matheme      #+#   ##    ##    #+#        #
#    Updated: 2019/05/27 20:38:45 by matheme     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

# nom de l'executable
NAME1 = fractol

# les routes
SRC_PATH	= srcs
OBJ_PATH	= obj
INC_PATH	= includes
LIB_PATH	= librairies

# nom des fichier code source (*.c)
NAME_SRC	=	fractol.c keyboard_event.c calcul_fractal.c display.c \
				multithreading_display.c error.c ui.c main.c mouse_event.c \
				calcul_fractal2.c

# nom des ficher objects (*.o)
NAME_OBJ = $(NAME_SRC:.c=.o)

#les sources
SRC		= $(addprefix $(SRC_PATH)/,$(NAME_SRC))
HEADER	= $(INC_PATH)/fractol.h

# les objects
OBJ		= $(addprefix $(OBJ_PATH)/,$(NAME_OBJ))

# compilateur + flags + framework
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
FRAMEWORKS	= -lmlx -framework OpenGL -framework AppKit

# librairies
LIBFT				= $(LIB_PATH)/libft
LIBFT.A				= $(LIBFT)/libft.a
MINILIBX			= $(LIB_PATH)/minilibx
MINILIBX.A			= $(MINILIBX)/libmlx.a

all : libft minilibx $(NAME1)
	@echo "\033[48;5;22m\033[38;5;15m frac_ol Compiler \033[0m"

$(NAME1) : $(OBJ) $(LIBFT.A) $(MINILIBX.A)
	@$(CC) -I $(LIBFT) -L $(LIBFT) -I $(MINILIBX) -L $(MINILIBX)  $^ -o $@ $(FRAMEWORKS)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c $(HEADER)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -I $(LIBFT) -I $(INC_PATH) -I $(MINILIBX) -c $< -o $@
	@printf "\033[48;5;28m \033[0m"

libft :
	@make -C $(LIBFT)

minilibx :
	@make -C $(MINILIBX)

clean :
	@rm -f $(OBJ)
	@make -C $(LIBFT) clean
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[48;5;1m\033[38;5;15m   binaire supprimer  \033[0m"

fclean: clean
	@make -C $(LIBFT) fclean
	@make -C $(MINILIBX) clean
	@rm -f $(NAME1)
	@echo "\033[48;5;208m\033[38;5;15m tout a été supprimer \033[0m"

re: fclean all

nonor :
	@norminette $(SRC_PATH)/*.c $(INC_PATH)/*.h

supernonor: nonor
	@make -C $(LIBFT) nonor
