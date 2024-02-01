SRCS = 
NAME = philo
MAIN = main.c
LIBS = -Llibs/libft -lft
FLAGS = #-Werror -Wall -Wextra -g3

%.o: %.c
	@gcc $(FLAGS) -c $< 

all : libertad $(SRCS)
	@gcc -g3 -o $(NAME) $(MAIN) $(SRCS) $(LIBS) 
	@echo "\033[1;36mphilo :\033[m \033[1;32mOK\033[m"

libertad:
	@echo "\033[1;35mCompiling libs :\033[m"
	@make -s --no-print-directory -C libs/libft

stu :
	git subtree pull --prefix=libs/libft git@github.com:vlaward/philosopher_42.git main --squash

make re : fclean all

fclean : clean
	@rm -f ${NAME}
	@make fclean --no-print-directory -C libs/libft
	@echo "\033[1;32mReaaaaally clean :D\033[m"

clean :
	@echo "\033[0;35mSO DIRTY >w<\033[m"
	@rm -f ${SRCS}
	@make clean --no-print-directory -C libs/libft
	@echo "\033[1;32mEvrything's clean now 0w0\033[m"

