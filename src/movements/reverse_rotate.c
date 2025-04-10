/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:44:45 by crizapat          #+#    #+#             */
/*   Updated: 2025/04/10 18:07:18 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void reverse_rotate_a(t_stack *a)
{
	t_node *temp_node;
	t_node *current_node;

	if(!a || !a->head || !a->head->next)
		return ;
	current_node = a->head;
	while (current_node->next->next != NULL)
		current_node = current_node->next;
	temp_node = current_node->next;
	current_node->next = NULL;
	temp_node->next = a->head;
	a->head = temp_node;
	write(STDOUT_FILENO, "rra", sizeof(char) * 4);
	write(STDOUT_FILENO, "\n", sizeof(char));
}

void reverse_rotate_b(t_stack *b)
{
	t_node *temp_node;
	t_node *current_node;

	if(!b || !b->head || !b->head->next)
		return ;
	current_node = b->head;
	while (current_node->next->next != NULL)
		current_node = current_node->next;
	temp_node = current_node->next;
	current_node->next = NULL;
	temp_node->next = b->head;
	b->head = temp_node;
	write(STDOUT_FILENO, "rrb", sizeof(char) * 4);
	write(STDOUT_FILENO, "\n", sizeof(char));
}

void reverse_rotate_both(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	reverse_rotate_a(a);
	reverse_rotate_a(b);
	write(STDOUT_FILENO, "rrr", sizeof(char) * 4);
	write(STDOUT_FILENO, "\n", sizeof(char));
}

