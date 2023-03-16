/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:13:43 by aigarcia          #+#    #+#             */
/*   Updated: 2023/03/16 20:13:45 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

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

void	argcheck(int *s, int argc)
{
	int	it;
	int	jt;

	it = 0;
	jt = 1;
	while (it < argc - 1)
	{
		while (jt < argc - 1)
		{
			if (s[it] == s[jt])
			{
				ft_printf("Some number(s) appear twice or more.\n");
				freestacks(s, 0);
			}
			jt++;
		}
		jt = (it + 2);
		it++;
	}
}

int	checksmall(int *a, int *len)
{
	int	it;
	int	n;

	it = 0;
	n = 0;
	while (it < *len)
	{
		if (a[it] < a[n])
			n = it;
		it++;
	}
	return (n);
}

int	checkbig(int *a, int *len)
{
	int	it;
	int	n;

	it = 0;
	n = 0;
	while (it < *len)
	{
		if (a[it] > a[n])
			n = it;
		it++;
	}
	return (n);
}

void	checklen(int *a, int *b, int argc)
{
	int	alen;
	int	blen;

	blen = 0;
	alen = argc - 1;
	if (alen == 2 || alen == 3)
		index3(a, &alen);
	if (alen == 4)
		index4(a, b, &alen, &blen);
	if (alen == 5)
		index5(a, b, &alen, &blen);
	if (alen < 101 && alen > 5)
		index100(a, b, &alen, &blen);
	if (alen <= 500 && alen > 100)
		index500(a, b, &alen, &blen);
}
