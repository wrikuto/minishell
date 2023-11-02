# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 18:56:17 by wrikuto           #+#    #+#              #
#    Updated: 2023/10/31 17:44:39 by wrikuto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
INC		= ./inc
GNL		= ./get_next_line
GNL_A	= $(addprefix $(GNL), /libgnl.a)
LIBFT	= ./libft
LIBFT_A	= $(addprefix $(LIBFT), /libft.a)
PRTF	= ./ft_printf
PRTF_A	= $(addprefix $(PRTF), /libftprintf.a)

SRC_DIR	= ./srcs
SRCS	= \
		./srcs/main.c \
		./srcs/builtin/cat.c \
		./srcs/builtin/pwd.c \
		./srcs/exec/exec.c \
		./srcs/exec/search_path.c \
		./srcs/parse/parser.c \
		./srcs/parse/input_spliter.c \
		./srcs/free/free.c \
		./srcs/error/error_msg.c \


OBJS = $(SRCS:.c=.o)

CC		= cc
FLAGS	= -Wall -Wextra -Werror -I$(INC)
RM		= rm -rf

all:			$(NAME)



$(NAME):		$(OBJS) $(LIBFT_A) $(GNL_A) $(PRTF_A)
				@$(CC) $(FLAGS) $(OBJS) $(LIBFT_A) $(GNL_A) $(PRTF_A) -lreadline -o $(NAME)

$(GNL_A):
				@$(MAKE) -s -C $(GNL)
				@echo "gnl compiled"

$(LIBFT_A):
				@$(MAKE) -s -C $(LIBFT)
				@echo "libft compiled"

$(PRTF_A):
				@$(MAKE) -s -C $(PRTF)
				@echo "printf compiled"


cls:
				@$(RM) $(OBJS)
				@echo "deleted srcs/**/*.o"

clean:
				@$(RM) $(OBJS)
				@$(MAKE) clean -s -C $(LIBFT)
				@$(MAKE) clean -s -C $(GNL)
				@$(MAKE) clean -s -C $(PRTF)
				@echo "cleaned"


fclean:			clean
				@$(MAKE) fclean -s -C $(LIBFT)
				@$(MAKE) fclean -s -C $(GNL)
				@$(MAKE) fclean -s -C $(PRTF)
				@$(RM) $(NAME)
				@echo "fcleaned"

re:				fclean all

sre:			cls
				$(MAKE)
				@echo "remake srcs"

.PHONY:			all clean fclean re clsr sre




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