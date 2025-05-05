/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:03:29 by crizapat          #+#    #+#             */
/*   Updated: 2025/04/11 12:11:51 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate_a(t_stack *stack_a, t_bool print)
{
	t_node	*temp_node;
	t_node	*current_node;

	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return ;
	current_node = stack_a->head;
	while (current_node->next->next != NULL)
		current_node = current_node->next;
	temp_node = current_node->next;
	current_node->next = NULL;
	temp_node->next = stack_a->head;
	stack_a->head = temp_node;
	if (print == TRUE)
		write(STDOUT_FILENO, "rra\n", sizeof(char) * 4);
}

void	reverse_rotate_b(t_stack *stack_b, t_bool print)
{
	t_node	*temp_node;
	t_node	*current_node;

	if (!stack_b || !stack_b->head || !stack_b->head->next)
		return ;
	current_node = stack_b->head;
	while (current_node->next->next != NULL)
		current_node = current_node->next;
	temp_node = current_node->next;
	current_node->next = NULL;
	temp_node->next = stack_b->head;
	if (print == TRUE)
		write(STDOUT_FILENO, "rrb\n", sizeof(char) * 4);
}

void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b, t_bool print)
{
	if (!stack_a || !stack_b)
		return ;
	reverse_rotate_a(stack_a, FALSE);
	reverse_rotate_a(stack_b, FALSE);
	if (print == TRUE)
		write(STDOUT_FILENO, "rrr\n", sizeof(char) * 4);
}

