/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:44:11 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/17 18:03:56 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

t_stack	*stack_new(int number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> value = number;
	new -> prev = NULL;
	new -> next = NULL;
	return (new);
}

t_stack	*stack_last(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (NULL);
	temp = stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	stack_addback(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	last = stack_last(*stack);
	if (!last)
		*stack = new;
	else
	{
		last->next = new;
		new->prev = last;
	}
}

void	stack_addfront(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	if (*stack)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	else
	{
		new->next = NULL;
		new->prev = NULL;
	}
	*stack = new;
	stack_update_index(stack);
}

t_stack	*stack_create(char *argv[])
{
	int		i;
	int		number;
	t_stack	*stack;

	i = 0;
	stack = NULL;
	while (argv[i])
	{
		number = ft_atoi(argv[i]);
		stack_addback(&stack, stack_new(number));
		i++;
	}
	return (stack);
}
