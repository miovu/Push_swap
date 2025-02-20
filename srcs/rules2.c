/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:34:35 by miovu             #+#    #+#             */
/*   Updated: 2025/02/11 16:35:24 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("ss\n");
	swap_nodes(stack_a, 'a', 0);
	swap_nodes(stack_b, 'b', 0);
}

void	rotate_both(t_stack	*stack_a, t_stack *stack_b)
{
	ft_printf("rr\n");
	rotate_nodes(stack_a, 'a', 0);
	rotate_nodes(stack_b, 'b', 0);
}

void	reverse_both(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("rrr\n");
	reverse_rotate(stack_a, 'a', 0);
	reverse_rotate(stack_b, 'b', 0);
}
