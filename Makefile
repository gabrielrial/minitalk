NAME = server client
NAME_BONUS = server_bonus client_bonus

SRC = src/
SRC_BONUS = src/bonus/

SRCSERVER = $(SRC)server.c
SRCCLIENT = $(SRC)client.c

BNSSERVER = $(SRC_BONUS) server.c
BNSCLIENT = $(SRC_BONUS) client.c

LIB_DIR = libft
LIBFT = -L$(LIB_DIR) -lft

CC =	cc
FLAGS =	-Wall -Werror -Wextra
RM = rm -f

all:	$(NAME)

bonus:	$(NAME_BONUS)

server:	$(SRCSERVER)
	$(CC) $(FLAGS) -o server $(SRCSERVER) $(LIBFT) 

client: $(SRCCLIENT)
	$(CC) $(FLAGS) -o client $(SRCCLIENT) $(LIBFT)

server_bonus: $(BNSSERVER)
	$(CC) $(FLAGS) -o server_bonus $(BNSSERVER) $(LIBFT)

client_bonus: $(BNSCLIENT)
	$(CC) $(FLAGS) -o client_bonus $(BNSCLIENT) $(LIBFT)

clean:
	$(RM) $(NAME) $(NAME_BONUS)

fclean: clean
	$(RM) server client server_bonus client_bonus

re : fclean all

