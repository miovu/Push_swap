/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:43:31 by miovu             #+#    #+#             */
/*   Updated: 2025/02/17 19:22:25 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_list(t_stack *stack, char id)
{
	t_node	*temp;

	if (!stack->head)
		return ;
	ft_printf("\nSTACK %c\n\n", id);
	temp = stack->head;
	ft_printf("Size = %d\n", stack->size);
	ft_printf("Head = %d\n", stack->head->content);
	while (temp)
	{
		ft_printf("Index: %d; Node: %d; Target: %d; Cost: %d.\n", temp->index,
			temp->content, temp->target->content, temp->cost);
		temp = temp->next;
	}
	ft_printf("Tail = %d\n", stack->tail->content);
}

void	print_stack(t_stack *stack, char id)
{
	t_node	*temp;

	if (!stack->head)
		return ;
	ft_printf("\nSTACK %c\n\n", id);
	temp = stack->head;
	ft_printf("Size = %d\n", stack->size);
	ft_printf("Head = %d\n", stack->head->content);
	while (temp)
	{
		ft_printf("Node: %d\n", temp->content);
		temp = temp->next;
	}
	ft_printf("Tail = %d\n", stack->tail->content);
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

int	main(int argc, char **argv)
{
	static t_stack	stack_a;
	static t_stack	stack_b;

	stack_a = make_stack(argc, argv);
	stack_b = make_stack(0, 0);
	if (argc == 1)
		return (0);
	if (!stack_a.head)
		return ((write (2, "Error\n", 7)));
	sort_stack(&stack_a, &stack_b);
	clear_stack(&stack_a);
	return (0);
}
