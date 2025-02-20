/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:52:49 by miovu             #+#    #+#             */
/*   Updated: 2025/02/13 17:43:11 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	index_value(t_stack *stack)
{
	t_node	*temp;
	int		i;

	if (!stack->head)
		return ;
	temp = stack->head;
	i = 0;
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}

void	cost_operation(t_stack *from, t_stack *to)
{
	t_node	*temp;

	temp = from->head;
	while (temp)
	{
		if (temp->index < (from->size / 2))
			temp->cost = temp->index;
		else
			temp->cost = (from->size - temp->index);
		if (temp->target->index < (to->size / 2))
			temp->cost += temp->target->index;
		else
			temp->cost += (to->size - temp->target->index);
		temp = temp->next;
	}
}
