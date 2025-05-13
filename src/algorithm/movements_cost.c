/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:21:20 by crizapat          #+#    #+#             */
/*   Updated: 2025/05/12 09:56:36 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

size_t	count_steps_to_index(t_stack *stack, size_t index)
{
	t_node	*current_node;
	size_t	steps;

	current_node = stack->head;
	steps = 0;
	while (current_node)
	{
		if (current_node->index == index)
			return (steps);
		steps++;
		current_node = current_node->next;
	}
	return (steps);
}

size_t	get_min_index(t_stack *stack_a)
{
	t_node	*current_node;
	size_t	min_index;

	current_node = stack_a->head;
	min_index = current_node->index;
	while (current_node)
	{
		if (current_node->index < min_index)
			min_index = current_node->index;
		current_node = current_node->next;
	}
	return (min_index);
}
