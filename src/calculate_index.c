/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:44:06 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/16 17:50:01 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			steps += curr->target->index - curr->index;
		else if (curr->target->index >= (len_dest + 1) / 2)
			steps += len_dest - curr->target->index;
	}
	else
	{
		steps = len_src - curr->index;
		if ((curr->target->index >= (len_dest + 1) / 2)
			&& (curr->target->index < curr->index))
			steps += curr->index - curr->target->index;
		else if (curr->target->index < (len_dest + 1) / 2)
			steps += curr->index;
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
	// if(index == 0)
	// 	ft_printf("target: %i", src->target->index);
	return (index);
}
