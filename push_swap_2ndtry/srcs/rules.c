/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:20:43 by miovu             #+#    #+#             */
/*   Updated: 2025/02/12 18:45:41 by miovu            ###   ########.fr       */
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

void	reverse_rotate(t_stack *stack, char id, int flag)
{
	t_node	*temp;

	if (flag == 1)
		ft_printf("rr%c\n", id);
	temp = remove_back(stack);
	stackadd_front(stack, temp);
}
