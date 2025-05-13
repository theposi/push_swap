/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:48:44 by crizapat          #+#    #+#             */
/*   Updated: 2025/05/12 09:55:57 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_2_numbers(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;

	first = stack_a->head;
	second = stack_a->head->next;
	if (first->index > second->index)
		swap_a(stack_a, TRUE);
}

void	sort_3_numbers(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stack_a->head;
	second = stack_a->head->next;
	third = stack_a->head->next->next;
	if (is_sorted(stack_a) == TRUE)
		return ;
	if (first->index < second->index && first->index < third->index)
	{
		swap_a(stack_a, TRUE);
		rotate_a(stack_a, TRUE);
	}
	else if (first->index < second->index)
		reverse_rotate_a(stack_a, TRUE);
	else if (first->index > second->index && first->index > third->index)
	{
		rotate_a(stack_a, TRUE);
		if (second->index > third->index)
			swap_a(stack_a, TRUE);
	}
	else
		swap_a(stack_a, TRUE);
}

void	sort_4_numbers(t_stack *stack_a, t_stack *stack_b)
{
	size_t		min_numb_on_stack;
	size_t		movements_cost;

	min_numb_on_stack = get_min_index(stack_a);
	movements_cost = count_steps_to_index(stack_a, min_numb_on_stack);
	if (is_sorted(stack_a) == TRUE)
		return ;
	while (stack_a->head->index != min_numb_on_stack)
	{
		if (movements_cost > 1)
			reverse_rotate_a(stack_a, TRUE);
		else
			rotate_a(stack_a, TRUE);
	}
	push_b(stack_a, stack_b, TRUE);
	sort_3_numbers(stack_a);
	push_a(stack_a, stack_b, TRUE);
}

void	sort_5_numbers(t_stack *stack_a, t_stack *stack_b)
{
	size_t	min_numb_on_stack;
	size_t	movements_cost;

	min_numb_on_stack = get_min_index(stack_a);
	movements_cost = count_steps_to_index(stack_a, min_numb_on_stack);
	if (is_sorted(stack_a) == TRUE)
		return ;
	while (stack_a->head->index != min_numb_on_stack)
	{
		if (movements_cost > 3)
			reverse_rotate_a(stack_a, TRUE);
		else
			rotate_a(stack_a, TRUE);
	}
	push_b(stack_a, stack_b, TRUE);
	sort_4_numbers(stack_a, stack_b);
	push_a(stack_a, stack_b, TRUE);
}
