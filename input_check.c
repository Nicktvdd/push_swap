/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:47:28 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/17 13:44:10 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header.h"

int	is_sorted(stack *a_stack)
{
	int	i;

	i = 0;
	while (i < a_stack->top) 
	{
		if (a_stack->items[i] > a_stack->items[i + 1])
			return (0);
		i++;
	}
	errormessage();
}
//checks for enough inputs
//if everything is a digit
//if there is whitespace in one of the arguments, it only accepts one argument
void	is_valid_input(int argc, char **argv)
{
	int	whitespace;
	int	i;
	int	j;
	
	whitespace = 0;
	i = 0;
	j = 0;
	if (argc < 2)
		exit (0);
	while (argv[i])
	{
		while (isdigit(argv[i][j]) || argv[i][j] == '-' || argv[i][j] == ' ')
		{
			if (argv[i][j] == ' ')
				whitespace++;
			if (whitespace > 1 && argc > 2)
				errormessage();
			j++;
		}
		i++;
	}
	if (argv[i][j])
		errormessage();
}

//check if there is a duplicate. could also compare ints?
void	is_duplicate(stack *a_stack)
{
    int i;
    int j;

	i = 0;
	j = 0;
    while (i <= (a_stack->top / 2)) 
	{
        j = 0;
        while (j <= a_stack->top) 
		{
			if (a_stack->items[i] == a_stack->items[j])
				errormessage();
            j++;
        }
        i++;
    }
}
