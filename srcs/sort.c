/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:23:11 by miovu             #+#    #+#             */
/*   Updated: 2025/02/17 17:08:50 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	give_values(t_stack *stack_a, t_stack *stack_b)
{
	index_value(stack_a);
	index_value(stack_b);
	target_a(stack_a, stack_b);
	cost_operation(stack_a, stack_b);
	target_b(stack_a, stack_b);
	cost_operation(stack_b, stack_a);
}

void	send_nodes(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 4)
		push_nodes(stack_a, stack_b, 'b');
	if (stack_a->size > 4)
	{
		push_nodes(stack_a, stack_b, 'b');
		push_nodes(stack_a, stack_b, 'b');
	}
}

void	final_sort(t_stack *stack)
{
	t_node	*temp;

	temp = smallest_node(stack);
	while (temp != stack->head)
	{
		if (temp->index < (stack->size / 2))
			rotate_nodes(stack, 'a', 1);
		else if (temp->index >= (stack->size / 2))
			reverse_rotate(stack, 'a', 1);
	}
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (sorted_stack(stack_a))
		return ;
	if (stack_a->size == 2)
		sort_two(stack_a);
	if (stack_a->size == 3)
		sort_three(stack_a);
	send_nodes(stack_a, stack_b);
	while (!sorted_stack(stack_a) && stack_a->size > 3)
	{
		give_values(stack_a, stack_b);
		move_both(stack_a, stack_b);
		move_a(stack_a, stack_b);
		push_nodes(stack_a, stack_b, 'b');
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
	{
		give_values(stack_a, stack_b);
		move_both(stack_b, stack_a);
		move_b(stack_b, stack_a);
		push_nodes(stack_b, stack_a, 'a');
	}
	index_value(stack_a);
	final_sort(stack_a);
}
