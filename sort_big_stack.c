/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:22:57 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/31 16:53:42 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"
// index it to negate negatives
// change values to index, but operations on original
// change to bits

void sort_big_stack(stack* a_stack, stack* b_stack)
{
	int size;
	int max_num;
	int max_bits;
	int	i;
	int	j;
	int	num;
	
	size = a_stack->bot;
	max_num = size - 1;
	max_bits = 0;
	i = 0;
	j = 0;
	while ((max_num >> max_bits) != 0) 
		++max_bits;
	while (i < max_bits)
	{
		while (j++ < size)
		{
			num = peek(a_stack);
			if (((num >> i)&1) == 1) 
				ra(a_stack); 
			else 
				pb(a_stack, b_stack);
		}
		j = 0;
		while (peek(b_stack))
			pa(a_stack, b_stack);
		i++;
	}
}
