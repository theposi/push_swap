/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:32:00 by crizapat          #+#    #+#             */
/*   Updated: 2025/04/10 17:08:25 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* TODO:
 * update header from relative to absolute
*/
#include "../../push_swap.h"

void push_a(t_stack *a, t_stack *b)
{
	t_node *node_to_a;

	if(!b || !b->node)
		return ;
	node_to_a = b->node;
	b->node = node_to_a->next;
	node_to_a->next = a->node;
	a->node = node_to_a;
	a->size++;
	b->size--;
	write(STDOUT_FILENO, "pa", sizeof(char) * 3);
}

void push_b(t_stack *a, t_stack *b)
{
	t_node *node_to_b;

	if(!a || !a->node)
		return ;
	node_to_b = a->node;
	a->node = node_to_b->next;
	node_to_b->next = b->node;
	b->node = node_to_b;
	b->size++;
	a->size--;
	write(STDOUT_FILENO, "pb", sizeof(char) * 3);
}

