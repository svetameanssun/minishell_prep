NAME = readline_ex
CC = gcc
SRC = readline_ex.c \
      ft_itoa.c \
      ft_strdup.c \
      ft_strlen.c \
      ft_strjoin.c
FLG = -lreadline
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC)  $^ -o $(NAME) $(FLG)

# The code bellow will create RELINK!
# Object file is dependent on ALL SOURCE FILES!!!
# Any change in any soyrce file will trigger the recompilation
# of all obect files
#$(OBJ): $(SRC)
#      $(CC)  $(FLG) -c $(SRC) -o $(OBJ)

%.o : %.c
	$(CC) -c $< -o $@ $(FLG)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
