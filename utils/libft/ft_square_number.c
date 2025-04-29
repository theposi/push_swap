/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:49:50 by crizapat          #+#    #+#             */
/*   Updated: 2025/04/29 10:54:02 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_square_number(int number)
{
	size_t i;

	if (number == 0)
		return (0);
	i = 1;
	while (i * i <= number)
		i++;
	return (i - 1);
}
