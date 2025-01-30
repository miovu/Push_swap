/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:37:20 by miovu             #+#    #+#             */
/*   Updated: 2025/01/30 18:33:16 by miovu            ###   ########.fr       */
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
	else
	{
		stack->tail->next = new;
		new->prev = stack->tail;
		stack->tail = new;
		stack->tail->next = NULL;
	}
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
		printf("entrou no loop do assemble\n");
		num = ft_atoi(split[i]);
		printf("fez atoi\n");
		new = new_node(num);
		printf("criou o node\n");
		if (!new)
			break ;
		printf("criou mesmo o node\n");
		stack_addback(stack, new);
		printf("adicionou o node\n");
		i++;
	}
	printf("saiu do loop do assemble\n");
	return (*stack);
}

void	ps_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return ;
}

t_stack	make_stack(char **argv)
{
	t_stack	stack_a; 
	char	**split;
	int		i;
	
	i = 1;
	while (argv[i])
	{
		printf("entrou no loop do make\n");
		split = ft_split(argv[i], ' ');
		printf("fez split\n");
		stack_a = assemble_stack(split, &stack_a);
		printf("fez assemble\n");
		ps_free(split);
		i++;
	}
	return (stack_a);
}
