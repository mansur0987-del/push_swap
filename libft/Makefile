FLAG = -MMD -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_calloc.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_strchr.c \
	  ft_strdup.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strncmp.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_split.c \
	  ft_itoa.c \
	  ft_strmapi.c \
	  ft_striteri.c \
	  ft_putchar_fd.c \
	  ft_putchar_len.c \
	  ft_putstr_fd.c \
	  ft_putstr_len.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c

SRCBON = ft_lstnew.c \
		 ft_lstadd_front.c \
		 ft_lstsize.c \
		 ft_lstlast.c \
		 ft_lstadd_back.c \
		 ft_lstdelone.c \
		 ft_lstclear.c \
		 ft_lstiter.c \
		 ft_lstmap.c

HEADER = libft.h

OBJ = $(SRC:.c=.o)

OBJBON = $(SRCBON:.c=.o)

SRC_D =	$(SRC:.c=.d) $(SRCBON:.c=.d)

.c.o:
	gcc $(FLAG) -c $< -o ${<:.c=.o} -I $(HEADER)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus:	$(OBJBON)
	ar rc $(NAME) $(OBJBON)

clean:
	rm -f $(SRC_D)
	rm -f $(OBJ)
	rm -f $(OBJBON)

	echo "OBJ deleted"

fclean: clean
	rm -f $(NAME)
	echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
