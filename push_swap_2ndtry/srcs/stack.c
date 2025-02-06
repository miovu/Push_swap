/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:37:20 by miovu             #+#    #+#             */
/*   Updated: 2025/02/06 19:33:24 by miovu            ###   ########.fr       */
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

void	assemble_stack(char **split, t_stack *stack)
{
	t_node	*new;
	int		nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (split[i])
	{
		nbr = ft_atoi(split[i]);
		new = new_node(nbr);
		stack_addback(stack, new);
		i++;
	}
}

void	initialize_stack(t_stack *stack_a)
{
	stack_a->size = 0;
	stack_a->head = NULL;
	stack_a->tail = NULL;
}

t_stack	make_stack(int argc, char **argv)
{
	t_stack stack;
	char	**split;
	int		i;

	initialize_stack(&stack);
	if (argc == 1 || !is_valid(argc, argv))
	{
		clear_stack(&stack);
		return (stack);
	}
	i = 0;
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			clear_stack(&stack);
		assemble_stack(split, &stack);
		ps_free(split);
	}
	if (!check_dup(&stack))
		clear_stack(&stack);
	return (stack);
}
