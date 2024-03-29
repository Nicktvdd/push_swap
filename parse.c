/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:14:00 by nvan-den          #+#    #+#             */
/*   Updated: 2023/06/05 14:51:11 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (res > 2147483648)
			errormessage();
	}
	else if (res > 2147483647)
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
		errormessage();
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	check_long(min, res);
	return ((int)res * min);
}

t_stack	*split_args(t_stack *a_stack, char **argv)
{
	int		i;
	char	**buf;
	int		num;

	i = 0;
	buf = ft_split(argv[1], ' ');
	while (buf[i])
	{
		num = ft_atol(buf[i]);
		a_stack->items[++a_stack->bot] = num;
		free(buf[i]);
		i++;
	}
	free(buf);
	return (a_stack);
}

t_stack	*parse(int argc, char **argv)
{
	int		i;
	int		num;
	t_stack	*a_stack;

	i = 1;
	a_stack = create_stack();
	if (argc == 2)
		split_args(a_stack, argv);
	else
	{
		while (i < argc)
		{
			num = ft_atol(argv[i]);
			a_stack->items[++a_stack->bot] = num;
			i++;
		}
	}
	return (a_stack);
}
