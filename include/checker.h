/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:45:46 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/23 19:20:39 by cayamash         ###   ########.fr       */
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

int		is_sorted_bonus(t_stack *stack);
int		stack_size_bonus(t_stack *stack);
void	free_array_bonus(char **array);
char	**copy_array_bonus(char **src, int start, int end);
int		check_arguments_bonus(char *argv[]);
t_stack	*stack_last_bonus(t_stack *stack);
void	stack_addfront_bonus(t_stack **stack, t_stack *new);
t_stack	*stack_create_bonus(char *argv[]);
void	stack_remove_first_bonus(t_stack **stack);
int		stack_free_bonus(t_stack *stack);
void	swap_bonus(t_stack **stack);
void	push_bonus(t_stack **src, t_stack **dest);
void	rotate_bonus(t_stack **s1, t_stack **s2);
void	reverse_rotate_bonus(t_stack **s1, t_stack **s2);

#endif