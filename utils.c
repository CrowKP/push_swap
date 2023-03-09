/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:06:57 by aigarcia          #+#    #+#             */
/*   Updated: 2023/03/09 13:06:58 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	freestacks(int *a, int *b)
{
	if (a)
		free(a);
	if (b)
		free(b);
	exit(0);
}

void	freestacksatoi(int *s, int sign)
{
	if (sign == -1)
		ft_printf("One of the numbers is too small.\n");
	if (sign == 1)
		ft_printf("One of the numbers is too big.\n");
	if (s)
		free(s);
	exit(0);
}

void	checknums(char *argv, int *s)
{
	int	it;

	it = 0;
	while (argv[it])
	{
		if ((argv[it] == '-' || argv[it] == '+'))
			if (ft_isdigit(argv[it + 1]) == 1)
				it++;
		if (ft_isdigit(argv[it]) == 0)
		{
			ft_printf("Some elements are not numbers.\n");
			freestacks(s, 0);
		}
		it++;
	}
}

void	checklen(int *a, int *b)
{
	int	len;

	len = stacklen(a);
	if (len == 3)
		index3(a);
	if (len == 5)
		index5(a, b);
}

int	checksmall(int *a)
{
	int	it;
	int	n;

	it = 0;
	n = 0;
	while (a[it])
	{
		if (a[it] < a[n])
			n = it;
		it++;
	}
	return (n);
}
