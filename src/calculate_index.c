/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:44:06 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/17 13:58:34 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	if (!stack || !stack->next)
		return (1);
	temp = stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
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
		steps = curr->index;
		if ((curr->target->index < (len_dest + 1) / 2)
			&& (curr->target->index > curr->index))
			steps += (curr->target->index - curr->index);
		else if (curr->target->index >= (len_dest + 1) / 2)
			steps += (len_dest - curr->target->index);
	}
	else
	{
		steps = len_src - curr->index;
		if ((curr->target->index >= (len_dest + 1) / 2)
			&& ((len_src - curr->index) < (len_dest - curr->target->index)))
			steps += (len_dest - curr->target->index) - (len_src - curr->index);
		else if (curr->target->index < (len_dest + 1) / 2)
			steps += curr->target->index;
	}
	return (++steps);
}

int	fastest_index(t_stack *src, t_stack *dest, char target_stack)
{
	int		index;
	int		less_steps;
	t_stack	*temp;

	index = 0;
	less_steps = -1;
	temp = src;
	while (temp)
	{
		temp->target = find_target(dest, temp->value, target_stack);
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
