/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:22:57 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/26 15:38:47 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

 void sort_big_stack(stack* a_stack, stack* b_stack)
{
    // Sort the first 20 numbers using insertion sort
    for (int i = 0; i < 20; i++)
    {
        while (a_stack->top > i)
        {
            if (a_stack->items[a_stack->top] > a_stack->items[a_stack->top - 1])
                sa(a_stack);
            ra(a_stack);
        }
    }

    // Push the largest 20 numbers to stack B
    for (int i = 0; i < 20; i++)
        pb(a_stack, b_stack);

    // Sort the remaining 80 numbers using selection sort
    for (int i = 0; i < 80; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < 100; j++)
        {
            if (a_stack->items[j] < a_stack->items[min_idx])
                min_idx = j;
        }
        while (min_idx < a_stack->top)
        {
            if (min_idx < a_stack->top - min_idx)
                ra(a_stack);
            else
                rra(a_stack);
        }
        pb(a_stack, b_stack);
    }

    // Push back the sorted numbers from stack B to stack A
    while (b_stack->top != -1)
        pa(a_stack, b_stack);
}


