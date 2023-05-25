/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:06:08 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/25 11:23:13 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

void	push(stack *s, int value)
{
	if (s->bot == STACK_SIZE - 1)
	{
		errormessage();
	}
	s->items[++s->bot] = value; // this was wrong, this is why it is incrementing. Or i need to find the
	// lowest number and put that into a different variable. now it's bot.
}

int	pop(stack *s)
{
	if (s->top == -1)
		errormessage();
	return (s->items[s->top--]);
}

int	peek(stack *s)
{
	if (s->top == -1)
		errormessage();
	return (s->items[s->top--]);
}

int	is_empty(stack *s)
{
	return (s->top == -1);
}

//debugging purposeses only
void	print_stack(stack *s)
{
	ft_printf("Stack: ");
	for (int i = 0; i <= s->bot; i++) 
		ft_printf("%d ", s->items[i]);
	ft_printf("\n");
}
