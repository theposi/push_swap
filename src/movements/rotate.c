/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:10:14 by crizapat          #+#    #+#             */
/*   Updated: 2025/04/10 18:07:25 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void rotate_a(t_stack *a)
{
	t_node *temp_node;
	t_node *current_node;

	if(!a || !a->head || !a->head->next) 	
		return ;
	temp_node = a->head;
	a->head = temp_node->next;
	current_node = a->head;
	while (current_node->next != NULL)
		current_node = current_node->next;
	current_node->next = temp_node;
	temp_node->next = NULL;
	write(STDOUT_FILENO, "ra", sizeof(char) * 3);
	write(STDOUT_FILENO, "\n", sizeof(char));
}

void rotate_b(t_stack *b)
{
	t_node *temp_node;
	t_node *current_node;

	if(!b || !b->head || !b->head->next)
		return ;
	temp_node = b->head;
	b->head = temp_node->next;
	current_node = b->head;
	while (current_node->next != NULL)
		current_node = current_node->next;
	current_node->next = temp_node;
	temp_node->next = NULL;
	write(STDOUT_FILENO, "rb", sizeof(char) * 3);
	write(STDOUT_FILENO, "\n", sizeof(char));
}

void rotate_both(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	rotate_a(a);
	rotate_a(b);
	write(STDOUT_FILENO, "rr", sizeof(char) * 3);
	write(STDOUT_FILENO, "\n", sizeof(char));
}

