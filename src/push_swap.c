/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:30:40 by crizapat          #+#    #+#             */
/*   Updated: 2025/04/18 13:23:56 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool fill_stack(t_stack *stack_a, int argc, char **argv)
{
	int	i;
	int	j;
	int	number;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_atoi_limits_checker(argv[i], &number, &j) == FALSE)
				return (stack_cleaner(&stack_a->head), FALSE);
			if (node_to_stack(stack_a, number) == FALSE)
				return (stack_cleaner(&stack_a->head), FALSE);
		}
		i++;
	}
	indexer(stack_a);
	return (TRUE);
}

t_bool indexer(t_stack *stack_a)
{
	t_node	*curren_node;	
	t_node	*node_to_compare;	
	size_t	index;

	if (!stack_a->head || !stack_a->size)
		return (FALSE);

	curren_node = stack_a->head;	
	while (curren_node)
	{
		index = 0;
		node_to_compare = stack_a->head; 
		while (node_to_compare)
		{
			if (node_to_compare->number < curren_node->number)
				index++;
			node_to_compare = node_to_compare->next;
		}
		curren_node->index = index;
		curren_node = curren_node->next;
	}
	return (TRUE);
}

int main(int argc, char **argv)
{
	if(argc == 1)
	{
		printf("Not enough parameters\n");
		exit(EXIT_FAILURE);
	}
	else {
		args_checker(argc, argv);
	}
	return (EXIT_SUCCESS);
}
