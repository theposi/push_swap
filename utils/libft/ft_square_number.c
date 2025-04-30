/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:55:46 by crizapat          #+#    #+#             */
/*   Updated: 2025/04/26 14:04:47 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_square_number(int number)
{
	int	i;

	if (number == 0)
		return (0);
	i = 1;
	while (i * i <= number)
		i++;
	return (i - 1);
}
