/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:06:08 by nvan-den          #+#    #+#             */
/*   Updated: 2023/06/05 14:44:17 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

void	push(t_stack *s, int value)
{
	int	i;

	if (s->bot == STACK_SIZE + 1)
		errormessage();
	i = s->bot++;
	while (i >= s->top) 
	{
		s->items[i + 1] = s->items[i];
		i--;
	}
	s->items[s->top] = value;
}


int	pop(t_stack *s)
{
	if (s->bot == -1)
		return (0);
	s->bot--;
	return (s->items[s->top]);
}

int	peek(t_stack *s)
{
	if (s->bot == -1)
		return (0);
	return (s->items[s->top]);
}

int	is_empty(t_stack *s)
{
	return (s->top == -1);
}

t_stack	*create_stack(void)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (new_stack == NULL)
		errormessage();
	new_stack->top = 0;
	new_stack->bot = -1;
	return (new_stack);
}
