/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:53:30 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/03 11:39:34 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	errormessage()
{
	write(2, "Error\n", 7);
	exit(0);
}

int	errorcheck(int argc, char **argv)
{
	int	flag;
	int	i;
	int	j;
	
	flag = 0;
	if (argc < 2)
	{
		write(1, *argv, 17);
		exit (0);
	}
	while (argv[i])
	{
		while(argv[i][j] >= 48 && argv[i][j] <= 57)
			j++;
		i++;
	}
	if (argv[i][j])
		errormessage();
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