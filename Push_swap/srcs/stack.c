/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:12:03 by chillhoneyy       #+#    #+#             */
/*   Updated: 2025/01/30 16:29:50 by miovu            ###   ########.fr       */
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
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	stackadd_front(t_stack *stack, t_node *new)
{
	if (!stack->head)
	{
		new = stack->head;
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
	stack->tail->next = new;
	new->prev = stack->tail;
	stack->tail = new;
	stack->tail->next = NULL;
}

void	clear_stack(t_stack	*stack)
{
	t_node	*temp;

	while (stack->head)
	{
		temp = stack->head->next;
		free(stack->head);
		stack->head = temp;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

t_stack	assemble_stack(char **split, t_stack *stack)
{
	t_node	*new;
	int		num;
	int		i;

	num = 0;
	i = 0;
	while (split[i])
	{
		num = ft_atoi(split[i]);
		new = new_node(num);
		if (!new)
			break ;
		stack_addback(stack, new);
		i++;
	}
	return (*stack);
}
