/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:42:39 by miovu             #+#    #+#             */
/*   Updated: 2025/01/30 16:28:45 by miovu            ###   ########.fr       */
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
	char	**split;
	int		i;

	stack_a = (t_stack){0};
	i = 0;
	if (argc == 1 || (!is_valid(argc, argv)))
		return (write (2, "Error\n", 7));
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		stack_a = assemble_stack(split, &stack_a);
		ps_free(split);
	}
	if (!check_dup(&stack_a))
		return (clear_stack(&stack_a), (write (2, "Error\n", 7)));
	ft_printf("Before:\n");
	print_list(&stack_a);
	clear_stack(&stack_a);
}
