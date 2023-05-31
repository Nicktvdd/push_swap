/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:22:57 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/31 14:08:44 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

int	find_max_num_digits(stack *a_stack)
{
	int max_num;
	int	num_digits;
	int	i;
	
	max_num = a_stack->items[a_stack->bot];
	num_digits = 0;
	i = a_stack->bot + 1;
	while (i <= a_stack->top)
	{
        if (a_stack->items[i] > max_num)
            max_num = a_stack->items[i];
		i++;	
	}
    while (max_num > 0)
    {
        max_num /= 10;
        num_digits++;
    }
	return (num_digits);
}

void sort_big_stack(stack* a_stack, stack* b_stack)
{
	int	i;
	int	num_digits;
	int	digit;
	int	num;
	int	divisor;

	i = a_stack->bot;
	num_digits = find_max_num_digits(a_stack);
	digit = 1;
    divisor = 1;
	num = 0;

	while (num_digits >= digit)
	{
		while (num <= 9)
		{
			while (i >= 0)
			{
				// Check if the current number belongs to the current number
				if ((a_stack->items[a_stack->top] / divisor) % 10 == num)
				{
					// Push it to stack B and continue with the next int
					pb(a_stack, b_stack);
				}
				else
				{
					ra(a_stack);
				}
				i--;
			}
			i = a_stack->bot;
			num++;
		print_stack(a_stack);
		print_stackb(b_stack);
		}
		while (peek(b_stack))
			pa(a_stack, b_stack);
		divisor *= 10;
		digit++;
		num = 0;
	}
}

