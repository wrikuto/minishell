

NAME	= minishell
INC		= ./inc
# GNL		= ./get_next_line
# GNL_A	= $(addprefix $(GNL), libgnl.a)
LIBFT	= ./libft
LIBFT_A	= $(addprefix $(LIBFT), /libft.a)

SRC_DIR	= ./srcs
SRCS	= \
		./srcs/main.c \
		./srcs/builtin/cat.c \
		./srcs/builtin/pwd.c \
		./srcs/exec/exec.c \
		# ./


OBJS = $(SRCS:.c=.o)

CC		= cc
FLAGS	= -Wall -Wextra -Werror -I$(INC)
RM		= rm -rf

all:		$(OBJ_DIR) $(NAME)




$(NAME):		$(OBJS) $(LIBFT_A)
				$(CC) $(FLAGS) $(OBJS) $(LIBFT_A) -lreadline -o $(NAME)

$(LIBFT_A):
				@$(MAKE) -s -C $(LIBFT)

# $(GNL_A):
# 				$(MAKE) -s -C $(GNL)



clsr:
				@$(RM) $(SRC_DIR)/**/*.o
				@echo "delete srcs/**/*.o"

clean:			clsr
				# $(MAKE) clean -s -C $(LIBFT)


fclean:			clean
				# $(MAKE) fclean -s -C $(LIBFT)
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re




# NAME	= minishell
# INC		= ./inc
# RM		= rm -f
# SRC_DIR	= ./srcs
# SRC		=

# CC 		= cc
# FLAG	= -Wall -Wextra -Werror -I$(INC) -lreadline

# OBJ		=	$(SRCS:%.c=%.o)

# all: $(NAME)

# .c.o:
# 				$(CC) $(FLAG) -c $< -o $(<:.c=.o)
				

# $(NAME):		$(OBJ)
# 				$(CC) $(FLAG) $(OBJ)

# clean:
# 				$(RM) *.o

# fclean:
# 				$(RM) *.o
# 				$(RM) $(NAME)


# -------