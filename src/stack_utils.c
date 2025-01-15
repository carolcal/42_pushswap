/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:24:57 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/15 10:06:03 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*temp;

	size = 0;
	if (!stack || stack == NULL)
		return (size);
	temp = stack;
	while (temp != NULL)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

void	stack_print(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		ft_printf("Value: %d, Index: %d, ", temp->value, temp->index);
		if(temp->steps)
			ft_printf("Steps: %d, ", temp->steps);
		if(temp->target)
			ft_printf("Target_index: %d", temp->target->index);
		ft_printf("\n");
		temp = temp->next;
	}
}