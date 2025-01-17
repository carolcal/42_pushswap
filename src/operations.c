/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:37:53 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/14 09:37:53 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char name)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->index = 1;
	second->index = 0;
	*stack = second;
	ft_printf("s%c\n", name);
}

void	push(t_stack **src, t_stack **dest, char name)
{
	t_stack	*item;

	if (!src || !*src)
		return ;
	item = *src;
	stack_remove(src, 0);
	stack_addfront(dest, item);
	stack_update_index(src);
	stack_update_index(dest);
	ft_printf("p%c\n", name);
}

void	rotate(t_stack **s1, t_stack **s2, char name)
{
	t_stack	*first;
	t_stack	*last;

	if (!s1 || !*s1 || !(*s1)->next)
		return ;
	first = *s1;
	last = stack_last(*s1);
	*s1 = first->next;
	(*s1)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	stack_update_index(s1);
	if (s2 && *s2 && (*s2)->next)
		rotate(s2, NULL, 0);
	if (name)
		ft_printf("r%c\n", name);
}

void	reverse_rotate(t_stack **s1, t_stack **s2, char name)
{
	t_stack	*first;
	t_stack	*last;

	if (!s1 || !*s1 || !(*s1)->next)
		return ;
	first = *s1;
	last = stack_last(*s1);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*s1 = last;
	stack_update_index(s1);
	if (s2 && *s2 && (*s2)->next)
		reverse_rotate(s2, NULL, 0);
	if (name)
		ft_printf("rr%c\n", name);
}
