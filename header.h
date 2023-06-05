/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:54:13 by nvan-den          #+#    #+#             */
/*   Updated: 2023/06/05 14:08:51 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define STACK_SIZE 501

# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int	items[STACK_SIZE];
	int	top; 
	int	bot;
}	t_stack;

void	errormessage(void);
void	is_duplicate(t_stack *a_stack);
int		is_valid_input(int argc, char **argv);
int		is_sorted(t_stack *a_stack);
void	sa(t_stack *a_stack);
void	sb(t_stack *b_stack);
void	ss(t_stack *a_stack, t_stack *b_stack);
void	pa(t_stack *a_stack, t_stack *b_stack);
void	pb(t_stack *a_stack, t_stack *b_stack);
void	ra(t_stack *a_stack);
void	rb(t_stack *b_stack);
void	rr(t_stack *a_stack, t_stack *b_stack);
void	rra(t_stack *a_stack);
void	rrb(t_stack *b_stack);
void	rrr(t_stack *a_stack, t_stack *b_stack);
stack	*parse(int argc, char **argv);
void	sort_big_stack(t_stack *a_stack, t_stack *b_stack);
stack	*sort_small_stack(int argc, t_stack *a_stack, t_stack *b_stack);
void	push(t_stack *s, int value);
int		pop(t_stack *s);
int		peek(t_stack *s);
int		is_empty(t_stack *s);
void	print_stack(t_stack *s);
void	print_stackb(t_stack *s);
stack	*create_stack(void);
void	create_index(t_stack *a_stack);

#endif