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

void	reverse_rotate_a(t_stack *a)
{
	t_node	*temp_node;
	t_node	*current_node;

	if (!a || !a->head || !a->head->next)
		return ;
	current_node = a->head;
	while (current_node->next->next != NULL)
		current_node = current_node->next;
	temp_node = current_node->next;
	current_node->next = NULL;
	temp_node->next = a->head;
	a->head = temp_node;
	write(STDOUT_FILENO, "rra\n", sizeof(char) * 4);
}

void	reverse_rotate_b(t_stack *b)
{
	t_node	*temp_node;
	t_node	*current_node;

	if (!b || !b->head || !b->head->next)
		return ;
	current_node = b->head;
	while (current_node->next->next != NULL)
		current_node = current_node->next;
	temp_node = current_node->next;
	current_node->next = NULL;
	temp_node->next = b->head;
	write(STDOUT_FILENO, "rrb\n", sizeof(char) * 4);
}

void	reverse_rotate_both(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	reverse_rotate_a(a);
	reverse_rotate_a(b);
	write(STDOUT_FILENO, "rrr\n", sizeof(char) * 4);
}
