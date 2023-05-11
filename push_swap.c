/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:53:30 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/11 13:47:46 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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