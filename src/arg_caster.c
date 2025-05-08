/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 11:20:45 by crizapat          #+#    #+#             */
/*   Updated: 2025/04/11 12:41:40 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	ft_atoi_limits_checker(const char *str, int *result, int *str_index)
{
	int		sign;
	long	temp_result;

	sign = 1;
	temp_result = 0;
	while (ft_is_space(str[*str_index]))
		*str_index += 1;
	if (str[*str_index] == '-')
		sign = -1;
	if (str[*str_index] == '-' || str[*str_index] == '+')
		*str_index += 1;
	while (ft_isdigit(str[*str_index]))
	{
		temp_result = (temp_result * 10) + str[*str_index] - '0';
		if ((sign == 1 && temp_result > (long)INT_MAX)
			|| (sign == -1 && - temp_result < (long)INT_MIN))
			return (FALSE);
		*str_index += 1;
	}
	*result = temp_result * sign;
	return (TRUE);
}

t_bool check_duplicate(t_stack stack_a)
{
	t_node *node_iterator;
	t_node *temp_node;

	node_iterator = stack_a.head;
	while (node_iterator != NULL && node_iterator->next != NULL)
	{
		temp_node = node_iterator->next;
		while (temp_node != NULL)
		{
			if (node_iterator->number == temp_node->number)
				return (FALSE);
			temp_node = temp_node->next;
		}
		node_iterator = node_iterator->next;
	}
	return (TRUE);
}

