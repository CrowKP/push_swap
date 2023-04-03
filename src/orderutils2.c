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
		if (a[0] < b[it] && a[0] > b[it - 1])
			return (it);
		it++;
	}
	exit (0);
}

void	pushrandom(int *a, int *b, int *alen, int *blen)
{
	int	it;
	int	n;

	n = a[checkposition(b, a, alen)];
	it = checkposition(b, a, alen);
	if (it <= *alen / 2)
	{
		while (a[0] != n)
			rtp(a, 0, alen, 0);
	}
	else
	{
		while (a[0] != n)
			rrtp(a, 0, alen, 0);
	}
	pa(b, a, blen, alen);
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
		rotb(b, blen);
		pa(b, a, blen, alen);
		it++;
	}
}

void	rota(int *a, int *alen, int top, int bot)
{
	int	hold;

	if (top <= *alen - bot)
	{
		hold = a[top];
		while (a[0] != hold)
			rtp(a, 0, alen, 0);
	}
	else if (top > *alen - bot)
	{
		hold = a[bot];
		while (a[0] != hold)
			rrtp(a, 0, alen, 0);
	}
}
