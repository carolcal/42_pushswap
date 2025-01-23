/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:44:11 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/23 19:21:38 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

static t_stack	*stack_new_bonus(int number)
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

t_stack	*stack_last_bonus(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (NULL);
	temp = stack;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

static void	stack_addback_bonus(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	last = stack_last_bonus(*stack);
	if (!last)
		*stack = new;
	else
	{
		last->next = new;
		new->prev = last;
	}
}

void	stack_addfront_bonus(t_stack **stack, t_stack *new)
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
}

t_stack	*stack_create_bonus(char *argv[])
{
	int		i;
	int		number;
	t_stack	*stack;

	i = 0;
	stack = NULL;
	while (argv[i])
	{
		number = ft_atoi(argv[i]);
		stack_addback_bonus(&stack, stack_new_bonus(number));
		i++;
	}
	return (stack);
}
