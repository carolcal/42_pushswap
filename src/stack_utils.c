/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:24:57 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/14 18:03:10 by cayamash         ###   ########.fr       */
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
		ft_printf("Value: %d, Index: %d, Steps: %d, Target_index: %d\n", temp->value, temp->index, temp->steps, temp->target->index);
		temp = temp->next;
	}
}