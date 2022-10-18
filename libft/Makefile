NAME1	= libft.a

cc		= gcc
CFLAG	= -Wall -Werror -Wextra
RM		= rm -f
AR		= ar crs
SRCS_1	= ft_strlen.c		\
		  ft_strchr.c		\
		  ft_strnstr.c		\
		  ft_memcpy.c		\
		  ft_atoi.c			\
		  ft_isalpha.c		\
		  ft_isdigit.c		\
		
SRCS_2 = ft_strjoin.c  ft_split.c ft_atoi_h.c ft_printf.c ft_word_count.c get_next_line.c print_utlis_1.c	print_utlis_2.c print_utlis_3.c



SRC	= $(SRCS_1)			\
	  $(SRCS_2)			\

OBJS	= $(SRC:.c=.o)



%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

all	: $(NAME1)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME1)

re : fclean all

$(NAME1) : $(OBJS)
	@$(AR) $@ $^


 .PHONY : all clean fclean re
