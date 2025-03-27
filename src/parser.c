/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:27:38 by crizapat          #+#    #+#             */
/*   Updated: 2025/03/06 16:48:11 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_bool args_checker(int argc, char **argv)
{
	int ic;
	int ia;

	ic = 1;
	while (ic < argc)
	{
		ia = 0;
		if (argv[ic][ia] == '\0')
			return (FALSE);
		while (argv[ic][ia] != '\0')
		{
			if ((argv[ic][ia] == '+' || argv[ic][ia] == '-') && argv[ic][ia + 1] != '\0' && ft_isdigit(argv[ic][ia + 1]))
				ia++;
			if (ft_isdigit(argv[ic][ia]) && (argv[ic][ia + 1] == '+' || argv[ic][ia + 1] == '-'))
				return (FALSE);
			if (argv[ic][ia] != ' ' && !ft_isdigit(argv[ic][ia]))
				return (FALSE);
			ia++;
		}
		ic++;	
}
	return (TRUE);
}


