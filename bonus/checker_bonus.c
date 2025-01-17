/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:45:05 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/17 18:58:06 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

void	exec_command(t_stack **stack_a, t_stack **stack_b, char *command)
{
	t_rotate	r;

	if (ft_strncmp(command, "rrr", 3))
		reverse_rotate(stack_a, stack_b);
	else if (ft_strncmp(command, "rra", 3))
		reverse_rotate(stack_a, NULL);
	else if (ft_strncmp(command, "rrB", 3))
		reverse_rotate(stack_b, NULL);
	else if (ft_strncmp(command, "rr", 2))
		rotate(stack_a, stack_b);
	else if (ft_strncmp(command, "ra", 2))
		rotate(stack_a, NULL);
	else if (ft_strncmp(command, "rb", 2))
		rotate(stack_b, NULL);
	else if (ft_strncmp(command, "pa", 2))
		push(stack_a, stack_b);
	else if (ft_strncmp(command, "pb", 2))
		push(stack_b, stack_a);
	else if (ft_strncmp(command, "sa", 2))
		swap(stack_a);
	else if (ft_strncmp(command, "sb", 2))
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

void	checker(char **args)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stack_create(args);
	stack_b = NULL;
	if (is_sorted(stack_a))
		return (1);
	read_commands(&stack_a, &stack_b);
	if (is_sorted(stack_a) && stack_size(stack_b) == 0)
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
		response = check_arguments(argv);
	if(response)
		checker(args);
	else
		ft_printf("Error\n");
	
	return (0);
}