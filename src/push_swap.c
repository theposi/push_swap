/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:30:40 by crizapat          #+#    #+#             */
/*   Updated: 2025/03/27 11:20:17 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
