/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:30:40 by crizapat          #+#    #+#             */
/*   Updated: 2025/05/12 09:48:32 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	fill_stack(t_stack *stack_a, int argc, char **argv)
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
	return (TRUE);
}

t_bool	indexer(t_stacks stacks)
{
	t_node	*curren_node;
	t_node	*node_to_compare;
	size_t	index;

	if (!stacks.stack_a.head || !stacks.stack_a.size)
		return (FALSE);
	curren_node = stacks.stack_a.head;
	while (curren_node)
	{
		index = 0;
		node_to_compare = stacks.stack_a.head;
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

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		return (EXIT_FAILURE);
	stacks.stack_a.head = NULL;
	stacks.stack_a.size = 0;
	stacks.stack_b.head = NULL;
	stacks.stack_b.size = 0;
	if (args_checker(argc, argv) == TRUE)
	{
		if (fill_stack(&(stacks.stack_a), argc, argv) == FALSE)
			return (ft_putstr_fd("Error\n", 2), EXIT_FAILURE);
		if (check_duplicate(stacks.stack_a) == FALSE || indexer(stacks))
		{
			ft_putstr_fd("Error\n", 2);
			return (stack_cleaner(&stacks.stack_a.head), EXIT_FAILURE);
		}
	}
	else
		return (ft_putstr_fd("Error\n", 2), EXIT_FAILURE);
	if (is_sorted(&stacks.stack_a) == FALSE)
		sorter(&stacks, stacks.stack_a.size);
	stack_cleaner(&stacks.stack_a.head);
	stack_cleaner(&stacks.stack_b.head);
	return (EXIT_SUCCESS);
}
