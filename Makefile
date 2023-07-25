RED	=\033[0;31m
BLUE	=\033[0;34m
WHITE	=\033[0;37m
YELLOW	=\033[0;33m

NAME		= cub3D
CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra
MLX_FLAGS_MACOS		= -framework OpenGL -framework AppKit
MLX_FLAGS_LINUX		= -lXext -lX11 -lm -lz

LIBFT 		= ./inc/libft/libft.a
MLX_LINUX	= ./inc/minilibx_linux/libmlx.a
MLX_MACOS	= ./inc/minilibx_macos/libmlx.a


SRCS	= 	${shell find ./src -name "*.c"}

OBJS = $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		@echo "$(YELLOW)>>>>> Libft Library Compiling <<<<<$(WHITE)"
		@make -C ./inc/libft/
		@echo "$(YELLOW)>>>>> Minilibx Library Compiling <<<<<$(WHITE)"
#		FOR LINUX
#		@make -C ./inc/minilibx_linux/
#		@echo "$(YELLOW)>>>> Cub3d Compiling <<<<<$(WHITE)"
#		@$(CC) $(OBJS) $(LIBFT) $(MLX_LINUX) $(MLX_FLAGS_LINUX) -o $(NAME)
#		FOR MAC
		@make -sC ./inc/minilibx_macos/
		@echo "$(YELLOW)>>>> Cub3d Compiling <<<<<$(WHITE)"
		@$(CC) $(OBJS) $(LIBFT) $(MLX_FLAGS_MACOS) $(MLX_MACOS) -o $(NAME)
		@echo "$(BLUE)>>>>> Done <<<<<$(WHITE)"
norm:
			@norminette ./inc/libft/
			@norminette ./src/
		
clean:
			@make clean -C ./inc/libft/
			$(RM) $(OBJS)

fclean:		clean
			@make fclean -C ./inc/libft/
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re