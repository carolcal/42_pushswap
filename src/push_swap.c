/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:34:35 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/14 13:28:23 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	test_change_stacks(t_stack **stack_a, t_stack **stack_b)
// {
// 	ft_printf("stack_a:\n");
// 	print_stack(*stack_a);
// 	ft_printf("stack_b:\n");
// 	print_stack(*stack_b);
// 	push(stack_a, stack_b);
// 	push(stack_a, stack_b);
// 	push(stack_a, stack_b);
// 	swap(stack_a);
// 	swap(stack_b);
// 	rotate(stack_a);
// 	rotate(stack_b);
// 	reverse_rotate(stack_a);
// 	reverse_rotate(stack_b);
// 	push(stack_b, stack_a);
// 	push(stack_b, stack_a);
// 	push(stack_b, stack_a);
// 	ft_printf("stack_a:\n");
// 	print_stack(*stack_a);
// 	ft_printf("stack_b:\n");
// 	print_stack(*stack_b);
// }

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->prev && temp->prev->value > temp->value)
			return (-1);
		if (temp->next && temp->next->value < temp->value)
			return (-1);
		temp = temp->next;
	}
	return (0);
}

void	small_stack(t_stack **stack)
{
	if (stack_size(*stack) == 2)
		return (swap(stack, 'a'));
	else
	{
		if ((*stack)->value < (*stack)->next->value)
		{
			reverse_rotate(stack, 'a');
			if (is_sorted(*stack) == 0)
				return ;
		}
		if (((*stack)->value > (*stack)->next->value &&
				(*stack)->value > (*stack)->next->next->value))
		{
			rotate(stack, 'a');
			if (is_sorted(*stack) == 0)
				return ;
		}
		if ((*stack)->value < (*stack)->next->next->value)
		{
			swap(stack, 'a');
			if (is_sorted(*stack) == 0)
				return ;
		}
	}
}

void	big_stack(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("stack_a:\n");
 	stack_print(*stack_a);
 	ft_printf("stack_b:\n");
 	stack_print(*stack_b);
}


int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc > 1)
	{
		stack_a = stack_create(argc - 1, argv);
		stack_b = NULL;
		if (is_sorted(stack_a) == 0)
			return (0);
		if (argc > 2 && argc < 5)
			small_stack(&stack_a);
		else if (argc >= 5)
			big_stack(&stack_a, &stack_b);
		stack_print(stack_a);
		stack_free(stack_a);
		stack_free(stack_b);
	}
	return (0);
}
