/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:53:30 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/17 10:39:53 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

//there's different ways of storing the integers. Array, where we use a struct 
//to locate where they are on the map
//or we can assign a number to them, to simplify the sorting

void	errormessage()
{
	write(2, "Error\n", 7);
	exit(0);
}

int	main(int argc, char **argv)
{
	stack	*a_stack;
	stack	*b_stack;
	
	is_valid_input(argc, argv);
	a_stack = parse(argc, argv);
	b_stack->top = NULL;
	is_sorted(a_stack);
	if (argc < 6)
		sort_small_stack(argc, a_stack, b_stack);
	else
		sort_big_stack(a_stack, b_stack);
	
	
	return (0);
}
