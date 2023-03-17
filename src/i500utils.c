/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i500utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigarcia <aigarcia@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:14:34 by aigarcia          #+#    #+#             */
/*   Updated: 2023/03/16 20:14:35 by aigarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

void	order500(int *a, int *b, int *alen, int *blen)
{
	int	it;
	int	top;
	int	bottom;
	int	jt;

	it = 0;
	jt = *alen;
	while (*alen > 5)
	{
		if (jt == *alen + 45)
		{
			it += 45;
			jt = *alen;
		}
		else if (a[0] >= it && a[0] <= it + 44)
			pb(a, b, alen, blen);
		else if (a[0] > it + 44)
		{
			top = checktop500(a, alen, it);
			bottom = checkbot500(a, alen, it);
			while (a[0] > it + 44)
				rotstack(a, alen, top, bottom);
		}
	}
	finalpush500(a, b, alen, blen);
}

int	checktop500(int *a, int *alen, int jt)
{
	int	it;
	int	top;

	it = 0;
	top = 0;
	while (it <= *alen / 2)
	{
		if (a[it] >= jt && a[it] <= jt + 44)
		{
			top = it;
			return (top);
		}
		it++;
	}
	return (*alen / 2);
}

int	checkbot500(int *a, int *alen, int jt)
{
	int	it;
	int	bot;

	it = *alen - 1;
	bot = 0;
	while (it > *alen / 2)
	{
		if (a[it] >= jt && a[it] <= jt + 44)
		{
			bot = it;
			return(bot);
		}
		it--;
	}
	return (bot);
}

void	rotb500(int *b, int *blen)
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

void	finalpush500(int *a, int *b, int *alen, int *blen)
{
	int	it;
	int	slen;

	it = 0;
	slen = *blen;
	while (*alen > 0)
		pb(a, b, alen, blen);
	while (it < slen)
	{
		rotb500(b, blen);
		pa(b, a, blen, alen);
		it++;
	}
}
