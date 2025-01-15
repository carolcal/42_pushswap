/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:44:32 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/15 16:52:49 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				steps;
	struct s_stack	*target;
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

t_stack	*stack_new(int number);
t_stack	*stack_last(t_stack *stack);
void	stack_addback(t_stack **stack, t_stack *new);
void	stack_addfront(t_stack **stack, t_stack *new);
t_stack	*stack_create(int length, char *argv[]);
void	stack_update_index(t_stack **stack);
void	stack_remove(t_stack **stack, int index);
int		stack_size(t_stack *stack);
void	stack_print(t_stack *stack);
int		stack_free(t_stack *stack);
void	swap(t_stack **stack, char name);
void	push(t_stack **src, t_stack **dest, char name);
void	rotate(t_stack **s1, t_stack **s2, char name);
void	reverse_rotate(t_stack **s1, t_stack **s2, char name);
t_stack	*find_smallest(t_stack *stack);
t_stack	*find_target(t_stack *stack, int num, char target_stack);
int		fastest_index(t_stack *src, t_stack *dest, char target_stack);
void	ex_rotate(t_stack **src, t_stack **dest, t_rotate r, char dname);
void	ex_revrotate(t_stack **src, t_stack **dest, t_rotate r, char dname);
void	push_to_stack(t_stack **src, t_stack **dest, int index, char name);

#endif
