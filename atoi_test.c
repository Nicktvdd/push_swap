#include <stdio.h>
#include <stdlib.h>

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
			exit(1);
	}
		if (res > 2147483647)
			exit(1);
}

int	ft_atoi(const char *str)
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

int	main(int argc, char **argv)
{
	printf("atoi is: %i\n", ft_atoi(argv[1]));
	return (0);
}