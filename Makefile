#####################################PUSH_SWAP#####################################

NAME	=	push_swap
NAME_BONUS	=	checker

#####################################SRCS########################################

PATH_SRCS	=	srcs/

SRCS	+=	lists.c

vpath	%.c	$(PATH_SRCS)

PATH_SRCS_BONUS	=	srcs_bonus/

SRCS_BONUS	+=	main_bonus.c

vpath	%.c	$(PATH_SRCS_BONUS)

###################################OBJS#########################################

PATH_OBJS	=	objs
OBJS	=	$(patsubst	%.c,	$(PATH_OBJS)/%.o,	$(SRCS))
MAIN	=	$(patsubst	%.c,	$(PATH_OBJS)/%.o,	main.c)

PATH_OBJS_BONUS	=	objs_bonus
OBJS_BONUS	=	$(patsubst	%.c,	$(PATH_OBJS_BONUS)/%.o,	$(SRCS_BONUS))

################################COMPILATION####################################

INCLUDE	=	-Ilibft/includes	-Iinclude -g

LIBFT	=	libft/libft.a

CFLAGS	=	-Wall	-Wextra	-Werror

##################################RULES#######################################

all:		$(NAME)


$(NAME): $(LIBFT)	$(OBJS)	$(MAIN) 
	$(CC)	$(CFLAGS) $(OBJS)	objs/main.o 	-o	$(NAME)	$(INCLUDE)	$(LIBFT)

$(LIBFT):
	${MAKE}	-sC	libft

$(MAIN):
	$(CC)	$(CFLAGS)	-c	srcs/main.c	-o	objs/main.o	$(INCLUDE)

$(OBJS):	$(PATH_OBJS)/%.o:%.c Makefile
	mkdir	-p	$(PATH_OBJS)
	$(CC)	$(CFLAGS)	-c	$<	-o	$@	$(INCLUDE)

bonus:	$(NAME_BONUS)

$(NAME_BONUS):	$(OBJS)	$(OBJS_BONUS)
	$(CC)	$(CFLAGS)	$(OBJS)	$(OBJS_BONUS) -o	$(NAME_BONUS) $(INCLUDE)	$(LIBFT)

$(OBJS_BONUS):	$(PATH_OBJS_BONUS)/%.o:%.c Makefile
	mkdir	-p	$(PATH_OBJS_BONUS)
	$(CC)	$(CFLAGS)	-c	$<	-o	$@	$(INCLUDE)

clean:
	rm	-rf	$(PATH_OBJS)
	rm	-rf	$(PATH_OBJS_BONUS)

fclean:	clean
	rm	-rf	$(NAME)
	rm	-rf	$(NAME_BONUS)
	${MAKE}	fclean -sC	libft

re:	fclean
	${MAKE}

malloc_test: $(OBJS) $(MAIN)
	$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ ${OBJS} libft/libft.a -L. -lmallocator

.PHONY:	all	libft	clean	fclean	re