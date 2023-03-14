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

void	checklen(int *a, int *b, int argc)
{
	int	alen;
	int	blen;

	blen = 0;
	alen = argc - 1;
	if (alen == 3)
		index3(a, &alen);
	//if (len == 4)
		//index4(a, b);
	if (alen == 5)
		index5(a, b, &alen, &blen);
	if (alen == 100)
		index100(a, b, &alen, &blen);
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
