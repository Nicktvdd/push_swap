/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:53:30 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/12 11:56:08 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

//there's different ways of storing the integers. Array, where we use a struct 
//to locate where they are on the map
//or we can assign a number to them, to simplify the sorting

void	errormessage()
{
	write(2, "Error\n", 7);
	exit(0);
}

int	main(int argc, char **argv)
{
	int i;
	int	*array;

	i = 1;
	array = malloc(sizeof(int*) * (argc));
	while (i < argc)
		array[i - 1] = ft_atoi(argv[i++]);
	array[i - 1] = NULL;

	return (0);
}