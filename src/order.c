/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:44:06 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/14 18:08:52 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*find_target(t_stack *stack, int num)
{
	t_stack	*smallest;

	smallest = find_closest_smaller(stack, num);
	if (!smallest)
		return (find_largest(stack));
	return (smallest);
}

int	calculate_steps(t_stack *src, t_stack *dest, t_stack *curr)
{
	int	len_src;
	int	len_dest;
	int	steps;

	len_src = stack_size(src);
	len_dest = stack_size(dest);
	if (curr->index < (len_src + 1) / 2)
	{
		steps = curr->index; //ra || rr
		if ((curr->target->index < (len_dest + 1) / 2)
			&& (curr->target->index > curr->index))
			steps += curr->target->index - curr->index; //rb
		else if (curr->target->index > (len_dest + 1) / 2)
			steps += len_dest - curr->target->index; //rrb
	}
	else
	{
		steps = len_src - curr->index; //rra || rrr
		if ((curr->target->index > (len_dest + 1) / 2)
			&& (curr->target->index < curr->index))
			steps += curr->index - curr->target->index; ///rrb
		else if (curr->target->index < (len_dest + 1) / 2)
			steps += curr->index; //rb
	}
	return (steps++);//pb
}

int	fastest_index(t_stack *src, t_stack *dest)
{
	int		index;
	int		less_steps;
	t_stack	*temp;

	index = 0;
	less_steps = -1;
	temp = src;
	while (temp)
	{
		temp->target = find_target(dest, temp->value);
		temp->steps = calculate_steps(src, dest, temp);
		if (less_steps == -1 || temp->steps < less_steps)
		{
			less_steps = temp->steps;
			index = temp->index;
		}
		temp = temp->next;
	}
	return (index);
}




