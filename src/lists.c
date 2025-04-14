/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:54:18 by crizapat          #+#    #+#             */
/*   Updated: 2025/04/11 12:17:02 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 * @warning MALLOC
 */
t_node	*create_node(int number)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->index = 0;
	new_node->number = number;
	new_node->next = NULL;
	return (new_node);
}

void	stack_cleaner(t_node **node)
{
	t_node	*current_node;
	t_node	*temp_node;

	current_node = *node;
	while (current_node)
	{
		temp_node = current_node->next;
		free(current_node);
		current_node = temp_node;
	}
	*node = NULL;
}

t_bool	node_to_stack(t_stack *stack, int number)
{
	t_node	*new_node;
	t_node	*current_node;

	new_node = create_node(number);
	if (!new_node)
		return (FALSE);
	if (stack->head == NULL)
		stack->head = new_node;
	else
	{
		current_node = stack->head;
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_node;
	}
	stack->size++;
	return (TRUE);
}
