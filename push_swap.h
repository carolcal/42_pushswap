/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:44:32 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/14 12:12:11 by cayamash         ###   ########.fr       */
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
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

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
void	rotate(t_stack **stack, char name);
void	reverse_rotate(t_stack **stack, char name);

#endif
