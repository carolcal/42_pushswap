/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:19:43 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/16 14:19:43 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

static int	is_repeat_bonus(char *argv[], char *str, int i)
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

static int	is_int_bonus(char *arg)
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
	else if (ft_strlen(arg) > 10 || ft_strlen(arg) == 0)
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

int	check_arguments_bonus(char *args[])
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!is_int_bonus(args[i]))
			return (0);
		if (!is_repeat_bonus(args, args[i], i + 1))
			return (0);
		i++;
	}
	return (1);
}

void	free_array_bonus(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**copy_array_bonus(char **src, int start, int end)
{
	int		i;
	char	**array;

	i = 0;
	array = (char **)ft_calloc(end - start + 1, sizeof(char *));
	if (!array)
		return (NULL);
	while (start < end && src[start])
	{
		array[i] = ft_strdup(src[start]);
		if (!array[i])
		{
			free_array_bonus(array);
			return (NULL);
		}
		i++;
		start++;
	}
	array[i] = NULL;
	return (array);
}
