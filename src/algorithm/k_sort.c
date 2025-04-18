/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:57:56 by crizapat          #+#    #+#             */
/*   Updated: 2025/04/18 14:21:13 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_bool	is_sorted(t_stack *stack_a)
{
	t_node *current_node;

	if(!stack_a || stack_a->size < 1)
		return (TRUE);
	current_node = stack_a->head;
	while (current_node->next)
	{
		if (current_node->index > current_node->next->index)
			return (FALSE);
		current_node = current_node->next;
	}
	return (TRUE);
}

/*
	WIP
	We have to meassure the cost of movements of a number
	with it's index in the stack.
*/
size_t	get_node_index(t_stack *stack, int index)
{
	size_t node_index;
	
	
}

void	push_nodes_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	index_counter;	
	t_node *current_node;

	index_counter = 0;
	while (stack_a->size != 0)
	{
		current_node = stack_a->head;
		if (current_node->index == index_counter)
		{
			push_b(stack_a, stack_b);
			index_counter++;
		}
		else
			rotate_a(stack_a);
	}
}

/*
	WIP
	Push the node to the stack b sorted by it's index.
*/
void	push_nodes_to_a(t_stack *stack_a, t_stack *stack_b)
{
		
}

