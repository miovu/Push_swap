/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:37:20 by miovu             #+#    #+#             */
/*   Updated: 2025/02/13 17:42:25 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*new_node(int content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->target = NULL;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	stackadd_front(t_stack *stack, t_node *new)
{
	stack->size++;
	if (!stack->head)
	{
		stack->head = new;
		stack->tail = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		new->next = stack->head;
		new->prev = NULL;
		stack->head->prev = new;
		stack->head = new;
	}
}

void	stack_addback(t_stack *stack, t_node *new)
{
	stack->size++;
	if (!stack->head)
	{
		stack->head = new;
		stack->tail = new;
		new->next = NULL;
		new->prev = NULL;
		return ;
	}
	else
	{
		stack->tail->next = new;
		new->prev = stack->tail;
		stack->tail = new;
		stack->tail->next = NULL;
	}
}

t_node	*remove_front(t_stack *stack)
{
	t_node	*temp;

	temp = stack->head;
	if (!temp)
		return (NULL);
	else if (temp->next == NULL)
	{
		stack->size--;
		return (temp);
	}
	else
	{
		stack->head = temp->next;
		temp->next->prev = NULL;
	}
	stack->size--;
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}

t_node	*remove_back(t_stack *stack)
{
	t_node	*temp;

	temp = stack->tail;
	if (!temp)
		return (NULL);
	else
	{
		stack->tail = temp->prev;
		temp->prev->next = NULL;
	}
	stack->size--;
	temp->next = NULL;
	temp->prev = NULL;
	return (temp);
}
