/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:37:19 by miovu             #+#    #+#             */
/*   Updated: 2025/01/30 16:23:20 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define LC_HEX "0123456789abcdef"
# define UP_HEX	"0123456789ABCDEF"
# define DEC "0123456789"

# include <errno.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <ctype.h>
# include <stdbool.h>
# include "includes/libft/libft.h"

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

t_node	*new_node(int content);
void	stackadd_front(t_stack *stack, t_node *new);
void	stack_addback(t_stack *stack, t_node *new);
void	clear_stack(t_stack	*stack);
t_stack	assemble_stack(char **split, t_stack *stack);
bool	check_int(char *str);
bool	check_dup(t_stack *stack);
bool	is_valid(int argc, char **argv);
void	swap_stack(t_stack *stack);
void	push_stack(t_stack *stack_from, t_stack *stack_to);
void	print_list(t_stack *stack);
void	ps_free(char **strs);
int		main(int argc, char **argv);

#endif