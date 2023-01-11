SRCS_DIR        = srcs

OBJS_DIR		= objs

DECODER_FILES	= decoder/main.c

ENCODER_FILES	= encoder/main.c

SCRS_DECODER	= $(addprefix $(SRCS_DIR)/, $(DECODER_FILES))

OBJS_DECODER    = $(addprefix $(OBJS_DIR)/, $(DECODER_FILES:%.c=%.o))

SCRS_ENCODER	= $(addprefix $(SRCS_DIR)/, $(ENCODER_FILES))

OBJS_ENCODER    = $(addprefix $(OBJS_DIR)/, $(ENCODER_FILES:%.c=%.o))

INCLUDES		= includes

CC            = gcc

CFLAGS        = -Wall -Wextra -Werror -g 

I_CC			= -I $(INCLUDES)

ENCODER_NAME    = encoder

DECODER_NAME    = decoder

SUBDIRS			= decoder encoder

all: $(ENCODER_NAME) $(DECODER_NAME)

$(ENCODER_NAME):	$(OBJS_ENCODER)
	$(CC) $(CFLAGS) $(OBJS_ENCODER) -o $(ENCODER_NAME)

$(DECODER_NAME):	$(OBJS_DECODER)
	$(CC) $(CFLAGS) $(OBJS_DECODER) -o $(DECODER_NAME)

$(OBJS_DIR)/%.o	: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR) $(addprefix $(OBJS_DIR)/, $(SUBDIRS))
	$(CC) $(CFLAGS) $(I_CC) -c $< -o $@

clean:
	rm -rf  $(OBJS_DIR)

fclean: clean
	rm -rf $(ENCODER_NAME) $(DECODER_NAME)

re: fclean all

.PHONY: all clean fclean re
