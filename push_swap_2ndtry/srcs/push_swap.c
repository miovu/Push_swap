/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:43:31 by miovu             #+#    #+#             */
/*   Updated: 2025/02/06 19:42:25 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_list(t_stack *stack, char	which)
{
	t_node	*temp;

	if (!stack->head)
		return ;
	ft_printf("STACK %c\n", which);
	temp = stack->head;
	ft_printf("Size: %d\n", stack->size);
	ft_printf("Head: %d\n", stack->head->content);
	ft_printf("\n");
	while (temp)
	{
		ft_printf("Node: %d\n", temp->content);
		if(temp->target != NULL)
			ft_printf("Target: %d\n", temp->target->content);
		temp = temp->next;
	}
	ft_printf("\n");
	ft_printf("Tail: %d\n", stack->tail->content);
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
	//push_nodes(&stack_a, &stack_b);
	//push_nodes(&stack_a, &stack_b);
	//reverse_both(&stack_a, &stack_b);
	// print_list(&stack_a, 'A');
	//temp = highest_node(&stack_a);
	//printf("Highest = %d\n", temp->content);
	sort_stack(&stack_a, &stack_b);
	push_nodes(&stack_a, &stack_b, 'b');
	push_nodes(&stack_a, &stack_b, 'b');
	push_nodes(&stack_a, &stack_b, 'b');
	target_node(&stack_a, &stack_b);
	print_list(&stack_a, 'A');
	print_list(&stack_b, 'B');
	clear_stack(&stack_a);
	clear_stack(&stack_b);
	return (0);
}
 