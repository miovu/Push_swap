/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:37:07 by miovu             #+#    #+#             */
/*   Updated: 2025/01/30 15:08:19 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	first = stack->head;
	second = stack->head->next;
	if (!stack || !stack->head)
		return ;
	temp = first->content;
	first->content = second->content;
	second->content = temp;
}

void	push_stack(t_stack *stack_from, t_stack *stack_to)
{
	t_node	*temp;

	if (!stack_from->head)
		return ;
	temp = stack_from->head;
	stack_from->head = stack_from->head->next;
	stackadd_front(stack_to, temp);
	stack_from->size--;
	// if (!stack_to->head)
	// {
	// 	stackadd_front(stack_to, temp);
	// 	temp = stack_to->head;
	// 	temp->prev = NULL;
	// 	temp = stack_to->tail;
	// 	temp->next = NULL;
	// }
	// else
	// {
	// 	temp->next = stack_from->head->next;
	// 	stackadd_front(stack_to, temp);
	// 	temp = stack_to->head;
	// 	temp->prev = NULL;
	// }
}

/* int main()
{
	t_stack	*stack_a = NULL;
	t_stack	*stack_b = NULL;

	t_node	*temp;
	t_node	*a;
	t_node	*a1;
	t_node	*a2;

	a->content = 1;
	a1->content = 1;
	a2->content = 1;
	
	stack_a = new_node(a->content);
	stack_a = new_node(a1->content);
	stack_a = new_node(a2->content);

	ft_printf("Stack_a before push:\n");
	print_list(stack_a);
	ft_printf("Stack_b before push:\n");
	print_list(stack_b);
	
	push_stack(stack_a, stack_b);

	ft_printf("Stack_a after push:\n");
	print_list(stack_a);
	ft_printf("Stack_b after push:\n");
	print_list(stack_b);
	return (0);
} */