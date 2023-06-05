/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:36:11 by nvan-den          #+#    #+#             */
/*   Updated: 2023/06/05 14:37:20 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

void	sb(t_stack *b_stack)
{
	int	temp;

	if (b_stack->bot < 1)
		return ;
	temp = b_stack->items[b_stack->top];
	b_stack->items[b_stack->top] = b_stack->items[b_stack->top + 1];
	b_stack->items[b_stack->top + 1] = temp;
	ft_printf("%s\n", __func__);
}

void	pb(t_stack *a_stack, t_stack *b_stack)
{
	int	i;

	i = 0;
	if (is_empty(a_stack))
		return ;
	push(b_stack, pop(a_stack));
	while (i <= a_stack->bot)
	{
		a_stack->items[i] = a_stack->items[i + 1];
		i++;
	}
	ft_printf("%s\n", __func__);
}

void	rb(t_stack *b_stack)
{
	int	i;
	int	temp;

	if (b_stack->bot < 0)
		return ;
	i = 0;
	temp = b_stack->items[b_stack->top];
	while (i < b_stack->bot)
	{
		b_stack->items[i] = b_stack->items[i + 1];
		i++;
	}
	b_stack->items[b_stack->bot] = temp;
	ft_printf("%s\n", __func__);
}

void	rrb(t_stack *b_stack)
{
	int	i;
	int	temp;

	if (b_stack->top < 0)
		return ;
	i = b_stack->bot;
	temp = b_stack->items[b_stack->bot];
	while (i > b_stack->top)
	{
		b_stack->items[i] = b_stack->items[i - 1];
		i--;
	}
	b_stack->items[b_stack->top] = temp;
	ft_printf("%s\n", __func__);
}
