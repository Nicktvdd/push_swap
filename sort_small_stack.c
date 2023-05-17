/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:58:11 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/16 12:18:15 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

int	*sort_small_stack(int stack_size, int *a_stack)
{
	if (stack_size == 3)
		sort_3(a_stack);
	if (stack_size == 5)
		sort_5(a_stack);
}

void	sort_3(int *a_stack)
{
	if (a_stack[0] > a_stack[1]) //1st number is smaller
	{	
		if (a_stack[0] < a_stack[2]) //213
			sa(a_stack);
		if (a_stack[0] > a_stack[2]) 
		{	
			if (a_stack[1] > a_stack[2]) //321
			{
				sa(a_stack);
				rra(a_stack);
			}
			else // 312
				ra(a_stack);
		}
	}
	else //1st number is bigger
	{
		if (a_stack[1] > a_stack[2]) //132
		{
			sa(a_stack);
			ra(a_stack);
		}
		else //231
			rra(a_stack);
	}
}

void	sort_5(int *a_stack, int *b_stack)
{
		int	value;

	while (!is_empty(a))
	{
		value = pop(a);
		if (is_empty(b) || peek(b) >= value)
			push(b, value);
		else
		{
			while (!isempty(b) && peek(b) < value)
				pa(a, b);
			push(b, value);
		}
	}
	while (!is_empty(b))
		pa(a, b);
	
}
