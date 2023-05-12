/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:58:11 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/12 12:26:50 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sorting_3(int *a_stack)
{
	if (a_stack[0] > a_stack[1]) //1st number is smaller
	{	
		if (a_stack[0] < a_stack[2]) //213
			sa(a_stack);
		if (a_stack[0] > a_stack[2]) 
		{	
			if (a_stack[1] > a_stack[2]) //321
			{
				sa(a_stack);
				rra(a_stack);
			}
			else // 312
				ra(a_stack);
		}
	}
	else //1st number is bigger
	{
		if (a_stack[1] > a_stack[2]) //132
		{
			sa(a_stack);
			ra(a_stack);
		}
		else //231
			rra(a_stack);
	}
}
