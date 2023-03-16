/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderutils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:15:51 by aigarcia          #+#    #+#             */
/*   Updated: 2023/03/16 20:15:52 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

int	checkposition(int *a, int *b, int *blen)
{
	int	it;

	it = 1;
	while (it < *blen)
	{
		if (a[0] > b[it] && a[0] < b[it - 1])
			return (it);
		it++;
	}
	return (0);
}

void	pushrandom(int *a, int *b, int *alen, int *blen)
{
	int	it;
	int	n;

	n = b[checkposition(a, b, blen)];
	it = checkposition(a, b, blen);
	if (it <= *blen / 2)
	{
		while (b[0] != n)
			rtp(0, b, 0, blen);
	}
	else
	{
		while (b[0] != n)
			rrtp(0, b, 0, blen);
	}
	pb(a, b, alen, blen);
}

void	rotb(int *b, int *blen)
{
	int	it;
	int	n;

	it = checkbig(b, blen);
	n = b[checkbig(b, blen)];
	if (it <= *blen / 2)
	{
		while (b[0] != n)
			rtp(0, b, 0, blen);
	}
	else
	{
		while (b[0] != n)
			rrtp(0, b, 0, blen);
	}
}

void	finalpush(int *a, int *b, int *alen, int *blen)
{
	int	it;
	int	slen;

	it = 0;
	slen = *blen;
	while (it < slen)
	{
		pa(b, a, blen, alen);
		it++;
	}
}
