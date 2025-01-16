/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:34:35 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/16 17:49:44 by cayamash         ###   ########.fr       */
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
			return (1);
	}
	if (((*stack)->value > (*stack)->next->value
			&& (*stack)->value > (*stack)->next->next->value))
	{
		rotate(stack, NULL, 'a');
		if (is_sorted(*stack) == 0)
			return (1);
	}
	if ((*stack)->value < (*stack)->next->next->value)
	{
		swap(stack, 'a');
		if (is_sorted(*stack) == 0)
			return (1);
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
		r.rd = 0;
		r.rs = small->index;
		ex_rotate(stack, NULL, r, 'b');
	}
	else
	{
		r.rrd = 0;
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
		//ft_printf("index: %i\n", index);
		push_to_stack(stack_a, stack_b, index, 'b');
		// ft_printf("stack_a\n");
		// stack_print(*stack_a);
		// ft_printf("stack_b\n");
		// stack_print(*stack_b);
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
	char	**args;
	int		length;

	if (argc == 1)
		return (0);
	if (ft_strchr(argv[1], ' '))
		args = ft_split(argv[1], ' ');
	else
		args = copy_array(argv, 1, argc);
	if (!args)
		response = 0;
	else
		response = check_arguments(args);
	if (response)
	{
		stack_a = stack_create(args);
		stack_b = NULL;
		if (is_sorted(stack_a))
			return (1);
		length = stack_size(stack_a);
		if (length > 2 && length < 5)
			response = small_stack(&stack_a);
		else if (length >= 5)
			response = large_stack(&stack_a, &stack_b);
		stack_print(stack_a);
		stack_free(stack_a);
		stack_free(stack_b);
	}
	free_array(args);
	if (!response)
		ft_printf("Error\n");
	return (0);
}
