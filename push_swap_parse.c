/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:47:28 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/11 15:58:34 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	is_sorted(int *a_stack)
{
	int	flag;
	int	i;
	
	flag = 0;
	i = 0;
	while(a_stack[i])
	{
		if (a_stack[i + 1] && (a_stack[i + 1] < a_stack[i]))
			errormessage();
	}
}

void	is_valid_input(int argc, char **argv)
{
	int	flag;
	int	i;
	int	j;
	
	flag = 0;
	if (argc < 2)
		exit (0);
	while (argv[i])
	{
		if (isdigit(argv[i][j]) || argv[i][j] == '-')
			j++;
		i++;
	}
	if (argv[i][j])
		errormessage();
}

//check if there is a duplicate. could also compare ints?
void	is_duplicate(int argc, char **argv)
{
	int	len;
	int i;
	int	j;

	len = 0;
	i = 0;
	j = 0;
	while (i <= (argc / 2))
	{
		while (argv[j])
		{
			if (ft_strlen(argv[i]) > ft_strlen(argv[j]))
				len = ft_strlen(argv[i]);
				if (!ft_strncmp(argv[i], argv[j]))
					errormessage();
			j++;
		}
		j = 0;
		i++;
	}
}

void	is_

int	is_integer()
{
	// could use modofied atoi here where you check if the long is
	// < INT_MAX || > INT_MIN
	// BUT WHAT IF THE RESULT IS 0 BECAUSE INPUT IS 0?
	// -> THEN WE EXIT() IF THERE IS AN ERROR
}

int	parse(int *a)
{
	//put numbers in the stack A if no errors are detected

	//check if the numbers in A are sorted. If so, end the program, call is_a_sorted()

	//if size of a < 5, call function sort small stack(), else call function sort_big_stack()

	
	
}

//after parsing and converting to int, use itoa and the strncmp to compare 
//if it's the same (not a long, or if error happened)