/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:13:46 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/17 17:59:40 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

t_stack	*find_closest_smaller(t_stack *stack, int num)
{
	t_stack	*closest;

	closest = NULL;
	while (stack)
	{
		if ((stack->value < num)
			&& (!closest || num - stack->value < num - closest->value))
			closest = stack;
		stack = stack->next;
	}
	return (closest);
}

t_stack	*find_closest_larger(t_stack *stack, int num)
{
	t_stack	*closest;

	closest = NULL;
	while (stack)
	{
		if ((stack->value > num)
			&& (!closest || num - stack->value > num - closest->value))
			closest = stack;
		stack = stack->next;
	}
	return (closest);
}

t_stack	*find_largest(t_stack *stack)
{
	t_stack	*largest;

	largest = NULL;
	while (stack)
	{
		if (!largest || stack->value > largest->value)
			largest = stack;
		stack = stack->next;
	}
	return (largest);
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*smallest;

	smallest = NULL;
	while (stack)
	{
		if (!smallest || stack->value < smallest->value)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

t_stack	*find_target(t_stack *stack, int num, char target_stack)
{
	t_stack	*target;

	if (target_stack == 'a')
	{
		target = find_closest_larger(stack, num);
		if (!target)
			return (find_smallest(stack));
		return (target);
	}
	if (target_stack == 'b')
	{
		target = find_closest_smaller(stack, num);
		if (!target)
			return (find_largest(stack));
		return (target);
	}
	return (NULL);
}
