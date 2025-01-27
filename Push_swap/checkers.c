/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillhoneyyy <chillhoneyyy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:14:33 by chillhoneyy       #+#    #+#             */
/*   Updated: 2025/01/24 18:37:15 by chillhoneyy      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_int(char *str)
{
	long	nbr;
	
	nbr	= ft_atol(str);
	if	(nbr < INT_MIN || nbr > INT_MAX)
		return (0);
	while (ft_isspace((int)*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit((int)*str))
			return (0);
		str++;
	}
	return (1);
}

int check_dup(t_dlist *stack)
{
    t_dlist	*current;
	t_dlist	*checker;

	current = stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->content == checker->content)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_valid(int argc, char **argv)
{
	int i;
	int	j;

	i = 1;
	while (i < argc)
	{
		char **split = ft_split(argv[1], ' ');
		j = 0;
		while (split[j])
		{
			if (!check_int(split[j]))
			{
				free(split);
				return (0);
			}
			j++;
		}
		free(split);
		i++;
	}
	return (1);
}
