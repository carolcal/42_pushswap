/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:45:05 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/23 19:27:00 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

static int	ex_call_bonus(t_stack **stack_a, t_stack **stack_b, char *call)
{
	if (ft_strncmp(call, "rrr", 3) == 0 && ft_strlen(call) == 4)
		reverse_rotate_bonus(stack_a, stack_b);
	else if (ft_strncmp(call, "rra", 3) == 0 && ft_strlen(call) == 4)
		reverse_rotate_bonus(stack_a, NULL);
	else if (ft_strncmp(call, "rrb", 3) == 0 && ft_strlen(call) == 4)
		reverse_rotate_bonus(stack_b, NULL);
	else if (ft_strncmp(call, "rr", 2) == 0 && ft_strlen(call) == 3)
		rotate_bonus(stack_a, stack_b);
	else if (ft_strncmp(call, "ra", 2) == 0 && ft_strlen(call) == 3)
		rotate_bonus(stack_a, NULL);
	else if (ft_strncmp(call, "rb", 2) == 0 && ft_strlen(call) == 3)
		rotate_bonus(stack_b, NULL);
	else if (ft_strncmp(call, "pa", 2) == 0 && ft_strlen(call) == 3)
		push_bonus(stack_b, stack_a);
	else if (ft_strncmp(call, "pb", 2) == 0 && ft_strlen(call) == 3)
		push_bonus(stack_a, stack_b);
	else if (ft_strncmp(call, "sa", 2) == 0 && ft_strlen(call) == 3)
		swap_bonus(stack_a);
	else if (ft_strncmp(call, "sb", 2) == 0 && ft_strlen(call) == 3)
		swap_bonus(stack_b);
	else
		return (1);
	return (0);
}

static int	read_commands_bonus(t_stack **stack_a, t_stack **stack_b)
{
	char	*command;

	command = get_next_line(0);
	while (command)
	{
		if (ex_call_bonus(stack_a, stack_b, command))
			return (1);
		free(command);
		command = get_next_line(0);
	}
	return (0);
}

static void	checker_bonus(char **args)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stack_create_bonus(args);
	stack_b = NULL;
	if (read_commands_bonus(&stack_a, &stack_b))
		ft_printf("Error\n");
	else if (is_sorted_bonus(stack_a) && stack_size_bonus(stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stack_free_bonus(stack_a);
	stack_free_bonus(stack_b);
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
		args = copy_array_bonus(argv, 1, argc);
	if (!args)
		response = 0;
	else
		response = check_arguments_bonus(args);
	if (response)
		checker_bonus(args);
	else
		ft_printf("Error\n");
	free_array_bonus(args);
	return (0);
}
