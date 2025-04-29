/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:57:56 by crizapat          #+#    #+#             */
/*   Updated: 2025/04/29 12:57:24 by crizapat         ###   ########.fr       */
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

void k_sort_2(t_stack *stack_a, t_stack *stack_b)
{
	size_t cost;

	while (stack_b->size != 0)
	{
		cost = count_steps_to_index(stack_a, stack_b->size - 1);
		while (stack_b->head->index != stack_b->size - 1)
		{
			if (cost >= stack_b->size / 2)		
				reverse_rotate_b(stack_b);
			else
				rotate_b(stack_b);
		}
		push_a(stack_a, stack_b);
	}
}

void k_sort_1(t_stack *stack_a, t_stack *stack_b)
{
	size_t movements_counter;
	size_t magic_number;

	movements_counter = 0;
	magic_number = ft_square_number(stack_a->size) * 133 / 100; 

	while (stack_a->size != 0)
	{
		if (stack_a->head->index <= movements_counter)
		{
			push_b(stack_a, stack_b);
			movements_counter++;
		}
		else if (stack_a->head->index <= movements_counter + magic_number)
		{
			push_b(stack_a, stack_b);
			movements_counter++;
			if (stack_a->head->index <= movements_counter + magic_number)
				rotate_b(stack_b);
			else
				rotate_both(stack_a, stack_b);
		}
		else
			rotate_a(stack_a);
	}
	k_sort_2(stack_a, stack_b);
}

void sorter(t_stacks *stacks, size_t size)
{
	if (size == 2)
		sort_2_numbers(&stacks->stack_a);
	else if (size == 3)
		sort_3_numbers(&stacks->stack_a);
	else if (size == 4)
		sort_4_numbers(&stacks->stack_a, &stacks->stack_b);
	else if (size == 5)
		sort_5_numbers(&stacks->stack_a, &stacks->stack_b);
	else
		k_sort_1(&stacks->stack_a, &stacks->stack_b);
}
