/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillhoneyyy <chillhoneyyy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 23:58:20 by chillhoneyy       #+#    #+#             */
/*   Updated: 2025/02/10 00:42:33 by chillhoneyy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//header

#include "../push_swap.h"

void    index_value(t_stack *stack)
{
    t_node  *temp;
    int     i;

    if (!stack->head)
        return ;
    temp = stack->head;
    i = 1;
    while (temp)
    {
        temp->index = i;
        temp = temp->next;
        i++;
    }
}

void    operation_cost(t_stack *stack_a, t_stack *stack_b)
{
    int cost_rr;
    int cost_rrr;
    int a_up_b_down;
    int a_down_b_up;
    t_node  *temp_a;
    t_node  *temp_b;

    temp_a = stack_a->head;
    while (temp_a)
    {
        cost_rr = max(temp_a->index, temp_a->target->index);
        cost_rr = max ((stack_a->size - temp_a->index), (stack_b->size - temp_b->index));
        a_up_b_down = temp_a->index + (stack_b->size - temp_b->index);
        a_down_b_up = (stack_a->size - temp_a->index) + temp_b->index;
        temp_a->cost = min(cost_rr, min(cost_rr, min(a_up_b_down, min(a_down_b_up))));
        temp_a = temp_a->next;
    }
}
