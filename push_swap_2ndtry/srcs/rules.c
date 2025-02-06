/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:20:43 by miovu             #+#    #+#             */
/*   Updated: 2025/02/06 16:46:41 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_nodes(t_stack *stack, char id, int flag)
{
	t_node	*first;
	t_node	*second;
	int		temp;

	if (!stack->head)
		return ;
	if (flag == 1)
		ft_printf("s%c\n", id);
	first = stack->head;
	second = stack->head->next;
	temp = first->content;
	first->content = second->content;
	second->content = temp;
}

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("ss\n");
	swap_nodes(stack_a,	'a', 0);
	swap_nodes(stack_b, 'b', 0);
}

void	push_nodes(t_stack *from, t_stack *to, char id)
{
	t_node	*temp;
	
	ft_printf("p%c\n", id);
	temp = remove_front(from);
	stackadd_front(to, temp);
}

void	rotate_nodes(t_stack *stack, char id, int flag)
{
	t_node	*temp;
	
	if (flag == 1)
		ft_printf("r%c\n", id);
	temp = remove_front(stack);
	stack_addback(stack, temp);
}

void	rotate_both(t_stack	*stack_a, t_stack *stack_b)
{
	ft_printf("rr\n");
	rotate_nodes(stack_a, 'a', 0);
	rotate_nodes(stack_b, 'b', 0);
}

void	reverse_rotate(t_stack *stack, char id, int flag)
{
	t_node	*temp;

	if (flag == 1)
		ft_printf("rr%c\n", id);
	temp = remove_back(stack);
	stackadd_front(stack, temp);
}

void	reverse_both(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("rrr\n");
	reverse_rotate(stack_a, 'a', 0);
	reverse_rotate(stack_b, 'b', 0);
}
