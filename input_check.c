/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:47:28 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/12 15:11:23 by nvan-den         ###   ########.fr       */
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
				whitespace = 1;
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

//check if there is whitespace in first argument, then only accept if
//it's the only argument
// hmm what about whitespaces for isdigit

// and other way around. whitespaces can appear ANYWHERE DUM DUM DUM
