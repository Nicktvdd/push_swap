/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:06:08 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/25 15:24:16 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

void	push(stack *s, int value)
{
	int	i;

	i = s->bot++;
	if (s->bot == STACK_SIZE - 1)
		errormessage();
	while (i >= s->top)
	{
		s->items[i + 1] = s->items[i];
		i--;
	}
	s->items[s->top] = value; // this was wrong, this is why it is incrementing. Or i need to find the
	// lowest number and put that into a different variable. now it's bot.
}

int	pop(stack *s)
{
	if (s->top == s->bot)
		errormessage();
	s->bot--;
	return (s->items[s->top]);
}

int	peek(stack *s)
{
	if (s->top == s->bot)
		errormessage();
	return (s->items[s->top]);
}

int	is_empty(stack *s)
{
	return (s->top == -1);
}

//debugging purposeses only
void	print_stack(stack *s)
{
	ft_printf("Stack a: ");
	for (int i = 0; i <= s->bot; i++) 
		ft_printf("%d ", s->items[i]);
	ft_printf("\n");
}

void	print_stackb(stack *s)
{
	ft_printf("Stack b: ");
	for (int i = 0; i <= s->bot; i++) 
		ft_printf("%d ", s->items[i]);
	ft_printf("\n");
}