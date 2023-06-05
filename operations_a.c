/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:53:46 by nvan-den          #+#    #+#             */
/*   Updated: 2023/06/05 14:37:51 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

void	sa(t_stack *a_stack)
{
	int	temp;

	if (a_stack->bot < 1)
		return ;
	temp = a_stack->items[a_stack->top];
	a_stack->items[a_stack->top] = a_stack->items[a_stack->top + 1];
	a_stack->items[a_stack->top + 1] = temp;
	ft_printf("%s\n", __func__);
}

void	pa(t_stack *a_stack, t_stack *b_stack)
{
	int	i;

	i = 0;
	if (is_empty(b_stack))
		return ;
	push(a_stack, pop(b_stack));
	while (i <= b_stack->bot)
	{
		b_stack->items[i] = b_stack->items[i + 1];
		i++;
	}
	ft_printf("%s\n", __func__);
}

void	ra(t_stack *a_stack)
{
	int	i;
	int	temp;

	if (a_stack->bot < 0)
		return ;
	i = 0;
	temp = a_stack->items[a_stack->top];
	while (i < a_stack->bot)
	{
		a_stack->items[i] = a_stack->items[i + 1];
		i++;
	}
	a_stack->items[a_stack->bot] = temp;
	ft_printf("%s\n", __func__);
}

void	rra(t_stack *a_stack)
{
	int	i;
	int	temp;

	if (a_stack->top < 0)
		return ;
	i = a_stack->bot;
	temp = a_stack->items[a_stack->bot];
	while (i > a_stack->top)
	{
		a_stack->items[i] = a_stack->items[i - 1];
		i--;
	}
	a_stack->items[a_stack->top] = temp;
	ft_printf("%s\n", __func__);
}
