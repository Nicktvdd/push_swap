/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:53:46 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/19 11:32:08 by nvan-den         ###   ########.fr       */
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
	ft_printf("%s\n", __func__);
}

void	sb(stack *b_stack)
{
	if (b_stack->top <1) 
		return;
	int	temp;
	
	temp = b_stack->items[b_stack->top];
	b_stack->items[b_stack->top] = b_stack->items[b_stack->top];
	b_stack->items[b_stack->top - 1] = temp;
	ft_printf("%s\n", __func__);
}

void	ss(stack *a_stack, stack *b_stack)
{
	sa(a_stack);
	sb(b_stack);
	ft_printf("%s\n", __func__);
}

void	pa(stack *a_stack, stack *b_stack)
{
	if (is_empty(b_stack)) 
		return;
	push(a_stack, pop(b_stack));
	ft_printf("%s\n", __func__);
}

void	pb(stack *a_stack, stack *b_stack)
{
	if (is_empty(a_stack)) 
		return;
	push(b_stack, pop(a_stack));
	ft_printf("%s\n", __func__);
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
	ft_printf("%s\n", __func__);
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
	ft_printf("%s\n", __func__);
}

void	rr(stack *a_stack, stack *b_stack)
{
	ra(a_stack);
	rb(b_stack);
	ft_printf("%s\n", __func__);
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
	ft_printf("%s\n", __func__);
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
	ft_printf("%s\n", __func__);
}

void	rrr(stack *a_stack, stack *b_stack)
{
	rra(a_stack);
	rrb(b_stack);
	ft_printf("%s\n", __func__);
}