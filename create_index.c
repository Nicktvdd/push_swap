/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:31:47 by nvan-den          #+#    #+#             */
/*   Updated: 2023/06/01 13:23:26 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

void swap(stack* stk, int i, int j)
{
    int temp = stk->items[i];
    stk->items[i] = stk->items[j];
    stk->items[j] = temp;
}

int partition(stack* stk, int low, int high)
{
    int pivot = stk->items[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (stk->items[j] <= pivot)
        {
            i++;
            swap(stk, i, j);
        }
    }

    swap(stk, i + 1, high);
    return i + 1;
}

void quicksort_stack(stack* stk, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(stk, low, high);
        quicksort_stack(stk, low, pivot - 1);
        quicksort_stack(stk, pivot + 1, high);
    }
}

void	index_stack(stack *a_stack, stack temp_stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= a_stack->bot)
	{
		while (a_stack->items[i] != temp_stack.items[j])
			j++;
		a_stack->items[i] = (j + 1);
		i++;
		j = 0;
	}
}

void	create_index(stack *a_stack)
{
	stack	temp_stack;

	temp_stack = *a_stack;
	quicksort_stack(&temp_stack, temp_stack.top, temp_stack.bot);
	index_stack(a_stack, temp_stack);
}