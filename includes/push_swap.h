/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:28:39 by crizapat          #+#    #+#             */
/*   Updated: 2025/04/29 12:23:11 by crizapat         ###   ########.fr       */
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

//		GENERAL
t_bool	args_checker(int argc, char **argv);
t_bool	ft_atoi_limits_checker(const char *str, int *result, int *str_index);
t_bool	fill_stack(t_stack *stack_a, int argc, char **argv);
t_bool	check_duplicate(t_stack stack_a);

//		LIST MANIPULATION
t_node	*create_node(int number);
void	stack_cleaner(t_node **node);
t_bool	node_to_stack(t_stack *stack, int number);

//		NODES MOVEMENTS
void	swap_a(t_stack *stack_a, t_bool print);
void	swap_b(t_stack *stack_b, t_bool print);
void	swap_both(t_stacks *stacks, t_bool print);

void	rotate_a(t_stack *stack_a, t_bool print);
void	rotate_b(t_stack *stack_a, t_bool print);
void	rotate_both(t_stack *stack_a, t_stack *stack_b, t_bool print);

void	reverse_rotate_a(t_stack *stack_a, t_bool print);
void	reverse_rotate_b(t_stack *stack_b, t_bool print);
void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b, t_bool print);

void	push_a(t_stack *stack_a, t_stack *stack_b, t_bool print);
void	push_b(t_stack *stack_a, t_stack *stack_b, t_bool print);

//		SORT FUNCTIONS
void	sort_2_numbers(t_stack *stack_a);
void	sort_3_numbers(t_stack *stack_a);
void	sort_4_numbers(t_stack *stack_a, t_stack *stack_b);
void	sort_5_numbers(t_stack *stack_a, t_stack *stack_b);
void	k_sort_1(t_stack *stack_a, t_stack *stack_b);
void	k_sort_2(t_stack *stack_a, t_stack *stack_b);
t_bool	is_sorted(t_stack *stack_a);
void	sorter(t_stacks *stacks, size_t size);

t_bool	indexer(t_stacks stacks);
size_t	count_steps_to_index(t_stack *stack, size_t index);
size_t	get_min_index(t_stack *stack_a);

#endif
