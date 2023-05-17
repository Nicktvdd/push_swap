/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:54:13 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/17 14:12:55 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define STACK_SIZE 500

#include <stdlib.h>
#include "./libft/libft.h"

typedef struct s_stack
{
	int	items[STACK_SIZE];
	int	top;
}	stack;

void	errormessage();
void	is_duplicate(stack *a_stack);
void	is_valid_input(int argc, char **argv);
int		is_sorted(stack *a_stack);
void 	sa(stack *a_stack);
void 	sb(stack *b_stack);
void 	ss(stack *a_stack, stack *b_stack);
void 	pa(stack *a_stack, stack *b_stack);
void 	pb(stack *a_stack, stack *b_stack);
void 	ra(stack *a_stack);
void 	rb(stack *b_stack);
void 	rr(stack *a_stack, stack *b_stack);
void 	rra(stack *a_stack);
void 	rrb(stack *b_stack);
void 	rrr(stack *a_stack, stack *b_stack);
stack	*parse(int argc, char** argv);
void	sort_big_stack(stack *a);
stack	*sort_small_stack(int argc, stack *a_stack, stack *b_stack);
void	push(stack *s, int value);
int		pop(stack *s);
int		peek(stack *s);
int		is_empty(stack *s);
void	print_stack(stack *s);
