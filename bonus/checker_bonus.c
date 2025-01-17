/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:45:05 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/17 17:51:59 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exec_command(t_stack **stack_a, t_stack **stack_b, char *command)
{
	t_rotate	r;

	if (strncmp(command, "rrr", 3))
		reverse_rotate(stack_a, stack_b);
	else if (strncmp(command, "rra", 3))
		reverse_rotate(stack_a, NULL);
	else if (strncmp(command, "rrB", 3))
		reverse_rotate(stack_b, NULL);
	else if (strncmp(command, "rr", 2))
		rotate(stack_a, stack_b);
	else if (strncmp(command, "ra", 2))
		rotate(stack_a, NULL);
	else if (strncmp(command, "rb", 2))
		rotate(stack_b, NULL);
	else if (strncmp(command, "pa", 2))
		push(stack_a, stack_b);
	else if (strncmp(command, "pb", 2))
		push(stack_b, stack_a);
	else if (strncmp(command, "sa", 2))
		swap(stack_a);
	else if (strncmp(command, "sb", 2))
		swap(stack_b);
	else
		return (1);
	return (0);
}

void	read_commands(t_stack **stack_a, t_stack **stack_b)
{
	char	*command;

	command = get_next_line(0);
	while (command)
	{
		exec_command(stack_a, stack_b, command);
		free(command);
		command = get_next_line(0);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		response;

	if (argc == 1)
		return (1);
	response = check_arguments(argv);
	stack_a = stack_create(argv);
	stack_b = NULL;
	if (is_sorted(stack_a))
		return (1);
	exec_commands(&stack_a, &stack_b);
	if (is_sorted(stack_a) && stack_size(stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}