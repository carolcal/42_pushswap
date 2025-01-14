/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:34:35 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/14 18:55:40 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->prev && temp->prev->value > temp->value)
			return (EXIT_FAILURE);
		if (temp->next && temp->next->value < temp->value)
			return (EXIT_FAILURE);
		temp = temp->next;
	}
	return (EXIT_SUCCESS);
}

int	small_stack(t_stack **stack)
{
	if (stack_size(*stack) == 2)
	{
		swap(stack, 'a');
		return (is_sorted(*stack));
	}
	if ((*stack)->value < (*stack)->next->value)
	{
		reverse_rotate(stack, 'a');
		if (is_sorted(*stack))
			return (EXIT_SUCCESS);
	}
	if (((*stack)->value > (*stack)->next->value &&
			(*stack)->value > (*stack)->next->next->value))
	{
		rotate(stack, 'a');
		if (is_sorted(*stack))
			return (EXIT_SUCCESS);
	}
	if ((*stack)->value < (*stack)->next->next->value)
	{
		swap(stack, 'a');
		if (is_sorted(*stack))
			return (EXIT_SUCCESS);
	}
	return (is_sorted(*stack));
}

int	big_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	index;

	push(stack_a, stack_b, 'b');
	if (stack_size(*stack_a) > 3)
		push(stack_a, stack_b, 'b');
	while (stack_size(*stack_a) > 3)
	{
		index = fastest_index(*stack_a, *stack_b);
		//push_to_stack(stack_a, stack_b, index);
	}
	stack_print(*stack_a);
	// while (stack_size(*stack_a) > 0)
	// {
	// 	small_stack(stack_a);
	// 	index = fastest_index(*stack_b, *stack_a);
	// 	push_to_stack(stack_b, stack_a, index);
	// }
	//return (is_sorted(*stack_a));
	return (0);
}


int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		response;

	response = 0;
	if (argc > 1)
	{
		stack_a = stack_create(argc - 1, argv);
		stack_b = NULL;
		if (is_sorted(stack_a))
			return (EXIT_SUCCESS);
		if (argc > 2 && argc < 5)
			response = small_stack(&stack_a);
		else if (argc >= 5)
			response = big_stack(&stack_a, &stack_b);
		stack_print(stack_a);
		stack_free(stack_a);
		stack_free(stack_b);
		return (response);
	}
	return (0);
}
