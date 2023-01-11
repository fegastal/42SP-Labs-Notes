SRCS         = ./srcs/

SRC_DECODER    = $(SRCS)./decoder/main.c

OBJ_DECODER    = $(SRC_DECODER:.c=.o)

SRC_ENCODER    = $(SRCS)./encoder/main.c

OBJ_ENCODER    = $(SRC_ENCODER:.c=.o)

CC            = gcc

CFLAGS        = -Wall -Wextra -Werror -g

ENCODER_NAME    = encoder

DECODER_NAME    = decoder

all: $(ENCODER_NAME) $(DECODER_NAME)

encoder:	$(OBJ_DECODER)
	$(CC) $(CFLAGS) $(OBJ_DECODER) -o $(ENCODER_NAME)

decoder:	$(OBJ_ENCODER)
	$(CC) $(CFLAGS) $(OBJ_ENCODER) -o $(DECODER_NAME)

clean:
	rm -rf  $(DIR)*.o

fclean: clean
	rm -rf $(ENCODER_NAME) $(DECODER_NAME)

re: fclean all

.PHONY: all clean fclean re
