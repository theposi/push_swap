/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:35:40 by crizapat          #+#    #+#             */
/*   Updated: 2025/04/02 12:31:42 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void swap_a(t_stack *stack_a)
{
	t_node	*first_node;
	t_node	*second_node;

	if(!stack_a || !stack_a->head || !stack_a->head->next)
		return ;
	first_node = stack_a->head;
	second_node = first_node->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	stack_a->head = second_node;
	write(STDOUT_FILENO, "sa\n", sizeof(char) * 3);
}

void swap_b(t_stack *stack_b)
{
	t_node *first_node;
	t_node *second_node;

	if(!stack_b || !stack_b->head || !stack_b->head->next)
		return ;
	first_node = stack_b->head;
	second_node = first_node->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	stack_b->head = second_node;
	write(STDOUT_FILENO, "sb\n", sizeof(char) * 3);
}

void swap_both(t_stacks *stacks)
{
	if (!stacks)
		return ;
	swap_a(&stacks->stack_a);
	swap_b(&stacks->stack_b);
	write(STDOUT_FILENO, "ss\n", sizeof(char) * 3);
}

