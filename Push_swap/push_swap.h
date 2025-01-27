/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillhoneyyy <chillhoneyyy@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:37:19 by miovu             #+#    #+#             */
/*   Updated: 2025/01/24 18:20:28 by chillhoneyy      ###   ########.fr       */
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
# include "libft/libft.h"
# include "libft/printf/ft_printf.h"

t_dlist *new_node(void *content);
t_dlist	*assemble_stack(char **split);
int     check_int(char *str);
int     check_dup(t_dlist *stack);
int     is_valid(int argc, char **argv);
int     main(int argc, char **argv);

#endif