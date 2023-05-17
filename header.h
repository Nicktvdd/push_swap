/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:54:13 by nvan-den          #+#    #+#             */
/*   Updated: 2023/05/16 12:11:00 by nvan-den         ###   ########.fr       */
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