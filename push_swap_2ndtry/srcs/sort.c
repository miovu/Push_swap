/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:52:49 by miovu             #+#    #+#             */
/*   Updated: 2025/02/06 18:01:56 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 4)
		push_nodes(stack_a, stack_b, 'b');
	if (stack_a->size > 4)
	{
		push_nodes(stack_a, stack_b, 'b');
		push_nodes(stack_a, stack_b, 'b');
	}
}
