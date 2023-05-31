/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:58:11 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/31 14:57:05 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

void sort_3(stack* a_stack)
{
    if (a_stack->items[0] > a_stack->items[1]) // 1st number is smaller
    {
        if (a_stack->items[0] < a_stack->items[2]) // 213
            sa(a_stack);
        if (a_stack->items[0] > a_stack->items[2])
        {
            if (a_stack->items[1] > a_stack->items[2]) // 321
            {
                sa(a_stack);
                rra(a_stack);
            }
            else // 312
                ra(a_stack);
        }
    }
    else // 1st number is bigger
    {
        if (a_stack->items[0] < a_stack->items[2]) // 132
        {
            sa(a_stack);
            ra(a_stack);
        }
        else // 231
            rra(a_stack);
    }
}

void	push_smallest(stack *a_stack, stack *b_stack)
{
	int	smallest;
	int	smallest_index;
	int	i;

	i = a_stack->bot;
	smallest = INT8_MAX;
	while (i >= 0)
	{
		if (a_stack->items[i] < smallest)
		{
			smallest = a_stack->items[i];
			smallest_index = i;
		}
		i--;
	}
		while (a_stack->items[0] != smallest)
	{
		if (smallest_index <= 2)
			ra(a_stack);
		else
			rra(a_stack);
	}
	pb(a_stack, b_stack);
}

void sort_5(stack* a_stack, stack* b_stack)
{
	int	i;

	i = 0;
	push_smallest(a_stack, b_stack);
	push_smallest(a_stack, b_stack);
	sort_3(a_stack);
	while (peek(b_stack))
			pa(a_stack, b_stack);
}

stack* sort_small_stack(int size, stack* a_stack, stack* b_stack)
{
	if (size == 2)
		sa(a_stack);
    if (size == 3)
        sort_3(a_stack);
	if (size == 4);
	{
		push_smallest(a_stack, b_stack);
		sort_3(a_stack);
		pa;
	}
    if (size == 5)
        sort_5(a_stack, b_stack);
    return a_stack;
}
