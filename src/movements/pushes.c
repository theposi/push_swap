/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:41:48 by crizapat          #+#    #+#             */
/*   Updated: 2025/04/09 09:41:53 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_a(t_stack *stack_a, t_stack *stack_b, t_bool print)
{
	t_node *node_to_a;

	if (!stack_a || !stack_a->head)
		return ;
	node_to_a = stack_b->head;
	stack_b->head = node_to_a->next;
	node_to_a->next = stack_a->head;
	stack_a->head = node_to_a;
	stack_a->size++;
	stack_b->size--;
	if (print == TRUE)
		write(STDOUT_FILENO, "pa\n", sizeof(char) * 3);
}

void	push_b(t_stack *stack_a, t_stack *stack_b, t_bool print)
{
	t_node *node_to_b;

	if (!stack_b || !stack_b->head)
		return ;
	node_to_b = stack_a->head;
	stack_a->head = node_to_b->next;
	node_to_b->next = stack_b->head;
	stack_b->head = node_to_b;
	stack_b->size++;
	stack_a->size--;
	if (print == TRUE)
		write(STDOUT_FILENO, "pb\n", sizeof(char) * 3);
}

