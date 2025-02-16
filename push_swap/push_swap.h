/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:37:19 by miovu             #+#    #+#             */
/*   Updated: 2025/02/13 17:44:51 by miovu            ###   ########.fr       */
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
	int				index;
	int				cost;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

//stack
t_node	*new_node(int content);
void	stackadd_front(t_stack *stack, t_node *new);
void	stack_addback(t_stack *stack, t_node *new);
t_node	*remove_front(t_stack *stack);
t_node	*remove_back(t_stack *stack);
//stack2
void	clear_stack(t_stack	*stack);
void	assemble_stack(char **split, t_stack *stack);
void	initialize_stack(t_stack *stack_a);
t_stack	make_stack(int argc, char **argv);
//checkers
bool	check_int(char *str);
bool	check_dup(t_stack *stack);
bool	is_valid(int argc, char **argv);
//rules
void	swap_nodes(t_stack *stack, char id, int flag);
void	push_nodes(t_stack *from, t_stack *to, char id);
void	rotate_nodes(t_stack *stack, char id, int flag);
void	reverse_rotate(t_stack *stack, char id, int flag);
//rules2
void	swap_both(t_stack *stack_a, t_stack *stack_b);
void	rotate_both(t_stack	*stack_a, t_stack *stack_b);
void	reverse_both(t_stack *stack_a, t_stack *stack_b);
//quick_sort
bool	sorted_stack(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_two(t_stack *stack);
//target
t_node	*smallest_node(t_stack *stack);
t_node	*highest_node(t_stack *stack);
void	target_a(t_stack *stack_a, t_stack *stack_b);
void	target_b(t_stack *stack_a, t_stack *stack_b);
//costs
void	index_value(t_stack *stack);
void	cost_operation(t_stack *from, t_stack *to);
//moves
t_node	*find_cheapest(t_stack *from);
void	move_a(t_stack *from, t_stack *to);
void	move_b(t_stack *from, t_stack *to);
void	move_both(t_stack *from, t_stack *to);
//sort
void	give_values(t_stack *stack_a, t_stack *stack_b);
void	send_nodes(t_stack *stack_a, t_stack *stack_b);
void	final_sort(t_stack *stack);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);
//pushswap
void	print_list(t_stack *stack, char id);
void	print_stack(t_stack *stack, char id);
void	ps_free(char **split);
int		main(int argc, char **argv);
#endif