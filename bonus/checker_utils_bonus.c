/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:43:08 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/20 10:40:08 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

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

void	stack_remove_first(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	temp = *stack;

	if (!temp)
		return ;
	*stack = temp->next;
	if (temp->next)
		temp->next->prev = NULL;
	
}
