/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:06:08 by nvan-den          #+#    #+#             */
/*   Updated: 2023/06/05 14:31:51 by nvan-den         ###   ########.fr       */
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

// debugging purposeses only
void	print_stack(t_stack *s)
{
	ft_printf("Stack a: ");
	for (int i = 0; i <= s->bot; i++)
		ft_printf("%d ", s->items[i]);
	ft_printf("\n");
}

void	print_stackb(t_stack *s)
{
	ft_printf("Stack b: ");
	for (int i = 0; i <= s->bot; i++)
		ft_printf("%d ", s->items[i]);
	ft_printf("\n");
}
