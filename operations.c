/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:53:46 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/17 13:59:56 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

void	sa(stack *a_stack)
{
	if (a_stack->top <1) 
		return;
	int	temp;

	temp = a_stack->items[a_stack->top];
	a_stack->items[a_stack->top] = a_stack->items[a_stack->top];
	a_stack->items[a_stack->top - 1] = temp;
}

void	sb(stack *b_stack)
{
	if (b_stack->top <1) 
		return;
	int	temp;
	
	temp = b_stack->items[b_stack->top];
	b_stack->items[b_stack->top] = b_stack->items[b_stack->top];
	b_stack->items[b_stack->top - 1] = temp;
}

void	ss(stack *a_stack, stack *b_stack)
{
	sa(a_stack);
	sb(b_stack);
}

void	pa(stack *a_stack, stack *b_stack)
{
	if (is_empty(b_stack)) 
		return;
	push(a_stack, pop(b_stack));
}

void	pb(stack *a_stack, stack *b_stack)
{
	if (is_empty(a_stack)) 
		return;
	push(b_stack, pop(a_stack));
}

void	ra(stack *a_stack)
{
	if (a_stack->top < 1) return;
	int	i;
	int	temp;

	i = a_stack->top;
	temp = a_stack->items[a_stack->top];
	while (i > 0)
	{
		a_stack->items[i] = a_stack->items[i - 1];
		i--;
	}
	a_stack->items[0] = temp;
}

void	rb(stack *b_stack)
{
	if (b_stack->top < 1) return;
	int	i;
	int	temp;

	i = b_stack->top;
	temp = b_stack->items[b_stack->top];
	while (i > 0)
	{
		b_stack->items[i] = b_stack->items[i - 1];
		i--;
	}
	b_stack->items[0] = temp;
}

void	rr(stack *a_stack, stack *b_stack)
{
	ra(a_stack);
	rb(b_stack);
}

void	rra(stack *a_stack)
{
	if (a_stack->top < 1)
		return;
	int	i;
	int	temp;
	
	i = 0;
	temp = a_stack->items[0];
	while (i < a_stack->top)
	{
		a_stack->items[i] = a_stack->items[i + 1];
		i++;
	}
	a_stack->items[a_stack->top] = temp;
}

void	rrb(stack *b_stack)
{
	if (b_stack->top < 1)
		return;
	int	i;
	int	temp;
	
	i = 0;
	temp = b_stack->items[0];
	while (i < b_stack->top)
	{
		b_stack->items[i] = b_stack->items[i + 1];
		i++;
	}
	b_stack->items[b_stack->top] = temp;
}

void	rrr(stack *a_stack, stack *b_stack)
{
	rra(a_stack);
	rrb(b_stack);
}