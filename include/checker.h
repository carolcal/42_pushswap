/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:45:46 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/20 10:41:32 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "lib/libft.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_rotate
{
	int	rs;
	int	rd;
	int	rrs;
	int	rrd;
}	t_rotate;

int		is_sorted(t_stack *stack);
int		stack_size(t_stack *stack);
char	**copy_array(char **src, int start, int end);
int		check_arguments(char *argv[]);
t_stack	*stack_last(t_stack *stack);
void	stack_addfront(t_stack **stack, t_stack *new);
t_stack	*stack_create(char *argv[]);
void	stack_remove_first(t_stack **stack);
void	swap(t_stack **stack);
void	push(t_stack **src, t_stack **dest);
void	rotate(t_stack **s1, t_stack **s2);
void	reverse_rotate(t_stack **s1, t_stack **s2);

#endif