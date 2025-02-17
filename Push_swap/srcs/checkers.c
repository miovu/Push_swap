/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:14:33 by chillhoneyy       #+#    #+#             */
/*   Updated: 2025/01/30 15:43:08 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	check_int(char *str)
{
	long	nbr;

	nbr = ft_atol(str);
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (false);
	while (ft_isspace((int)*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit((int)*str))
			return (false);
		str++;
	}
	return (true);
}

bool	check_dup(t_stack *stack)
{
	t_node	*current;
	t_node	*checker;

	current = stack->head;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->content == checker->content)
				return (false);
			checker = checker->next;
		}
		current = current->next;
	}
	return (true);
}

bool	is_valid(int argc, char **argv)
{
	char	**split;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		if (split[j] == 0)
			return (false);
		while (split[j])
		{
			if (!check_int(split[j]))
			{
				ps_free(split);
				return (false);
			}
			j++;
		}
		ps_free(split);
		i++;
	}
	return (true);
}
