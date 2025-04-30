/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:27:38 by crizapat          #+#    #+#             */
/*   Updated: 2025/04/11 12:33:33 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	args_checker(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			return (FALSE);
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] == '+' || argv[i][j] == '-')
				&& argv[i][j + 1] != '\0' && ft_isdigit(argv[i][j + 1]))
				j++;
			if (ft_isdigit(argv[i][j]) && (argv[i][j + 1] == '+'
				|| argv[i][j + 1] == '-'))
				return (FALSE);
			if (argv[i][j] != ' ' && !ft_isdigit(argv[i][j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

