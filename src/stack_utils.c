/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:40:04 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/14 09:40:04 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

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

void	stack_update_index(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}

void	stack_remove(t_stack **stack, int index)
{
	t_stack	*temp;
	int		i;

	if (!stack || !*stack || index < 0)
		return ;
	temp = *stack;
	i = 0;
	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}
	if (!temp)
		return ;
	if (temp->prev)
		temp->prev->next = temp->next;
	else
		*stack = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
}

int	stack_free(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*next;

	curr = stack;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	if (!stack)
		return (1);
	return (0);
}
