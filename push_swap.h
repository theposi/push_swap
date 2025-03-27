/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crizapat <crizapat@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:28:39 by crizapat          #+#    #+#             */
/*   Updated: 2025/03/27 11:22:18 by crizapat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include  "./utils/libft/libft.h"
# include  "./utils/ft_printf/ft_printf.h"
# include  <unistd.h>
# include  <stdio.h>
# include  <stdlib.h>
# include  <limits.h>

typedef	int	t_bool;
#define TRUE 0
#define FALSE 1

typedef struct s_node {
	size_t			index;
	int				number;
	struct s_node	*next;
} t_node;

typedef struct s_stack {
	size_t			size;
	t_node			*node;
} t_stack;

t_bool args_checker(int argc, char **argv);

#endif 
