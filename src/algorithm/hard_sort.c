/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:48:44 by crizapat          #+#    #+#             */
/*   Updated: 2025/04/18 18:00:56 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void sort_2_numbers(t_stack *stack_a)
{
	t_node *first;
	t_node *second;

	first = stack_a->head;
	second = stack_a->head->next;
	if (first->index > second->index)
		swap_a(stack_a);
}

/*
	WIP
	Finish the 4 and 5 numbers sorting	
*/
void sort_3_numbers(t_stack *stack_a)
{
	t_node *first;
	t_node *second;
	t_node *third;

	first = stack_a->head;
	second = stack_a->head->next;
	third = stack_a->head->next->next;
	if (is_sorted(stack_a) == TRUE)
		return ;
	if (first->index < second->index && first->index < third->index)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (first->index < second->index)
		reverse_rotate_a(stack_a);
	else if (first->index > second->index && first->index > third->index)
	{
		rotate_a(stack_a);
		if (second->index > third->index)
			swap_a(stack_a);
	}
	else 
		swap_a(stack_a);
}
