/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:22:57 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/15 15:29:46 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

void	sort_big_stack(stack *a, stack *b)
{
    stack buckets[10];
    int max_value;
	int	digit;

	max_value = find_max_value(a);
	digit = 1;
	memset(buckets, 0, sizeof(buckets));
    distribute_elements(a, buckets);
    sort_by_digit(buckets, digit, max_value);
    move_elements_to_a(a, buckets);
}

int	find_max_value(stack *a)
{
    int max_value;
	int value;
	
	max_value = peek(a);
    while (!is_empty(a))
	{
        value = pop(a);
        if (value > max_value)
		{
            max_value = value;
        }
        push(a, value);
    }
    return max_value;
}

void	distribute_elements(stack *a, stack *buckets)
{
	int value;
	
    while (!is_empty(a))
	{
        value = pop(a);
        push(&buckets[value % 10], value);
    }
}

void	sort_by_digit(stack *buckets, int *digit, int max_value)
{
    while (max_value / (*digit) > 0)
	{
        int i;
		
		i = 0;
        while (i < 10)
		{
            if (!is_empty(&buckets[i]))
			{
                int value = pop(&buckets[i]);
                push(&buckets[(value / (*digit)) % 10], value);
            }
			else
                i++;
        }
        (*digit) *= 10;
    }
}

void	move_elements_to_a(stack *a, stack *buckets)
{
    int i;
		
	i = 0;
    while (i < 10)
	{
        if (!is_empty(&buckets[i]))
            push(a, pop(&buckets[i]));
		else
            i++;
    }
}