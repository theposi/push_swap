/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:28:39 by crizapat          #+#    #+#             */
/*   Updated: 2025/04/11 12:27:07 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include  "../utils/libft/libft.h"
# include  "../utils/ft_printf/ft_printf.h"
# include  <unistd.h>
# include  <stdio.h>
# include  <stdlib.h>
# include  <limits.h>

typedef	int	t_bool;
#define TRUE 0
#define FALSE 1

typedef struct s_node {
	size_t			index;
	int				number;
	struct s_node	*next;
} t_node;

typedef struct s_stack {
	size_t			size;
	t_node			*head;
} t_stack;

typedef struct s_stacks {
	t_stack			stack_a;
	t_stack			stack_b;
} t_stacks;

t_bool	args_checker(int argc, char **argv);
t_bool	ft_atoi_limits_checker(const char *str, int *result, int *str_index);
t_node	*create_node(int number);
void	stack_cleaner(t_node **node);
t_bool	node_to_stack(t_stack *stack, int number);

#endif
