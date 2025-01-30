/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:43:31 by miovu             #+#    #+#             */
/*   Updated: 2025/01/30 18:29:56 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_list(t_stack *stack)
{
	t_node	*temp;

	temp = stack->head;
	ft_printf("Size: %d\n", stack->size);
	ft_printf("\n");
	ft_printf("Head: %d\n", stack->head->content);
	ft_printf("\n");
	while (temp)
	{
		ft_printf("Node: %d\n", temp->content);
		temp = temp->next;
	}
	ft_printf("\n");
	ft_printf("Tail: %d\n", stack->tail->content);
}

int	main(int argc, char **argv)
{
	static t_stack	stack_a;
	int				i;

	i = 1;
	while (i < argc)
	{
		printf("entrou no loop da main\n");
		stack_a = make_stack(&argv[i]);
		printf("fez make\n");
		i++;
	}
	printf("saiu do loop da main\n");
	print_list(&stack_a);
	clear_stack(&stack_a);
	return (0);
}