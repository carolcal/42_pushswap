/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayamash <cayamash@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:44:22 by cayamash          #+#    #+#             */
/*   Updated: 2025/01/16 15:10:02 by cayamash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
long    ft_atoi(const char *nptr)
{
	long	num;
	int	    sin;

	num = 0;
	sin = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		sin = -1;
		nptr ++;
	}
	while (ft_isdigit(*nptr))
	{
		num = (num * 10) + (*nptr - '0');
		nptr++;
	}
	return (num * sin);
}
