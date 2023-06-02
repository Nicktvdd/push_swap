/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:47:28 by nvan-den          #+#    #+#             */
/*   Updated: 2023/06/02 14:48:09 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

int	is_sorted(stack *a_stack)
{
	int	i;

	i = 0;
	while (i < a_stack->bot) 
	{
		if (a_stack->items[i] > a_stack->items[i + 1])
			return (0);
		i++;
	}
	return (1);
}
//checks for enough inputs
//if everything is a digit
//if there is whitespace in one of the arguments, it only accepts one argument
int	is_valid_input(int argc, char **argv)
{
	int	whitespace;
	int	i;
	int	j;
	
	whitespace = 0;
	i = 1;
	j = 0;
	if (argc < 2)
		exit (0);
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) || argv[i][j] == '-' || argv[i][j] == ' ')
			{
				if (argv[i][j] == '-' && !ft_isdigit(argv[i][j+1]))
					errormessage();
				if (argv[i][j] == ' ')
					whitespace++;
				if (whitespace > 1 && argc > 2)
					errormessage();
			}
			else
				errormessage();
			j++;
		}
		if (argv[i][j - 1] == ' ')
			whitespace--;
		j = 0;
		i++;
	}
	return (whitespace + 1);
}

void	is_duplicate(stack *a_stack)
{
    int i;
    int j;

	i = 0;
	j = (i + 1);
    while (a_stack->items[i]) 
	{
        j = (i + 1);
        while (a_stack->items[j]) 
		{
			if (a_stack->items[i] == a_stack->items[j])
				errormessage();
            j++;
        }
        i++;
    }
}
