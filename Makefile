NAME = libftprintf.a

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

SRCLIBFT =	libft/ft_atoi.o libft/ft_bzero.o libft/ft_calloc.o\
		libft/ft_isalnum.o libft/ft_isalpha.o libft/ft_isascii.o\
		libft/ft_isdigit.o libft/ft_isprint.o libft/ft_itoa.o\
		libft/ft_memccpy.o libft/ft_memchr.o\
		libft/ft_memcmp.o libft/ft_memcpy.o libft/ft_memmove.o\
		libft/ft_memset.o libft/ft_putchar_fd.o\
		libft/ft_putendl_fd.o libft/ft_putnbr_fd.o\
		libft/ft_putstr_fd.o libft/ft_split.o libft/ft_strchr.o\
		libft/ft_strdup.o libft/ft_strjoin.o\
		libft/ft_strlcat.o libft/ft_strlen.o libft/ft_strmapi.o\
		libft/ft_strncmp.o libft/ft_strnstr.o libft/ft_strrchr.o\
		libft/ft_strtrim.o libft/ft_substr.o libft/ft_putnbr.o\
		libft/ft_tolower.o libft/ft_toupper.o libft/ft_strlcpy.o\
		libft/ft_putchar.o

SRCPRINTF =  conv_low_x.o\
			 conv_u_x.o\
			 ft_printf.o\
			 print_arg.o\
			 print_c.o\
             print_int.o\
             print_p.o\
             print_perc.o\
             print_s.o\
             print_u.o\
             print_low_x.o\
             printchar_time.o\
			 conv_ptr.o\
			 print_up_x.o\
			 len_digit.o\
			 init_parseprint.o\
			 check_pos.o\
			 check_width.o\
			 printstr_len.o\
			 parse_spec.o

all: $(NAME)

$(NAME): $(SRCLIBFT) $(SRCPRINTF)
	ar rc $(NAME) $(SRCLIBFT) $(SRCPRINTF)

clean:
	rm -f $(SRCLIBFT) $(SRCPRINTF)

fclean: clean
	rm -f $(NAME)

re: fclean all
