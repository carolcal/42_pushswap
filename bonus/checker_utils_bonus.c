/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:43:08 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/17 18:06:18 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

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

int	stack_size(t_stack *stack)
{
	int		size;
	t_stack	*temp;

	size = 0;
	if (!stack || stack == NULL)
		return (size);
	temp = stack;
	while (temp != NULL)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

int	is_repeat(char *argv[], char *str, int i)
{
	size_t	len;

	len = ft_strlen(str);
	while (argv[i])
	{
		if (len == ft_strlen(argv[i]))
		{
			if (ft_strncmp(argv[i], str, len) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_int(char *arg)
{
	int		j;
	long	num;
	int		spaces;

	j = 0;
	spaces = 0;
	if (arg[j] == '-')
	{
		if (ft_strlen(arg) > 11)
			return (0);
		j++;
	}
	else if (ft_strlen(arg) > 10)
		return (0);
	while (ft_isdigit(arg[j]) != 0 && arg[j] != '\0')
		j++;
	if (arg[j] != '\0' && ft_isdigit(arg[j]) == 0)
		return (0);
	num = ft_atoi(arg);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

int	check_arguments(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!is_int(argv[i]))
			return (0);
		if (!is_repeat(argv, argv[i], i + 1))
			return (0);
		i++;
	}
	return (1);
}
