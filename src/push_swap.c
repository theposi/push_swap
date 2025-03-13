/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:30:40 by crizapat          #+#    #+#             */
/*   Updated: 2025/03/13 17:07:42 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int argc, char **argv)
{
	int i;	

	if(argc == 1)
	{
		printf("Not enough parameters\n");
		exit(EXIT_FAILURE);
	}
	else {
		i = 0;
		while(i < argc)
		{
			printf("Argument: %d, position %d\n", ft_atoi(argv[i]), i);
			i++;
		}
	}
	return (0);
}
