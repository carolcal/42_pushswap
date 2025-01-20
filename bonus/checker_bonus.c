/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:45:05 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/20 17:31:26 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

int	exec_command(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (ft_strncmp(command, "rrr", 3) == 0 && ft_strlen(command) == 4)
		reverse_rotate(stack_a, stack_b);
	else if (ft_strncmp(command, "rra", 3) == 0 && ft_strlen(command) == 4)
		reverse_rotate(stack_a, NULL);
	else if (ft_strncmp(command, "rrb", 3) == 0 && ft_strlen(command) == 4)
		reverse_rotate(stack_b, NULL);
	else if (ft_strncmp(command, "rr", 2) == 0 && ft_strlen(command) == 3)
		rotate(stack_a, stack_b);
	else if (ft_strncmp(command, "ra", 2) == 0 && ft_strlen(command) == 3)
		rotate(stack_a, NULL);
	else if (ft_strncmp(command, "rb", 2) == 0 && ft_strlen(command) == 3)
		rotate(stack_b, NULL);
	else if (ft_strncmp(command, "pa", 2) == 0 && ft_strlen(command) == 3)
		push(stack_b, stack_a);
	else if (ft_strncmp(command, "pb", 2) == 0 && ft_strlen(command) == 3)
		push(stack_a, stack_b);
	else if (ft_strncmp(command, "sa", 2) == 0 && ft_strlen(command) == 3)
		swap(stack_a);
	else if (ft_strncmp(command, "sb", 2) == 0 && ft_strlen(command) == 3)
		swap(stack_b);
	else
		return (1);
	return (0);
}

int	read_commands(t_stack **stack_a, t_stack **stack_b)
{
	char	*command;

	command = get_next_line(0);
	while (command)
	{
		if (exec_command(stack_a, stack_b, command))
			return (1);
		free(command);
		command = get_next_line(0);
	}
	return (0);
}

void	checker(char **args)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stack_create(args);
	stack_b = NULL;
	if (read_commands(&stack_a, &stack_b))
		ft_printf("Error\n");
	else if (is_sorted(stack_a) && stack_size(stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char *argv[])
{
	char	**args;
	int		response;

	if (argc == 1)
		return (1);
	if (ft_strchr(argv[1], ' '))
		args = ft_split(argv[1], ' ');
	else
		args = copy_array(argv, 1, argc);
	if (!args)
		response = 0;
	else
		response = check_arguments(args);
	if (response)
		checker(args);
	else
		ft_printf("Error\n");
	return (0);
}
