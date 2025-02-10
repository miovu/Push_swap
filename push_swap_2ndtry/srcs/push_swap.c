/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillhoneyyy <chillhoneyyy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:43:31 by miovu             #+#    #+#             */
/*   Updated: 2025/02/10 00:14:48 by chillhoneyy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_list(t_stack *stack, char	id)
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
		ft_printf("Index %d\n", temp->index);
		if(temp->target != NULL)
			ft_printf("Target: %d\n", temp->target->content);
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
	t_node	*temp;
	static t_stack	stack_a;
	static t_stack	stack_b;
	
	stack_a = make_stack(argc, argv);
	stack_b = make_stack(0, 0);
	if (!stack_a.head)
		return ((write (2, "Error\n", 7)));
	print_list (&stack_a, 'A');
	sort_stack(&stack_a, &stack_b);
	push_nodes(&stack_a, &stack_b, 'b');
	push_nodes(&stack_a, &stack_b, 'b');
	push_nodes(&stack_a, &stack_b, 'b');
	target_b(&stack_a, &stack_b);
	index_value(&stack_a);
	index_value(&stack_b),
	print_list(&stack_a, 'A');
	print_list(&stack_b, 'B');
	clear_stack(&stack_a);
	clear_stack(&stack_b);
	return (0);
}
 