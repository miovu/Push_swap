/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillhoneyyy <chillhoneyyy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:49:02 by miovu             #+#    #+#             */
/*   Updated: 2025/02/08 16:09:17 by chillhoneyy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node *smallest_node(t_stack *stack)
{
	t_node	*temp;
	t_node	*smallest;
	int		small;
	
	smallest = stack->head;
	small = stack->head->content;
	if (!stack->head)
		return (NULL);
	temp = stack->head;
	while (temp->next)
	{
		if (temp->content > temp->next->content
			&& small > temp->next->content)
		{
			smallest = temp->next;
			small = temp->next->content;
		}
		temp = temp->next;
	}
	return (smallest);
}

t_node *highest_node(t_stack *stack)
{
	t_node	*temp;
	t_node	*highest;
	int		high;
	
	highest = stack->head;
	high = stack->head->content;
	if (!stack->head)
		return (NULL);
	temp = stack->head;
	while (temp->next)
	{
		if (temp->content < temp->next->content
			&& high < temp->next->content)
		{
			highest = temp->next;
			high = temp->next->content;
		}
		temp = temp->next;
	}
	return (highest);
}

void	target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp_a;
	t_node	*temp_b;
	long	small;
	
	if (!stack_a->head || !stack_b->head)
		return ;
	temp_a = stack_a->head;
	while (temp_a)
	{
		small = LONG_MIN;
		temp_b = stack_b->head;
		while (temp_b)
		{
			if (temp_a->content > temp_b->content
				&& small < temp_b->content)
			{
				small = temp_b->content;
				temp_a->target = temp_b;
			}
			temp_b = temp_b->next;
		}
		if (small == LONG_MIN)
			temp_a->target = highest_node(stack_b);
		temp_a = temp_a->next;
	}
}

void	target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp_a;
	t_node	*temp_b;
	long	big;

	if (!stack_a->head || !stack_b->head)
		return;
	temp_b = stack_b->head;
	while (temp_b)
	{
		big = LONG_MAX;
		temp_a = stack_a->head;
		while (temp_a)
		{
			if (temp_b->content < temp_a->content
				&& big > temp_a->content)
			{
				big = temp_a->content;
				temp_b->target = temp_a;
			}
			temp_a = temp_a->next;
		}
		if (big == LONG_MAX)
			temp_b->target = smallest_node(stack_a);
		temp_b = temp_b->next;
	}
}
