/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:40:17 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/23 19:27:47 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

void	swap_bonus(t_stack **stack)
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
	*stack = second;
}

void	push_bonus(t_stack **src, t_stack **dest)
{
	t_stack	*item;

	if (!src || !*src)
		return ;
	item = *src;
	stack_remove_first_bonus(src);
	stack_addfront_bonus(dest, item);
}

void	rotate_bonus(t_stack **s1, t_stack **s2)
{
	t_stack	*first;
	t_stack	*last;

	if (!s1 || !*s1 || !(*s1)->next)
		return ;
	first = *s1;
	last = stack_last_bonus(*s1);
	*s1 = first->next;
	(*s1)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (s2 && *s2 && (*s2)->next)
		rotate_bonus(s2, NULL);
}

void	reverse_rotate_bonus(t_stack **s1, t_stack **s2)
{
	t_stack	*first;
	t_stack	*last;

	if (!s1 || !*s1 || !(*s1)->next)
		return ;
	first = *s1;
	last = stack_last_bonus(*s1);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*s1 = last;
	if (s2 && *s2 && (*s2)->next)
		reverse_rotate_bonus(s2, NULL);
}
