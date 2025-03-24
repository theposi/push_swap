# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 15:14:23 by crizapat          #+#    #+#              #
#    Updated: 2025/03/13 16:13:57 by crizapat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	FLAGS ___________________________________
CC		=	cc
FLAGS 	= 	-Wall -Werror -Wextra -g3 -fsanitize=address
INCLUDE = 	-I
RM 		= 	rm -f

#	CONF___________________________________
TARGET 	= 	push_swap	
GREEN	=	\e[32m
RED		=	\e[31m
MAG		=	\e[35m
CYAN	=	\e[36m
NC		=	\e[0m


#	DIR___________________________________	
SRC_DIR = ./src/
LIBFT_DIR = ./utils/libft/
PRINTF_DIR = ./utils/ft_printf/

#	SRCS___________________________________	
LIBFT 	= 	$(LIBFT_DIR)libft.a
PRINTF 	= 	$(PRINTF_DIR)libftprintf.a

SRC 	= 	$(SRC_DIR)push_swap.c \
	  		$(SRC_DIR)parser.c

# OBJ___________________________________	
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(LIBFT):
	@echo "$(CYAN)📦 Compiling libft...$(NC)"
	@make -sC $(LIBFT_DIR) 
	@echo "$(GREEN)✅ Libft compiled successfully!.$(NC)"

$(PRINTF):
	@echo "$(CYAN)📦 Compiling ft_printf...$(NC)"
	@make -sC $(PRINTF_DIR) 
	@echo "$(GREEN)✅ ft_printf compiled successfully!$(NC)"

$(TARGET): $(OBJ) $(LIBFT) $(PRINTF)
	@echo "$(CYAN) 📦 Compiling push swap...$(NC)"
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(TARGET)
	@echo "$(MAG)✅ Push swap compiled successfully!.$(NC)"

%.o: %.c
	@echo "$(CYAN)🛠️Compiling $< → $@...$(NC)"
	@$(CC) $(FLAGS) -c $< -o $@

clean: 
	@make -sC $(LIBFT_DIR) fclean
	@make -sC $(PRINTF_DIR) fclean
	@echo "$(RED)🗑️ Cleaning object files.$(NC)"
	@$(RM) $(OBJ)

fclean:
	@echo "$(RED)🗑️ Cleaning executables and libraries.$(NC)"
	@$(RM) $(TARGET)

re: fclean all

.PHONY: all clean fclean re
