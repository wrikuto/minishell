NAME	= minishell
INC		= ./inc
RM		= rm -f
SRC_DIR	= ./srcs
SRC		=

CC 		= cc
FLAG	= -Wall -Wextra -Werror -I$(INC) -lreadline

OBJ		=	$(SRCS:%.c=%.o)

all: $(NAME)

.c.o:
				$(CC) $(FLAG) -c $< -o $(<:.c=.o)
				

$(NAME):		$(OBJ)
				$(CC) $(FLAG) $(OBJ)

clean:
				$(RM) *.o

fclean:
				$(RM) *.o
				$(RM) $(NAME)				