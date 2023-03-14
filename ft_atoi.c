/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:52:13 by aigarcia          #+#    #+#             */
/*   Updated: 2022/02/02 14:55:07 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "push_swap.h"

int	ft_atoi(const char *str, int *s)
{
	long long int				result;
	int							sign;

	sign = 1;
	result = 0;
	while (*str == 32 || *str == '\t' || *str == '\f'
		|| *str == '\r' || *str == '\n' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		result = (10 * result) + (*str - '0');
		str++;
		if (result > ((long long int)INT_MAX + 1) && sign == -1)
			freestacksatoi(s, sign);
		if (result > INT_MAX && sign == 1)
			freestacksatoi(s, sign);
	}
	return (result * sign);
}
