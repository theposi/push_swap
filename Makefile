# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 15:14:23 by crizapat          #+#    #+#              #
#    Updated: 2025/05/08 23:07:33 by crizapat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	FLAGS ___________________________________
CC			=	cc
INCLUDE 	= 	-I ./includes
FLAGS 		= 	-Wall -Werror -Wextra -g3 $(INCLUDE)
RM 			= 	rm -f

#	CONF___________________________________
TARGET 		= 	push_swap
GREEN		=	\e[32m
RED			=	\e[31m
MAG			=	\e[35m
CYAN		=	\e[36m
NC			=	\e[0m

#	DIR___________________________________
SRC_DIR 	= 	src
AGTHM_DIR 	= 	algorithm
MVTS_DIR 	= 	movements
LIBFT_DIR 	= 	utils/libft
PRINTF_DIR 	= 	utils/ft_printf

#	SRCS___________________________________
LIBFT 		= 	$(LIBFT_DIR)/libft.a
PRINTF 		= 	$(PRINTF_DIR)/libftprintf.a

SRCS 		= 	push_swap.c 		\
	  			parser.c 			\
				lists.c 			\
				arg_caster.c

MVTS		=	pushes.c 			\
				reverse_rotate.c 	\
				rotates.c			\
				swaps.c

AGTHMS		=	hard_sort.c			\
				k_sort.c			\
				movements_cost.c

#	PEFIX__________________________________
SRC 		=	$(addprefix $(SRC_DIR)/, $(SRCS))
MVT 		=	$(addprefix $(SRC_DIR)/$(MVTS_DIR)/, $(MVTS))
AGTHM		=	$(addprefix $(SRC_DIR)/$(AGTHM_DIR)/, $(AGTHMS))
PACKAGES    =	$(SRC) $(MVT) $(AGTHM)
OBJS 		= 	$(PACKAGES:%.c=%.o)

all: $(TARGET)

$(LIBFT):
	@echo "$(CYAN)📦 Compiling libft...$(NC)"
	@make -sC $(LIBFT_DIR)
	@echo "$(GREEN)✅ Libft compiled successfully!.$(NC)"

$(PRINTF):
	@echo "$(CYAN)📦 Compiling ft_printf...$(NC)"
	@make -sC $(PRINTF_DIR)
	@echo "$(GREEN)✅ ft_printf compiled successfully!$(NC)"

$(TARGET): $(OBJS) $(LIBFT) $(PRINTF)
	@echo "$(CYAN) 📦 Compiling push swap...$(NC)"
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(TARGET)
	@echo "$(MAG)✅ Push swap compiled successfully!.$(NC)"

%.o: %.c
	@echo "$(CYAN)🛠️ Compiling $< → $@...$(NC)"
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@make -sC $(LIBFT_DIR) fclean
	@make -sC $(PRINTF_DIR) fclean
	@echo "$(RED)🗑️ Cleaning object files.$(NC)"
	@$(RM) $(OBJS)

fclean:
	@echo "$(RED)🗑️ Cleaning executables and libraries.$(NC)"
	@$(RM) $(TARGET)

re: fclean all

.PHONY: all clean fclean re
