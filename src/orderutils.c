/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:15:39 by aigarcia          #+#    #+#             */
/*   Updated: 2023/03/16 20:15:40 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

int	checktop(int *a, int *alen, int jt)
{
	int	it;
	int	top;
	int	mod;

	it = 0;
	top = 0;
	if (*alen > 100 || jt > 100)
		mod = 44;
	else
		mod = 19;
	while (it <= *alen / 2)
	{
		if (a[it] >= jt && a[it] <= jt + mod)
		{
			top = it;
			return (top);
		}
		it++;
	}
	return (*alen / 2);
}

int	checkbot(int *a, int *alen, int jt)
{
	int	it;
	int	bot;
	int	mod;

	it = *alen - 1;
	bot = 0;
	if (*alen > 100 || jt > 100)
		mod = 44;
	else
		mod = 19;
	while (it > *alen / 2)
	{
		if (a[it] >= jt && a[it] <= jt + mod)
		{
			bot = it;
			return (bot);
		}
		it--;
	}
	return (bot);
}

void	rotstack(int *a, int *b, int *alen, int *blen)
{
	int	top;
	int	bot;
	int	it;
	int	hold;

	it = calclen(alen, blen);
	top = checktop(a, alen, it);
	bot = checkbot(a, alen, it);
	if (top <= *alen - bot)
	{
		hold = a[top];
		rotbtran(a, b, alen, blen);
		if (a[0] != hold)
			rota(a, alen, top, bot);
		/*if (*blen == 1)
			pb(a, b, alen, blen);*/
	}
	if (top > *alen - bot)
	{
		hold = a[bot];
		rotbbran(a, b, alen, blen);
		if (a[0] != hold)
			rota(a, alen, top, bot);
		/*if (*blen == 1)
			pb(a, b, alen, blen);*/
	}
}

void	pushstack(int *a, int *b, int *alen, int *blen)
{
	if (*blen == 0 || (*blen == 1 && a[0] > b[0]))
		pb(a, b, alen, blen);
	else if (*blen == 1 && a[0] < b[0])
	{
		pb(a, b, alen, blen);
		sp(0, b, 0, blen);
	}
	else if (a[0] > b[0] && a[0] < b[*blen - 1])
		pb(a, b, alen, blen);
	else if (a[0] > b[checkbig(b, blen)] || a[0] < b[checksmall(b, blen)])
		pushexb(a, b, alen, blen);
	else
		pushrandom(a, b, alen, blen);
}

void	pushexb(int *a, int *b, int *alen, int *blen)
{
	int	it;
	int	n;

	n = b[checkbig(b, blen)];
	it = checkbig(b, blen);
	while (b[0] != n)
	{
		if (it <= *blen / 2)
			rtp(0, b, 0, blen);
		else
			rrtp(0, b, 0, blen);
	}
	pb(a, b, alen, blen);
}
