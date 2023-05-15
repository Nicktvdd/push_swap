/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:53:46 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/15 13:26:16 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

void	sa(stack *a)
{
	if (a->top <1) 
		return;
	int	temp;

	temp = a->items[a->top];
	a->items[a->top] = a->items[a->top];
	a->items[a->top - 1] = temp;
}

void	sb(stack *b)
{
	if (b->top <1) 
		return;
	int	temp;
	
	temp = b->items[b->top];
	b->items[b->top] = b->items[b->top];
	b->items[b->top - 1] = temp;
}

void	ss(stack *a, stack *b)
{
	sa(a);
	sb(b);
}

void	pa(stack *a, stack *b)
{
	if (is_empty(b)) 
		return;
	push(a, pop(b));
}

void	pb(stack *a, stack *b)
{
	if (is_empty(a)) 
		return;
	push(b, pop(a));
}

void	ra(stack *a)
{
	if (a->top < 1) return;
	int	i;
	int	temp;

	i = a->top;
	temp = a->items[a->top];
	while (i > 0)
	{
		a->items[i] = a->items[i - 1];
		i--;
	}
	a->items[0] = temp;
}

void	rb(stack *b)
{
	if (b->top < 1) return;
	int	i;
	int	temp;

	i = b->top;
	temp = b->items[a->top];
	while (i > 0)
	{
		b->items[i] = b->items[i - 1];
		i--;
	}
	b->items[0] = temp;
}

void	rr(stack *a, stack *b)
{
	ra(a);
	rb(b);
}

void	rra(stack *a)
{
	if (a->top < 1)
		return;
	int	i;
	int	temp;
	
	i = 0;
	while (i < a->top)
	{
		a->items[i] = a->items[i + 1];
		i++;
	}
	a->items[a->top] = temp;
}

void	rrb(stack *b)
{
	if (b->top < 1)
		return;
	int	i;
	int	temp;
	
	i = 0;
	while (i < b->top)
	{
		b->items[i] = b->items[i + 1];
		i++;
	}
	b->items[b->top] = temp;
}

void	rrr(stack *a, stack *b)
{
	rra(a);
	rrb(b);
}