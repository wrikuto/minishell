

NAME	= minishell
INC		= ./inc
# GNL		= ./get_next_line
# GNL_A	= $(addprefix $(GNL), libgnl.a)
LIBFT	= ./libft
LIBFT_A	= $(addprefix $(LIBFT), libft.a)


OBJ_DIR	= ./objs
SRCS	= \
		./srcs/main.c \
		./srcs/builtin/cat.c \
		./srcs/builtin/pwd.c \
		./srcs/exec/exec.c \
		# ./


OBJS = $(SRCS:.c=.o)

CC		= cc
FLAGS	= -Wall -Wextra -Werror -I$(INC)
RM		= rm -f

all:		$(OBJ_DIR) $(NAME)


$(OBJ_DIR)/%.o: $(SRCS:.c=.o)
				$(CC) $(FLAGS) -c $< -o $@

$(NAME):		$(OBJS) $(GNL_A)
				$(CC) $(FLAGS) $(OBJS) -lreadline -llibft -o $(NAME)


# $(GNL_A):
# 				$(MAKE) -s -C $(GNL)

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)

clean:
				# $(MAKE) clean -s -C $(GNL)
				$(RM) $(OBJ_DIR)/*

fclean:			clean
				# $(MAKE) fclean -s -C $(GNL)
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