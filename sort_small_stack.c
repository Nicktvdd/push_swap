/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:58:11 by nvan-den          #+#    #+#             */
/*   Updated: 2023/06/05 14:32:21 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

void	sort_3(t_stack *a_stack)
{
	if (a_stack->items[0] > a_stack->items[1])
	{
		if (a_stack->items[0] < a_stack->items[2])
			sa(a_stack);
		if (a_stack->items[0] > a_stack->items[2])
		{
			if (a_stack->items[1] > a_stack->items[2])
			{
				sa(a_stack);
				rra(a_stack);
			}
			else
				ra(a_stack);
		}
	}
	else
	{
		if (a_stack->items[0] < a_stack->items[2])
		{
			sa(a_stack);
			ra(a_stack);
		}
		else
			rra(a_stack);
	}
}

void	push_smallest(t_stack *a_stack, t_stack *b_stack)
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

void	sort_5(t_stack *a_stack, t_stack *b_stack)
{
	int	i;

	i = 0;
	push_smallest(a_stack, b_stack);
	push_smallest(a_stack, b_stack);
	if (!is_sorted(a_stack))
		sort_3(a_stack);
	while (peek(b_stack))
		pa(a_stack, b_stack);
}

t_stack	*sort_small_stack(int size, t_stack *a_stack, t_stack *b_stack)
{
	create_index(a_stack);
	if (size == 2)
		sa(a_stack);
	if (size == 3)
		sort_3(a_stack);
	if (size == 4)
	{
		push_smallest(a_stack, b_stack);
		if (!is_sorted(a_stack))
			sort_3(a_stack);
		pa(a_stack, b_stack);
	}
	if (size == 5)
		sort_5(a_stack, b_stack);
	return (a_stack);
}
