/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:22:57 by nvan-den          #+#    #+#             */
/*   Updated: 2023/06/05 14:59:02 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

// check when you return to a from b if the next bit is 1 so that it stays in b

void	sort_to_b(int i, int size, t_stack *a_stack, t_stack *b_stack)
{
	int	j;
	int	num;

	j = 0;
	while (j++ <= size)
	{
		num = peek(a_stack);
		if (((num >> i) & 1) == 1)
			ra(a_stack);
		else
			pb(a_stack, b_stack);
	}
}

void	sort_big_stack(t_stack *a_stack, t_stack *b_stack)
{
	int	size;
	int	max_num;
	int	max_bits;
	int	i;

	size = a_stack->bot;
	max_num = size - 1;
	max_bits = 0;
	i = 0;
	create_index(a_stack);
	while ((max_num >> max_bits) != 0)
		++max_bits;
	while (i < max_bits)
	{
		sort_to_b(i, size, a_stack, b_stack);
		while (peek(b_stack))
			pa(a_stack, b_stack);
		i++;
	}
}
