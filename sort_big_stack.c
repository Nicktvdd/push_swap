/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:22:57 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/31 16:46:15 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"
// index it to negate negatives
// change values to index, but operations on original
// change to bits

void sort_big_stack(stack* a_stack, stack* b_stack)
{
	int size;
	int max_num; // the biggest number in a is stack_size - 1
	int max_bits; // how many bits for max_num 
	int	i;
	int	j;
	
	size = a_stack->bot;
	max_num = size - 1;
	max_bits = 0;
	i = 0;
	j = 0;
	while ((max_num >> max_bits) != 0) 
		++max_bits;
	while (i < max_bits) // repeat for max_bits times
	{
		while (j < size)
		{
			int num = peek(a_stack); // top number of A
			if (((num >> i)&1) == 1) ra(a_stack); 
			// if the (i + 1)-th bit is 1, leave in stack a
			else pb(a_stack, b_stack);
			// otherwise push to stack b
			j++;
		}
		j = 0;
		// put into boxes done
		while (peek(b_stack))
			pa(a_stack, b_stack); // while stack b is not empty, do pa
		
		// connect numbers done
		i++;
	}
}
