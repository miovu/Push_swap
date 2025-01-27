/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillhoneyyy <chillhoneyyy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:12:03 by chillhoneyy       #+#    #+#             */
/*   Updated: 2025/01/24 18:39:14 by chillhoneyy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*new_node(void *content)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->content = (int)(long)content;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_dlist	*assemble_stack(char **split)
{
	t_dlist	*head = NULL;
	t_dlist	*current = NULL;
	int		num = 0;
	int		i = 0;

	while (split[i])
	{
		num = ft_atoi(split[i]);
		t_dlist	*new = new_node((void *)(long)num);
		if (!new)
			return (NULL);
		if (!head)
		{
			head = new;
			current = head;
		}
		else
		{
			current->next = new;
			new->prev = current;
			current = new;
		}
		i++;
	}
	return (head);
}

int main(int argc, char **argv)
{
    t_dlist *stack_a = NULL;

    if (argc == 1)
        return (ft_printf("Error\n"));
    if (!is_valid(argc, argv))
    {
        ft_putstr_fd("Error\n", STDERR_FILENO);
        return (1);
    }
	int i = 1;
    while (i < argc)
    {
        char **split_str = ft_split(argv[i], ' ');
        t_dlist *sublist = assemble_stack(split_str);
        if (!stack_a)
            stack_a = sublist;
        else
        {
            t_dlist *tail = stack_a;
            while (tail->next)
                tail = tail->next;
            tail->next = sublist;
            if (sublist)
                sublist->prev = tail;
        }
        free(split_str);
		i++;
    }
    if (check_dup(stack_a))
    {
        ft_putstr_fd("Error\n", STDERR_FILENO);
        return (1);
    }
	t_dlist	*current = stack_a;
	while (current)
	{
		ft_printf("Node value: %d\n", (int)(long)current->content);
		current = current->next;
	}
    return (0);
}


