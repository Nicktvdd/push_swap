/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:53:30 by nvan-den          #+#    #+#             */
/*   Updated: 2023/06/05 14:31:16 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

// there's different ways of storing the integers. Array, where we use a struct
// to locate where they are on the map
// or we can assign a number to them, to simplify the sorting

void	errormessage(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	int		argnum;

	argnum = is_valid_input(argc, argv);
	a_stack = parse(argc, argv);
	b_stack = create_stack();
	is_duplicate(a_stack);
	if (is_sorted(a_stack))
		exit(0);
	if (argc == 2)
	{
		if (argnum <= 1)
			exit(0);
		if (argnum < 6)
			sort_small_stack(argnum, a_stack, b_stack);
		else
			sort_big_stack(a_stack, b_stack);
	}
	else if (argc < 7)
		sort_small_stack((argc - 1), a_stack, b_stack);
	else
		sort_big_stack(a_stack, b_stack);
	free(a_stack);
	free(b_stack);
	return (0);
}
