/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:22:57 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/31 14:44:21 by nvan-den         ###   ########.fr       */
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
	i = 0;
	while (i <= a_stack->bot)
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
				if (!(a_stack->items[a_stack->top] / divisor))
					pb(a_stack, b_stack);
				else
					ra(a_stack);
				i--;
			}
			i = a_stack->bot;
			while (i >= 0)
			{
				if ((a_stack->items[a_stack->top] / divisor) % 10 == num)
					pb(a_stack, b_stack);
				else
					ra(a_stack);
				i--;
			}
			i = a_stack->bot;
			num++;
/* 		print_stack(a_stack);
		print_stackb(b_stack); */
		}
		while (peek(b_stack))
			pa(a_stack, b_stack);
		divisor *= 10;
		digit++;
		num = 0;
	}
}

