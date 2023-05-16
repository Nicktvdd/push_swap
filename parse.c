/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:14:00 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/16 12:04:03 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// modified atoi here where you check if the long is
	// < INT_MAX || > INT_MIN
	// BUT WHAT IF THE RESULT IS 0 BECAUSE INPUT IS 0?
	// -> THEN WE EXIT() IF THERE IS AN ERROR
#include "./header.h"

int	ft_overflow(int min)
{
	if (min == -1)
		return (0);
	else
		return (-1);
}

void	check_long(int min, long res)
{
	if (min < 0)
	{
		if (res == 2147483648)
			errormessage();
	}
		if (res > 2147483647)
			errormessage();
}

int	ft_atol(const char *str)
{
	int		i;
	long	res;
	int		min;

	i = 0;
	res = 0;
	min = 1;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-')
	{
		min = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (str[i] == '+' || str[i] == '-')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i++] - '0');
		if (res < 0)
				return (ft_overflow(min));
	}
	check_long(min, res);
	return ((int)res * min);
}

int	parse(int argc, char** argv)
{
	//put numbers in the stack A if no errors are detected

	//check if the numbers in A are sorted. If so, end the program, call is_a_sorted()

	int		i;
	int		num;
	stack 	a_stack;
	stack	b_stack;
	
	i = 0;

	while (i < argc)
	{
		num = ft_atol(argv[i]);
		push(&a_stack, num);
	}

	b_stack.top = NULL;
	
	//if size of a < 5, call function sort small stack(), else call function sort_big_stack()
	
	
}

//after parsing and converting to int, use itoa and the strncmp to compare 
//if it's the same (not a long, or if error happened)