/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:39:30 by miovu             #+#    #+#             */
/*   Updated: 2025/02/11 16:38:27 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	sorted_stack(t_stack *stack)
{
	t_node	*checker;
	t_node	*current;

	if (!stack->head)
		return (false);
	current = stack->head;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->content > checker->content)
				return (false);
			else if (current->content < checker->content)
				checker = checker->next;
		}
		current = current->next;
	}
	return (true);
}

void	sort_three(t_stack *stack)
{
	if (stack->head->content < stack->head->next->content
		&& stack->head->next->content > stack->tail->content
		&& stack->head->content < stack->tail->content)
	{
		reverse_rotate(stack, 'a', 1);
		swap_nodes(stack, 'a', 1);
	}
	else if (stack->head->content < stack->head->next->content
		&& stack->head->next->content > stack->tail->content
		&& stack->head->content > stack->tail->content)
		reverse_rotate(stack, 'a', 1);
	else if (stack->head->content > stack->head->next->content
		&& stack->head->next->content < stack->tail->content
		&& stack->head->content < stack->tail->content)
		swap_nodes(stack, 'a', 1);
	else if (stack->head->content > stack->head->next->content
		&& stack->head->next->content > stack->tail->content)
	{
		rotate_nodes(stack, 'a', 1);
		swap_nodes(stack, 'a', 1);
	}
	else if (stack->head->content > stack->head->next->content
		&& stack->head->next->content < stack->tail->content
		&& stack->head->content > stack->tail->content)
		rotate_nodes(stack, 'a', 1);
}

void	sort_two(t_stack *stack)
{
	if (stack->head->content > stack->head->next->content)
		swap_nodes(stack, 'a', 1);
}
