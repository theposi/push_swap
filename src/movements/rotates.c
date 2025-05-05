/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:26:28 by crizapat          #+#    #+#             */
/*   Updated: 2025/04/11 10:56:56 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void rotate_a(t_stack *stack_a, t_bool print)
{
	t_node	*temp_node;
	t_node	*current_node;

	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return ;
	temp_node = stack_a->head;
	stack_a->head = temp_node->next;
	current_node = stack_a->head;
	while (current_node->next != NULL)
		current_node = current_node->next;
	current_node->next = temp_node;
	temp_node->next = NULL;
	if (print == TRUE)
		write(STDOUT_FILENO, "ra\n", sizeof(char) * 3);
}

void rotate_b(t_stack *stack_b, t_bool print)
{
	t_node	*temp_node;
	t_node	*current_node;

	if (!stack_b || !stack_b->head || !stack_b->head->next)
		return ;
	temp_node = stack_b->head;
	stack_b->head = temp_node->next;
	current_node = stack_b->head;
	while (current_node->next != NULL)
		current_node = current_node->next;
	current_node->next = temp_node;
	temp_node->next = NULL;
	if (print == TRUE)
		write(STDOUT_FILENO, "rb\n", sizeof(char) * 3);
}

void rotate_both(t_stack *stack_a, t_stack *stack_b, t_bool print)
{
	if (!stack_a || !stack_b)
		return ;
	rotate_a(stack_a, FALSE);
	rotate_a(stack_b, FALSE);
	if (print == TRUE)
		write(STDOUT_FILENO, "rr\n", sizeof(char) * 3);
}

