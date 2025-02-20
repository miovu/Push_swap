/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:32:59 by miovu             #+#    #+#             */
/*   Updated: 2025/02/17 19:21:37 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	t_stack	stack;
	char	**split;
	int		i;

	initialize_stack(&stack);
	if (!is_valid(argc, argv))
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
