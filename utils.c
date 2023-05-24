/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:06:08 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/24 16:31:39 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

void	push(stack *s, int value)
{
	if (s->top == STACK_SIZE - 1)
	{
		errormessage();
	}
	s->items[++s->top] = value; // this is wrong, this is why it is incrementing. Or i need to find the
	// lowest number and put that into a different variable
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
	for (int i = 0; i <= s->top; i++) 
		ft_printf("%d ", s->items[i]);
	ft_printf("\n");
}
