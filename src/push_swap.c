/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:34:35 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/15 16:59:14 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	if (!stack || !stack->next)
		return (EXIT_SUCCESS);
	temp = stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
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
		reverse_rotate(stack, NULL, 'a');
		if (is_sorted(*stack) == 0)
			return (EXIT_SUCCESS);
	}
	if (((*stack)->value > (*stack)->next->value
			&& (*stack)->value > (*stack)->next->next->value))
	{
		rotate(stack, NULL, 'a');
		if (is_sorted(*stack) == 0)
			return (EXIT_SUCCESS);
	}
	if ((*stack)->value < (*stack)->next->next->value)
	{
		swap(stack, 'a');
		if (is_sorted(*stack) == 0)
			return (EXIT_SUCCESS);
	}
	return (is_sorted(*stack));
}

void	bring_small_top(t_stack **stack)
{
	t_rotate	r;
	t_stack		*small;
	int			len;

	len = stack_size(*stack);
	small = find_smallest(*stack);
	if (small->index < (len + 1) / 2)
	{
		r.rs = small->index;
		ex_rotate(stack, NULL, r, 'b');
	}
	else
	{
		r.rrs = len - small->index;
		ex_revrotate(stack, NULL, r, 'b');
	}
}

int	large_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	index;

	push(stack_a, stack_b, 'b');
	if (stack_size(*stack_a) > 3)
		push(stack_a, stack_b, 'b');
	while (stack_size(*stack_a) > 3)
	{
		index = fastest_index(*stack_a, *stack_b, 'b');
		push_to_stack(stack_a, stack_b, index, 'b');
	}
	small_stack(stack_a);
	while (stack_size(*stack_b) > 0)
	{
		index = fastest_index(*stack_b, *stack_a, 'a');
		push_to_stack(stack_b, stack_a, index, 'a');
	}
	if (is_sorted(*stack_a) != 0)
		bring_small_top(stack_a);
	return (is_sorted(*stack_a));
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
		stack_print(stack_a);
		if (is_sorted(stack_a) == 0)
			return (EXIT_SUCCESS);
		if (argc > 2 && argc < 5)
			response = small_stack(&stack_a);
		else if (argc >= 5)
			response = large_stack(&stack_a, &stack_b);
		ft_printf("stack final \n");
		stack_print(stack_a);
		stack_free(stack_a);
		stack_free(stack_b);
		return (response);
	}
	return (0);
}
