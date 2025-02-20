/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:52:49 by miovu             #+#    #+#             */
/*   Updated: 2025/02/17 17:04:07 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*find_cheapest(t_stack *from)
{
	t_node	*temp;
	t_node	*cheapest;

	cheapest = from->head;
	temp = from->head->next;
	while (temp)
	{
		if (cheapest->cost == 0)
			return (cheapest);
		else
		{
			if (cheapest->cost > temp->cost)
				cheapest = temp;
			temp = temp->next;
		}
	}
	return (cheapest);
}

void	move_a(t_stack *from, t_stack *to)
{
	t_node	*temp;

	temp = find_cheapest(from);
	while (temp != from->head)
	{
		if (temp->index <= (from->size / 2))
			rotate_nodes(from, 'a', 1);
		else
			reverse_rotate(from, 'a', 1);
	}
	while (temp->target != to->head)
	{
		if (temp->target->index <= (to->size / 2))
			rotate_nodes(to, 'b', 1);
		else
			reverse_rotate(to, 'b', 1);
	}
}

void	move_b(t_stack *from, t_stack *to)
{
	t_node	*temp;

	temp = find_cheapest(from);
	while (temp != from->head)
	{
		if (temp->index <= (from->size / 2))
			rotate_nodes(from, 'b', 1);
		else
			reverse_rotate(from, 'b', 1);
	}
	while (temp->target != to->head)
	{
		if (temp->target->index <= (to->size / 2))
			rotate_nodes(to, 'a', 1);
		else
			reverse_rotate(to, 'a', 1);
	}
}

void	move_both(t_stack *from, t_stack *to)
{
	t_node	*temp;

	temp = find_cheapest(from);
	if ((temp->index < (from->size / 2))
		&& (temp->target->index < (to->size / 2)))
	{
		while (temp != from->head && temp->target != to->head)
			rotate_both(from, to);
	}
	else if ((temp->index >= (from->size / 2))
		&& (temp->target->index >= (to->size / 2)))
	{
		while (temp != from->head && temp->target != to->head)
			reverse_both(from, to);
	}
}
